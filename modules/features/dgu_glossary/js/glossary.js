
(function($) {
    $.hideNewTerms = function(){
        $('.term-new').hide();
    }
    $.showNewTerms = function(){
        $('.term-new').show();
    }
    $.showExistingTerms = function(){
        $('.term-existing').show();
    }
    $.hideExistingTerms = function(){
        $('.term-existing').hide();
    }
    $.showAllTerms = function(){
        $('.term-existing').show();
        $('.term-new').show();
    }


    $.changeTerms = function(){
        $show = $(this).val();
        switch ($show) {
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

        }

    }

    $(document).ready(function() {
        // Enable the localscroll functionality
        console.log($('.filter_glossary'));
        $('input[name=filter_glossary]:radio').change($.changeTerms);
        console.log('on change hooked up');
    });
})(jQuery);
