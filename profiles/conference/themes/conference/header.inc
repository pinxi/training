<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Strict//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-strict.dtd">
<html xmlns="http://www.w3.org/1999/xhtml" xml:lang="<?php print $language->language ?>" lang="<?php print $language->language ?>" dir="<?php print $language->dir ?>" xmlns:og="http://opengraphprotocol.org/schema/" xmlns:fb="http://www.facebook.com/2008/fbml">
  <head>
    <?php print $head ?>
    <?php print $styles ?>
    <?php print $scripts ?>
    <title><?php print $head_title ?></title>
  </head>
  <body <?php print drupal_attributes($attr) ?>>

  <?php if ($help): ?>
  <div id='page-help'><div class='limiter clear-block'>
    <?php if ($help_toggler) print $help_toggler ?>
    <?php if ($help) print $help ?>
  </div></div>
  <?php endif; ?>
  
  <div id="bg-top" class="limiter clear-block"></div>
  <div id ='page' class='clear-block limiter'><div class='page-content'><div class='clear-block'>
    
    <div id='header' class='clear-block'>
      <?php print l('<img src="'. $logo .'" alt="" />', '<front>', array('html' => TRUE)) ?>
      <?php print $header ?>
    </div>
  
    <?php if ($show_messages && $messages): ?>
      <div id='console' class='clear-block'><?php print $messages; ?></div>
    <?php endif; ?>
