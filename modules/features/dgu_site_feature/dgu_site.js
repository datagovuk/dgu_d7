(function($){

  Drupal.behaviors.dgu_site = {
    attach: function (context) {
      $('button.form-submit').click(function(){
        $(this).parents('form').submit();
        $('button.form-submit').attr("disabled", true);
      });

      $('ul.tabs--primary li.quick-edit a').click(function(e){
          e.preventDefault();
          $('ul.contextual-links li.quick-edit a').trigger( 'click');
      });

    }
  };

})(jQuery);
