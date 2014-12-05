(function($){
    $(window).resize(function() {
        redrawVisualisations();
//        if (Drupal.settings.d3 && Drupal.settings.d3.inventory) {
//            // Iterate over each of the visualizations set in inventory.
//            for (id in Drupal.settings.d3.inventory) {
//                Drupal.d3.draw(id, Drupal.settings.d3.inventory[id]);
//            }
//        }
    });


    Drupal.behaviors.dgu_data_request_vis = {
        attach: function (context) {
            $('.vis-see-more').click(function (e) {
                e.preventDefault();
                $('.vis-hidden').toggle();
                $(this).html($(this).text() == 'See more' ? 'See less' : 'See more');
                redrawVisualisations();
            });
        }
    }

    function redrawVisualisations() {
        if (Drupal.settings.d3 && Drupal.settings.d3.inventory) {
            // Iterate over each of the visualizations set in inventory.
            for (id in Drupal.settings.d3.inventory) {
                Drupal.d3.draw(id, Drupal.settings.d3.inventory[id]);
            }
        }
    }

})(jQuery);