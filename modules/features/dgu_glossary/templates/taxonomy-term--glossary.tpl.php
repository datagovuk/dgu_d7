<?php

/**
 * @file
 * Default theme implementation to display a term.
 *
 * Available variables:
 * - $name: the (sanitized) name of the term.
 * - $content: An array of items for the content of the term (fields and
 *   description). Use render($content) to print them all, or print a subset
 *   such as render($content['field_example']). Use
 *   hide($content['field_example']) to temporarily suppress the printing of a
 *   given element.
 * - $term_url: Direct URL of the current term.
 * - $term_name: Name of the current term.
 * - $classes: String of classes that can be used to style contextually through
 *   CSS. It can be manipulated through the variable $classes_array from
 *   preprocess functions. The default values can be one or more of the following:
 *   - taxonomy-term: The current template type, i.e., "theming hook".
 *   - vocabulary-[vocabulary-name]: The vocabulary to which the term belongs to.
 *     For example, if the term is a "Tag" it would result in "vocabulary-tag".
 *
 * Other variables:
 * - $term: Full term object. Contains data that may not be safe.
 * - $view_mode: View mode, e.g. 'full', 'teaser'...
 * - $page: Flag for the full page state.
 * - $classes_array: Array of html class attribute values. It is flattened
 *   into a string within the variable $classes.
 * - $zebra: Outputs either "even" or "odd". Useful for zebra striping in
 *   teaser listings.
 * - $id: Position of the term. Increments each time it's output.
 * - $is_front: Flags true when presented in the front page.
 * - $logged_in: Flags true when the current user is a logged-in member.
 * - $is_admin: Flags true when the current user is an administrator.
 *
 * @see template_preprocess()
 * @see template_preprocess_taxonomy_term()
 * @see template_process()
 *
 * @ingroup themeable
 */
?>
  <div class="glossary-content">


    <?php print $lexicon_alphabar; ?>
    <div id="taxonomy-term-<?php print $term->tid; ?>" class="<?php print $classes; ?>">

      <?php if (!$page): ?>
        <div class="glossary-header">
          <h2><?php print $term_name; ?></h2>
          <div class="content">
            <?php
            // Hide comments, tags, and links now so that we can render them later.
            hide($content['links']);
            hide($content['field_comment']);

            hide($content['field_endorse']);
            hide($content['glossary_item_actions']);
            print render($content);
            ?>
          </div>
          <div class="glossary-appsi-quality"><?php print $quality_score; ?></div>

          <?php
          // Hide comments, tags, and links now so that we can render them later.
          print render($content['field_endorse']);
          print render($content['glossary_item_actions']);
          ?>

        </div>
      <?php endif; ?>



      <div class="source">
        <?php print render($source); ?>
      </div>

      <?php if ($suggested_definitions): error_log(print_r($suggested_definitions, TRUE)); ?>
        <div class="suggested-definitions">
          <h2>Suggested definitions</h2>
          <?php print render($suggested_definitions); ?>
        </div>
      <?php endif; ?>

    </div>

  </div>

<?php if (!empty($content['field_comment'])): ?>
  <footer>
    <?php print render($content['field_comment']); ?>
  </footer>
<?php endif; ?>