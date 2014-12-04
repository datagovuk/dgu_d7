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
      w: 75,
      h: 20,
      // The width of the triangular tip as it is on the base
      tipW: 10,
      // Tip length, vertically
      tipL: 5,
      // Tip offset point, from the very tip to the middle of the square
      tipO: 5,
      // 'Requests' text offset
      offset: 15
    };
    if (parseInt(txt) > 9 ) {
        tooltip.w += 7;
        tooltip.offset += 7;
    }
    if (parseInt(txt) > 99 ) {
        tooltip.w += 7;
        tooltip.offset += 7;
    }

    var svg = tipjar.node();
    while (svg.tagName != "svg" && svg.parentNode) {
      svg = svg.parentNode;
    }

    // Create a container for the paths specifically
    var img = tipjar.append("g");

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
    .attr('stroke', '#ccc')
    .attr('fill-opacity', 1)
    .attr('stroke-width', 1);

    var offset = (tooltip.w / 2) - (tooltip.tipO - tooltip.tipW);

    var textbox = tipjar.append('g')
    .attr('class', 'text')
    .attr('transform', function(d) { return 'translate(-' + offset + ',-' + tooltip.h + ')'})

    textbox.append('text')
    .text(txt)
    .attr('text-anchor', 'start')
    .attr('dx', 5)
    .attr('dy', 9)
    .attr('font-family', 'Arial,sans-serif')
    .attr('font-size', '12')
    .attr('font-weight', 'normal');

    textbox.append('text')
    .text('Requests')
    .attr('text-anchor', 'start')
    .attr('dx', tooltip.offset)
    .attr('dy', 9)
    .attr('font-family', 'Arial,sans-serif')
    .attr('font-size', '12')
    .attr('font-weight', 'normal');
  }
})(jQuery);
