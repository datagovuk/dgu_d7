<li>
    <?php if (user_access('moderate glossary')): ?>
      <?php print $status ?>
    <?php endif; ?>
    <?php print render($suggested_definition); ?>
    <?php print render($comments); ?>
</li>
