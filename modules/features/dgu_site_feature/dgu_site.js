(function($){

  Drupal.behaviors.dgu_site = {
    attach: function (context) {
      $('button.form-submit').click(function(){
        $(this).parents('form').submit();
        $('button.form-submit').attr("disabled", true);
      });
    }
  };

})(jQuery);
