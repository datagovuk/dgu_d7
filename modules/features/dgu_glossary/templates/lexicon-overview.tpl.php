<?php
/**
 * Created by JetBrains PhpStorm.
 * User: noels
 * Date: 15/04/2013
 * Time: 21:33
 * To change this template use File | Settings | File Templates.
 *
 * @file
 * Theme implementation for displaying the Lexicon overview in the DGU glossary.
 *
 * This template renders a the Lexicon overview.
 *
 * Available variables:
 * - $lexicon_overview: Lexicon overview object.
 *    - $lexicon_overview->voc_name: vocabulary name.
 *    - $lexicon_overview->description: vocabulary description.
 *    - $lexicon_overview->introduction: introduction text for Lexicon.
 *    - $lexicon_overview->go_to_top_link: Optional "go-to-top" link information
 *      in named array containing go_to_top_link["name"],
 *      go_to_top_link["path"], go_to_top_link["fragment"], and
 *      go_to_top_link["attributes"].
 * - $lexicon_alphabar: Lexicon alphabar as rendered by
 *   lexicon-alphabar.tpl.php.
 * - $lexicon_overview_sections: Lexicon overview sections as rendered by
 *   lexicon-overview-section.tpl.php.
 *
 */
?>
<div id="<?php print $lexicon_overview->voc_name ?>" xmlns="http://www.w3.org/1999/html">
    <?php print $lexicon_alphabar ?>
    <?php if (isset($lexicon_overview->introduction)) : ?>
        <div class="lexicon-introduction">
            <?php print $lexicon_overview->introduction; ?>
        </div>
    <?php endif;?>
    <div class="glossary_filter">
        <input type="radio" name="filter_glossary" value="show_approved">Only approved terms</input>
        <input type="radio" name="filter_glossary" value="show_new">Only new terms</input>
        <input checked="true" type="radio" name="filter_glossary" value="show_both">Both new and approved terms</input>
    </div>
    <a href="glossary/suggest_new" class="button">Suggest a new Term</a>
    <div class="lexicon-list">
        <?php foreach ($lexicon_overview_sections as $section) : ?>
            <?php print $section; ?>
            <?php if (isset($lexicon_overview->go_to_top_link)) : ?>
                <p>
                    <?php print l($lexicon_overview->go_to_top_link["name"], '#', array(
                        'fragment' => $lexicon_overview->go_to_top_link["fragment"],
                        'attributes' => $lexicon_overview->go_to_top_link["attributes"],
                        'external' => TRUE,
                    )); ?>
                </p>
            <?php endif; ?>
        <?php endforeach; ?>
    </div>
</div>
