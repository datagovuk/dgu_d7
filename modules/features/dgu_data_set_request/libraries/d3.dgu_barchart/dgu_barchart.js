/**
 * @file
 * Adds a function to generate a column chart to the `Drupal` object.
 */

/** 
 * Notes on data formatting:
 * legend: array of text values. Length is number of data types.
 * rows: array of arrays. One array for each point of data
 * arrays have format array(label, data1, data2, data3, ...)
 */

(function($) {
  Drupal.d3.dgu_barchart = function (select, settings) {
      var rows = settings.rows,
      // Use first value in each row as the label.
      yLabels = rows.map(function(d) { return d.shift(); });

      // Legend
      key = ["Public", "Confidential"];

      // The highest (numeric) value from flat array.
      max = d3.max(d3.merge(settings.rows).map(function(d) { return + d; })),
      // Padding is top, right, bottom, left as in css padding.

      padding = {top: 10, right: 10, bottom: 20, left: 10};
      w = parseInt(d3.select('#' + settings.id).style('width'));
      h = 200;
      labelsWidth = 210;
      legendWidth = 140;
      textHeight = 20;
      if (w < 700) {
        legendWidth = 0;
        h = h + 40 + textHeight;
        padding.bottom = 80;
      }
      chart = {w: w - labelsWidth - legendWidth - padding.left - padding.right, h: h - padding.top - padding.bottom};
      barWidth = .08 * chart.h;
      barGroupWidth = barWidth * 2;
      barSpacing = (.2 * chart.h) / rows.length;
      x = d3.scale.linear().domain([0,max]).range([20,chart.w]);
      y = d3.scale.linear().domain([0,rows.length]).range([0, chart.h]);
      z = d3.scale.ordinal().range(["bar1", "bar2"]);

    var svg = d3.select('#' + settings.id).append("svg")
      .attr("width", w - padding.left - padding.right)
      .attr("height", h)
      .append("g")
      .attr("transform", "translate(" + labelsWidth + "," + padding.right + ")");

    var graph = svg.append("g")
      .attr("class", "chart");

    /* Y AXIS  */
    var yTicks = graph.selectAll("g.ticks")
      .data(rows)
      .enter().append("g")
      .attr("class","ticks")
      .attr('width', 50)
      .attr('transform', function(d,i) { return 'translate(-4,' + (y(i) + (barGroupWidth / 2)) + ')'});

    // This adds the labels to the ytick groups.
    yTicks.append('text')
      .attr("dy", ".25em")
      .attr('dx', 5)
      .attr("text-anchor", "end")
      .text(function(d, i) { return yLabels[i]; })
      .ellipsis(labelsWidth);

    /* LINES */
    var rule = graph.selectAll("g.rule")
      .data(x.ticks(4))
      .enter().append("g")
      .attr("class", "rule")
      .attr("transform", function(d) { return "translate(" + x(d) + "," + chart.h + ")"; });

    rule.append("line")
      .attr("y2", -chart.h)
      .style("stroke", function(d) { return d ? "#ccc" : "#000"; })
      .style("stroke-opacity", function(d) { return d ? .7 : null; });

    /* X AXIS */
    rule.append("text")
      .attr("y", textHeight)
      .attr("text-anchor", "end")
      .text(d3.format(",d"))
      .attr("x", function(d) {return this.getComputedTextLength() / 2;});

    var bar = graph.selectAll('g.bars')
      .data(rows)
      .enter().append('g')
      .attr('class', 'bargroup')
      .attr('transform', function(d,i) { return "translate(20, " + i * (barGroupWidth + barSpacing) + ")"; });

    bar.selectAll('rect')
      .data(function(d) { return d; })
      .enter().append('rect')
      //.attr("width", 0)
      .attr("width", function(d) { return x(d); })
      .attr("height", barWidth)
      .attr('x', function (d,i) { return 0; })
      .attr('y', function (d,i) { return i * barWidth; })
      //.attr('fill', function(d,i) { return d3.rgb(z(i)); })
      .attr("class", function(d,i) {return "color_" + z(i); })
      .on('mouseover', function(d, i) { showToolTip(d, i, this); })
      .on('mouseout', function(d, i) { hideToolTip(d, i, this); });

    /* LEGEND */
    var legend = svg.append("g")
      .attr("class", "legend")

    if(legendWidth > 0) {
        legend.attr("transform", "translate(" + (chart.w + 30) + "," + 0 + ")");
    }
    else {
        legend.attr("transform", "translate(" + 20 + "," + 200 + ")");
    }


    var keys = legend.selectAll("g")
      .data(key)
      .enter().append("g")
      .attr("transform", function(d,i) { return "translate(0," + d3.tileText(d,10) + ")"});

    keys.append("rect")
      //.attr("fill", function(d,i) { return d3.rgb(z(i)); })
      .attr("class", function(d,i) {return "color_" + z(i); })
      .attr("width", 16)
      .attr("height", 16)
      .attr("y", 0)
      .attr("x", 0)
      .on('mouseover', highlightBars)
      .on('mouseout', unhighlightBars);

    var labelWrapper = keys.append("g");

    labelWrapper.selectAll("text")
      .data(function(d,i) { return d3.splitString(key[i], 15); })
      .enter().append("text")
      .text(function(d,i) { return d})
      .attr("x", 20)
      .attr("y", function(d,i) {  return i * 20})
      .attr("dy", "1em");

    function showToolTip(d, i, obj) {
      // change color and style of the bar
      var bar = d3.select(obj);
      bar.attr('stroke', '#ccc')
        .attr('stroke-width', '1')
        .attr('opacity', '0.75');

      var group = d3.select(obj.parentNode);

      var tooltip = graph.append('g')
        .attr('class', 'tooltip')
        // move to the x position of the parent group
        .attr('transform', function(data) { return group.attr('transform'); })
          .append('g')
        // now move to the actual x and y of the bar within that group
        .attr('transform', function(data) { return 'translate(' + x(d) + ',' + (Number(bar.attr('y')) + barWidth / 2) + ')'; });

      d3.tooltip(tooltip, d);
    }

    function hideToolTip(d, i, obj) {
      var group = d3.select(obj.parentNode);
      var bar = d3.select(obj);
      bar.attr('stroke-width', '0')
        .attr('opacity', 1);

      graph.select('g.tooltip').remove();

    }

    function highlightBars(d, i) {
      var like_color = d3.selectAll('.color_' + z(i));
      like_color.attr('stroke', '#ccc').attr('opacity', '0.75');
    }

    function unhighlightBars(d, i) {
      var like_color = d3.selectAll('.color_' + z(i));
      like_color.attr('opacity', 1);
    }

  }

})(jQuery);
