(function($){

  Drupal.behaviors.dgu_site = {
    attach: function (context) {
      $('#edit-actions button.form-submit').click(function(){
        $('#edit-actions button.form-submit').attr("disabled", true);
      });
    }
  };

})(jQuery);
