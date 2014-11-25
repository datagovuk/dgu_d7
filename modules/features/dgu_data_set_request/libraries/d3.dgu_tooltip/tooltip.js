/**
 * @file
 * D3.js tooltip extensions
 */
(function($) {
  d3 = d3 || {};

  /**
   * Creates a tooltip-like popup in svg
   *
   * @param tipjar
   *   Container to put the tooltip
   * @param x
   *   X axis of container group
   * @param y
   *   Y axis of container group
   * @param txt
   *   Text to display inside the popup
   *   @todo make more customizable
   * @param h
   *   height of container group
   * @param w
   *   width of container group
   */
  d3.tooltip = function(tipjar, txt, h, w) {
    var tooltip = {
      w: 115,
      h: 20,
      // The width of the triangular tip as it is on the base
      tipW: 10,
      // Tip length, vertically
      tipL: 5,
      // Tip offset point, from the very tip to the middle of the square
      tipO: 5
    };

    var svg = tipjar.node();
    while (svg.tagName != "svg" && svg.parentNode) {
      svg = svg.parentNode;
    }
    w = parseInt(svg.attributes.width.textContent, 10);
    h = parseInt(svg.attributes.height.textContent, 10);

    //Precomputing the x and y attributes is difficult. Need to find a new way.
    //console.log(tipjar.node().getBBox());

    // Create a container for the paths specifically
    var img = tipjar.append("g");
    // Creates 3 identical paths with different opacities
    // to create a shadow effect

    img.append('path')
    .attr("d", function(d) { return "M0,0"
    + 'l' + tooltip.tipO+',-' + tooltip.tipL
    + 'l' + ((tooltip.w / 2) - tooltip.tipW) + ',0'
    + 'l0,-' + tooltip.h + ''
    + 'l-' + tooltip.w + ',0'
    + 'l0, ' + tooltip.h
    + 'l' + (tooltip.w / 2) +',0'
    + "L0,0"; })
    .attr("fill", '#fff')
    .attr('transform', function(d) { return 'translate(' + x + ',' + x + ')';  })
    .attr('stroke', '#ccc')
    .attr('fill-opacity', 1)
    .attr('stroke-width', 1);

    var offset = (tooltip.w / 2) - (tooltip.tipO - tooltip.tipW);

    var textbox = tipjar.append('g')
    .attr('class', 'text')
    .attr('transform', function(d) { return 'translate(-' + offset + ',-' + tooltip.h + ')'})

    textbox.append('text')
    .text(txt)
    .attr('text-anchor', 'end')
    .attr('dx', 25)
    .attr('dy', 9)
    .attr('font-family', 'Arial,sans-serif')
    .attr('font-size', '12')
    .attr('font-weight', 'normal');

    textbox.append('text')
    .text('Data requests')
    .attr('text-anchor', 'start')
    .attr('dx', 30)
    .attr('dy', 9)
    .attr('font-family', 'Arial,sans-serif')
    .attr('font-size', '12')
    .attr('font-weight', 'normal');
  }
})(jQuery);
