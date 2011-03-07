

Drupal.theme.prototype.viewsSlideshowPagerNumbered = function (classes, idx, slide, settings) {
  var href = '#';
  if (settings.pager_click_to_page) {
    href = $(slide).find('a').attr('href');
  }
  return '<div class="' + classes + '"><a href="' + href + '">&nbsp;<span>' + (idx+1) + '</span></a></div>';
}
