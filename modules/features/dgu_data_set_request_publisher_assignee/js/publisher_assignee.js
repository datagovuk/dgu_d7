(function($) {

    Drupal.behaviors.publisherChange = {
        attach: function (context, settings) {
            if ($('#edit-field-publisher-ref input:checked').length > 0) {
                var PublisherY = $('#edit-field-publisher-ref input:checked').offset().top;
                var PublisherWrapperY = $('#edit-field-publisher-ref').offset().top;
                var offset = PublisherY - PublisherWrapperY - 3;
                $('#edit-field-publisher-assignee').css({ 'padding-top': offset });

                $('#edit-field-publisher-assignee label').append('<div class="publisher-assignee-connector"></div>');

                $('#edit-field-publisher-ref li').css({ 'background': 'none'});
                $('#edit-field-publisher-ref input:checked').closest('li').css({ 'background': '#f0fcff'});

                if (typeof $('#edit-field-publisher-assignee input:checked').val() == 'undefined') {
                    $('#edit-field-publisher-assignee input.form-radio:first').attr('checked','checked');
                }
            }
        }
    }

    Drupal.behaviors.dataRequestSubmit = {
        attach: function (context, settings) {
            $('input.form-submit').unbind("click").click(function(e) {
                var publisher = $('#edit-field-publisher-ref input.form-radio:checked').val();
                var publisherAssignee = $('#edit-field-publisher-assignee input.form-radio:checked').val();
                if($.isNumeric(publisher) && !$.isNumeric(publisherAssignee)) {
                    if (confirm("Publisher is set but Publisher assignee isn't.\nIn order to notify data holder about this request you must select user in Publisher assignee field.\n\nAre you sure that you want to save this request without notifying data holder?") != true) {
                        e.preventDefault();
                    }

                }
            });
        }
    }

})(jQuery);