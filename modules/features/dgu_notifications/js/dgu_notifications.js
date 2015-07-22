(function ($) {
    $(document).ready(function () {

        $('body.page-user-subscriptions-auto-subscribe #edit-content-types .form-type-checkbox').each(function (index) {
            if ($(this).attr('class').indexOf('subscribe') >= 0) {

                // Find parent class from child name.
                var parts = $(this).children('input').attr('value').split('_');
                var parent = '';
                if (parts.length > 2) {
                    var parent = parts[0] + '-' + parts[1]
                }
                else {
                    var parent = parts[0]
                }

                // Hide child if parent not checked.
                if (!$('#edit-content-types-' + parent).is(':checked')) {
                    $(this).hide();
                }
            }

            else {
                $(this).addClass('content-type').children('input').change(function() {
                    var content_type = $(this).attr('value').replace('_', '-');
                    $('#edit-content-types .form-type-checkbox').each(function (index) {
                        var classes = $(this).attr('class');
                        if (classes.indexOf('subscribe') >= 0 && classes.indexOf(content_type) >= 0) {
                            $(this).toggle().children('input').prop('checked', false);
                        }
                    });
                });
            };
        });
    });
})(jQuery);