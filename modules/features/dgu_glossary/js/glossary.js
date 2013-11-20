(function($) {

    $.hideNewTerms = function(){
        $('.term-new').hide();
        $('.term-existing').show();
    }
    $.showNewTerms = function(){
        $('.term-new').show();
        $('.term-existing').hide();
    }
    $.showExistingTerms = function(){
        $('.term-existing').show();
        $('.term-new').hide();
    }
    $.hideExistingTerms = function(){
        $('.term-existing').hide();
        $('.term-new').show();

    }
    $.showAllTerms = function(){
        $('.term-existing').show();
        $('.term-new').show();
    }

    $.changeTerms = function(e){
        show = $(e.srcElement).find('input').attr('id');
        switch (show) {
            case 'show_new':
                $.showNewTerms();
                $.hideExistingTerms();
                break;
            case 'show_both':
		        $.showAllTerms();
                break;
            case 'show_approved':
                $.showExistingTerms();
                $.hideNewTerms();
                break;
        }

    }

    $(document).ready(function() {
        $("#glossary_filter").on('click', $.changeTerms);
    });
})(jQuery);

