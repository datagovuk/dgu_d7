(function($){

  Drupal.behaviors.dgu_site = {
    attach: function (context) {
      $('button.form-submit').click(function(){
        $(this).parents('form').submit();
        $(this).attr("disabled", true);
      });
    }
  };

})(jQuery);
