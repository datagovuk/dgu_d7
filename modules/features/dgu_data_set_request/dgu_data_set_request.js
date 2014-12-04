(function($){
    $(window).resize(function() {
        if (Drupal.settings.d3 && Drupal.settings.d3.inventory) {
            // Iterate over each of the visualizations set in inventory.
            for (id in Drupal.settings.d3.inventory) {
                Drupal.d3.draw(id, Drupal.settings.d3.inventory[id]);
            }
        }
    });
})(jQuery);