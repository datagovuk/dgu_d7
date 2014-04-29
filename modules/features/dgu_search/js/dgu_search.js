(function ($) {
    $(document).ready(function () {
        $("a.show-facets, a.hide-facets").click(function (e) {
            e.preventDefault();
            if ($(e.delegateTarget).hasClass("show-facets")) {
                $(".panel-left-bottom").addClass("in");
            } else {
                $(".panel-left-bottom").removeClass("in");
            }
            return false;
        });
    });
})(jQuery);
