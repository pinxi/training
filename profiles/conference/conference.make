core = 6.x
api = 2

;
; Modules
;
projects[admin][subdir] = "contrib"
projects[admin][version] = "2.0"

projects[captcha][subdir] = "contrib"
projects[captcha][version] = "2.4"

projects[cck][subdir] = "contrib"
projects[cck][version] = "2.9"

projects[content_profile][subdir] = "contrib"
projects[content_profile][version] = "1.0"

projects[context][subdir] = "contrib"
projects[context][version] = "3.0"

projects[ctools][subdir] = "contrib"
projects[ctools][version] = "1.8"

projects[date][subdir] = "contrib"
projects[date][version] = "2.7"

projects[designkit][type] = "module"
projects[designkit][download][type] = "cvs"
projects[designkit][download][module] = "contributions/modules/designkit"
projects[designkit][download][revision] = "DRUPAL-6--1:2010-08-12"
projects[designkit][subdir] = "contrib"

projects[diff][subdir] = "contrib"
projects[diff][version] = "2.1"

projects[email][subdir] = "contrib"
projects[email][version] = "1.2"

projects[feeds][subdir] = "contrib"
projects[feeds][version] = "1.0-beta4"

projects[features][subdir] = "contrib"
projects[features][version] = "1.0"

projects[filefield][subdir] = "contrib"
projects[filefield][version] = "3.9"

projects[flag][subdir] = "contrib"
projects[flag][version] = "2.0-beta5"

projects[imageapi][subdir] = "contrib"
projects[imageapi][version] = "1.9"

projects[imagecache][subdir] = "contrib"
projects[imagecache][version] = "2.0-beta10"

projects[imagefield][subdir] = "contrib"
projects[imagefield][version] = "3.9"

; Revision from 6 March 2010 http://drupalcode.org/project/inline.git/commit/5a51424
projects[inline][type] = "module"
projects[inline][download][type] = "git"
projects[inline][download][url] = "http://git.drupal.org/project/inline.git"
projects[inline][download][revision] = "5a514240ab62071866790ec88e6c6dcd720a7339"
projects[inline][subdir] = "contrib"

projects[jquery_ui][subdir] = "contrib"
projects[jquery_ui][version] = "1.4"

projects[lightbox2][subdir] = "contrib"
projects[lightbox2][version] = "1.11"

projects[link][subdir] = "contrib"
projects[link][version] = "2.9"

projects[markdown][subdir] = "contrib"
projects[markdown][version] = "1.2"

projects[pathauto][subdir] = "contrib"
projects[pathauto][version] = "1.5"

projects[recaptcha][subdir] = "contrib"
projects[recaptcha][version] = "1.4"

projects[rules][subdir] = "contrib"
projects[rules][version] = "1.4"

projects[select_or_other][subdir] = "contrib"
projects[select_or_other][version] = "2.4"

projects[semanticviews][subdir] = "contrib"
projects[semanticviews][version] = "1.1"

projects[strongarm][subdir] = "contrib"
projects[strongarm][version] = "2.0"

projects[tablegroup][type] = "module"
projects[tablegroup][download][type] = "cvs"
projects[tablegroup][download][module] = "contributions/modules/tablegroup"
projects[tablegroup][download][revision] = "DRUPAL-6--1:2010-07-25"
projects[tablegroup][subdir] = "contrib"

projects[token][subdir] = "contrib"
projects[token][version] = "1.15"

projects[transliteration][subdir] = "contrib"
projects[transliteration][version] = "3.0"

projects[upload_element][subdir] = "contrib"
projects[upload_element][version] = "1.2"

projects[views][subdir] = "contrib"
projects[views][version] = "2.12"

projects[views_bonus][type] = "module"
projects[views_bonus][download][type] = "cvs"
projects[views_bonus][download][module] = "contributions/modules/views_bonus"
projects[views_bonus][download][revision] = "DRUPAL-6--1:2010-07-22"
projects[views_bonus][subdir] = "contrib"

projects[views_bulk_operations][subdir] = "contrib"
projects[views_bulk_operations][version] = "1.10"

projects[views_slideshow][subdir] = "contrib"
projects[views_slideshow][version] = "2.3"

;
; Features from Git
;
projects[feature_site][subdir] = "features"
projects[feature_site][type] = "module"
projects[feature_site][download][type] = "git"
projects[feature_site][download][url] = "git://github.com/ademarco/feature_site.git"

:
; Development modules
:
projects[schema][subdir] = "dev"
projects[schema][version] = "1.7"

projects[simpletest][subdir] = "dev"
projects[simpletest][version] = "2.8"

projects[backup_migrate][subdir] = "dev"
projects[backup_migrate][version] = "2.4"

;
; Themes
;
projects[tao][version] = "3.2"

projects[rubik][version] = "3.0-beta2"

;
; Libraries
;
libraries[jquery_ui][download][type] = "get"
libraries[jquery_ui][download][url] = "http://jquery-ui.googlecode.com/files/jquery.ui-1.6.zip"
libraries[jquery_ui][directory_name] = "jquery.ui"
libraries[jquery_ui][destination] = "modules/contrib/jquery_ui"

;
; Patches
;
projects[designkit][patch][] = "http://drupal.org/files/issues/designkit-default_fallback-2.patch"

projects[inline][patch][] = "http://drupal.org/files/issues/inline_upload-imagecache_and_position-2.patch"



