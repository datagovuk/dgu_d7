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

  Drupal.d3.dgu_piechart = function (select, settings) {

    var instance_id = Math.floor((Math.random() * 1000000) + 1);

    if (typeof(settings) != 'undefined') {
      Drupal.d3.dgu_piechart.settings = settings;
    }

    d3.y = 0;

    var legendWidth = 170;
    var w = parseInt($('#' + Drupal.d3.dgu_piechart.settings.id).parent().width()) * Drupal.d3.dgu_piechart.settings.width;
    var legendOffsetY = 10;
    var legendOffsetX = w - legendWidth;
    var h = w - legendWidth;
    var labelBreak = 22; // break line after 22 characters

    if (w < 200) {
        w = parseInt($('#' + Drupal.d3.dgu_piechart.settings.id).parent().width()) - 20;
        legendOffsetX = 10;
        legendOffsetY = w;
        legendWidth = 0;
        h = w;
        labelBreak = 35;

    }
    else if (w < 350) {
        legendOffsetX = 10;
        legendOffsetY = w;
        legendWidth = 0;
        h = w;
        labelBreak = 27;
    }

    var wedges = Drupal.d3.dgu_piechart.settings.rows;
    var padding = {top: 0, right: 10, bottom: 20, left: 10};
    var radius = (w - padding.left - padding.right - legendWidth) / 2;
    var key = wedges.map(function(d) { return String(d[0]); });
    var color = d3.scale.ordinal().range(['pie1', 'pie2', 'pie3', 'pie4', 'pie5']);

    // Remove previously rendered h3 and svg elements if exist.
    d3.select('#' + Drupal.d3.dgu_piechart.settings.id + ' svg').remove();
    d3.select('#' + Drupal.d3.dgu_piechart.settings.id + ' h3').remove();

    var heading = d3.select('#' + Drupal.d3.dgu_piechart.settings.id).append('h3').text(Drupal.d3.dgu_piechart.settings.title);
    //var heading = d3.select('#' + Drupal.d3.dgu_piechart.settings.id).append('h3').text(instance_id);


    var svg = d3.select('#' + Drupal.d3.dgu_piechart.settings.id).append('svg')
      .attr('width', w)
      .append('g')
      .attr('transform', 'translate(' + padding.left + ',' + padding.top + ')');



    /* LEGEND */
    var legend = svg.append('g')
      .attr('class', 'legend')
      .attr('transform', 'translate(' + legendOffsetX + ',' + legendOffsetY + ')');

    var keys = legend.selectAll('g')
      .data(key)
      .enter().append('g')
      .attr('transform', function(d,i) { return 'translate(0,' + d3.tileText(d, labelBreak) + ')'});

    keys.append('rect')
      .attr('class', function(d,i) {return 'color_' + color(i) + ' row_' + i + '_' + instance_id; })
      .attr('width', 16)
      .attr('height', 16)
      .attr('y', 0)
      .attr('x', 0)
      .on('mouseover', function(d, i) { interact('over', i, instance_id); })
      .on('mouseout', function(d, i) { interact('out', i, instance_id); });

    var legendHeight = legend.node().getBBox().height;
    if (legendOffsetX == 10) {
      d3.select('#' + Drupal.d3.dgu_piechart.settings.id + ' svg').attr('height', h + legendHeight + padding.bottom);
    }
    else {
      var height = legendHeight > h ? legendHeight : h;
      d3.select('#' + Drupal.d3.dgu_piechart.settings.id + ' svg').attr('height', height);
    }

    var labelWrapper = keys.append('g');

    labelWrapper.selectAll('text')
      .data(function(d,i) { return d3.splitString(key[i], labelBreak); })
      .enter().append('text')
      .text(function(d,i) { return d})
      .attr('x', 20)
      .attr('y', function(d,i) { return i * 17})
      .attr('dy', '1em');


      var graph = svg.append('g')
          .attr('class', 'chart')
          .attr('transform', 'translate(' + radius + ',' + radius + ')');

      var arc = d3.svg.arc()
          .outerRadius(radius - 10)
          .innerRadius(0);

      // Background arc that will act as a rollover.
      var arc_effect = d3.svg.arc()
          .outerRadius(radius)
          .innerRadius(radius - 10);

      // Main arc that will be visible at all time.
      var circle = d3.svg.arc()
          .outerRadius(radius - 10)
          .innerRadius(radius - 10);

      var pie = d3.layout.pie()
          .sort(null)
          .value(function(d) { return Number(d[1]); });

      /* MAIN CHART */
      var g = graph.selectAll('.arc')
          .data(pie(wedges))
          .enter().append('g')
          .attr('class', function(d, i) { return 'arc arc-' + i; });

      // outer wedges
      g.append('path')
          .attr('d', arc_effect)
          .attr('fill', '#fff')
          .attr('fill-opacity', 0)
          .attr('class', function(d, i) { return 'arc-' + i + '-over' + ' row_' + i + '_' + instance_id + '-over'; });

      //main wedges
      g.append('path')
          .attr('d', arc)
          .style('stroke', '#fff')
          .style('stroke-width', 1)
          .on('mouseover', function(d, i) { interact('over', i, instance_id); })
          .on('mouseout', function(d, i) { interact('out', i, instance_id); })
          .attr('class', function(d, i) { return 'color_' + color(i) + ' arc-' + i + ' row_' + i + '_' + instance_id; });


    /**
     * Wrapper function for all rollover functions.
     *
     * @param string text
     *   Current state, 'over', or 'out'.
     * @param int i
     *   Current index of the current data row.
     * @return none
     */
    function interact(state, i, instance_id) {
      if (state == 'over') {
        showToolTip(i);
        highlightSlice(i, instance_id);
      }
      else {
        hideToolTip(i);
        unhighlightSlice(i);
      }
      return true;
    }

    /**
     * Displays a tooltip on the centroid of a pie slice.
     *
     * @param int i
     *   Index of the current data row.
     * @return none
     */
    function showToolTip(i) {
      var data = pie(wedges);
      var tooltip = graph.append('g')
        .attr('class', 'tooltip')
        // move to the x position of the parent group
          .append('g')
        // now move to the actual x and y of the bar within that group
        .attr('transform', function(d) { return 'translate(' + circle.centroid(data[i]) + ')'; });

      d3.tooltip(tooltip, Number(wedges[i][1]));
    }

    /**
     * Hides tooltip for a given class. Each slice has a unique class in
     * this chart.
     *
     * @param int i
     *   Index of the current data row.
     * @return none
     */
    function hideToolTip(i) {
      var bar = d3.selectAll('.color_' + color(i));
      bar.attr('stroke-width', '0')
        .attr('opacity', 1);

      graph.select('g.tooltip').remove();

    }

    /**
     * Changes appearance of group to have an outer border.
     *
     * @param int i
     *   Index of the current data row.
     * @return none
     */
    function highlightSlice(i, instance_id) {
      d3.selectAll('.row_' + i + '_' + instance_id + '-over')
        .attr('fill', '#ccc')
        .attr('fill-opacity', 0.3);
    }

    /**
     * Revert slice back to init state.
     *
     * @param int i
     *   Index of the current data row.
     * @return none
     */
    function unhighlightSlice(i) {
      d3.selectAll('.arc-' + i + '-over')
        .attr('fill', 'white')
        .attr('fill-opacity', 0);
    }

    function percent(i) {
      var sum = d3.sum(wedges.map(function(d,i) { return Number(d[1]); }));
      var val = Number(wedges[i][1]);

      return ((val / sum) ? Math.round((val / sum) * 100) : 0) + '%';
    }
  }

})(jQuery);
