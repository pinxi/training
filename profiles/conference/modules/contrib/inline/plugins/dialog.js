// $Id: dialog.js,v 1.1 2009/08/08 06:56:42 sun Exp $

/**
 * Attach insert/close behavior to Inline-based Wysiwyg dialogs.
 */
Drupal.behaviors.inlineWysiwygDialog = function (context) {
  var target = window.opener || window.parent;
  var dialog = Drupal.settings.wysiwyg;
  // @todo Only apply this behavior to Wysiwyg dialogs.
  $('form input[type=submit]', context).click(function () {
    var settings = {};
    // Retrieve inline macro parameters from form elements.
    $(this.form).find(':input').each(function () {
      settings[this.name] = $(this).val();
    });
    // Insert into currently attached editor.
    target.Drupal.wysiwyg.instances[dialog.instance].insert(target.Drupal.wysiwyg.plugins[dialog.plugin].insert(settings));
    // Close this dialog.
    target.Drupal.wysiwyg.instances[dialog.instance].closeDialog(window);
    return false;
  });
  $('a.form-cancel', context).click(function () {
    // Close this dialog.
    target.Drupal.wysiwyg.instances[dialog.instance].closeDialog(window);
    return false;
  });
}
