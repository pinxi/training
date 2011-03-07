core = 6.x

;
; Modules
;
projects[markdown][version] = "1.2"

projects[strongarm][version] = "2.0"

projects[features][version] = "1.0"

projects[inline][type] = "module"
projects[inline][download][type] = "cvs"
projects[inline][download][module] = "contributions/modules/inline"
projects[inline][download][revision] = "HEAD:2010-03-06"

;
; Patches
;
projects[inline][patch][] = "http://drupal.org/files/issues/inline_upload-imagecache_and_position-2.patch"

