<?php include('header.inc'); ?>

  <div id='left' class='clear-block'>
    <?php print $left ?>
  </div>
  <div id='content'>
    <?php if ($title || $tabs || $tabs2): ?>
    <div id='branding'><div class='clear-block'>
      <?php if ($tabs): ?><div id='tabs' class="clear-block"><div class='page-tabs primary'><?php print $tabs ?></div></div><?php endif; ?>
      <?php if ($tabs2): ?><div id='tabs2' class='clear-block'><div class='page-tabs secondary'><?php print $tabs2 ?></div></div><?php endif; ?>
      <div class="clear-block"><div class="inner"><?php if ($title) print "<h2>$title</h2>"; ?></div></div>
    </div></div>
    <?php endif; ?>
  
    <?php if (!empty($content)): ?>
      <div class='content-wrapper clear-block'><?php print $content ?></div>
    <?php endif; ?>
    <?php print $content_region ?>
  </div>
  <div id='right' class='clear-block'>
    <?php print $right ?>
  </div>

<?php include('footer.inc'); ?>
