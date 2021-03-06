/* $Id: README.txt,v 1.12 2010/01/06 00:42:59 sun Exp $ */

-- SUMMARY --

Inline module allows you to display files uploaded with the current node
inline, i.e. with a link to the original file, using special tags. The tags
will be replaced with links to the corresponding files. If a tag refers to an
image, it will be replaced with the image.

Inline module does not attempt to resize a images. It assumes that the user 
will optimize the size and resolution of images prior to uploading it. A
configuration setting of this module allows to specify the maximum display
width and height for inline images. If the original image is not bigger than
the maximum width and height, it will be displayed as-is, otherwise its
dimensions will be recalculated, maintaining the same aspect ratio.

For a full description visit the project page:
  http://drupal.org/project/inline
Bug reports, feature suggestions and latest developments:
  http://drupal.org/project/issues/inline


-- REQUIREMENTS --

* Upload module (Drupal core)

* ImageCache (optional)


-- INSTALLATION --

* Install as usual, see http://drupal.org/node/70151 for further information.


-- CONFIGURATION --

* Enable "Inline content" in the input formats you intend to use. To do this, go
  to Administer >> Input formats and click on one of the "Configure" links. For
  instance, you can click on the "Configure" link for "Filtered HTML" and then
  you will see a list of filters including "Inline content". Turn that on and
  click on "Save".

* When using the optional Inline Upload module:

  Go to Administer >> Site configuration >> Inline and edit the maximum width
  and height for inline images.  If an image exceeds those dimensions, it will
  be displayed as text link to download (like any other attachment than images).

  Please note that this configuration setting no longer applies if the optional
  ImageCache module is installed.


-- USAGE --

* For more details on using the module, see the help text by clicking:
  /filter/tips/1#filter-inline after you install it.

  [upload|file=#|title=Custom title text]
  or
  [upload|file=filename.ext|title=Any title]

  You can specify the file you want to display in two ways:
  - specifying #, which will display the #th uploaded file
  - specifying filename

  If the file is not found, a 'NOT FOUND' message will be output.

  Specifying the file by number can cause problems if files are deleted or
  changed. In this case, specifying by name is recommended.

  You can also specify a title for the file, by using an optional 'title=Title'
  parameter. In this case, it will be used as a title for the file link or as
  an ALT tag for an image. If no title is specified, the file name is used as
  title.


-- EXAMPLES --

* Suppose you uploaded three files (in this order):
  - imag1.png (referred as file #1)
  - file2.pdf (referred as file #2)
  - imag3.png (referred as file #3)

* [upload|file=2] or [upload|file=file2.pdf]
  will be replaced with <a href="file2.pdf">file2.pdf</a>

* [upload|file=1|title=test] or [upload|file=imag1.png|title=test]
  will be replaced with <img src="imag1.png" alt="test" />


-- CONTACT --

Current maintainers:
* Daniel F. Kudwien (sun) - dev@unleashedmind.com

Previous maintainers:
* Richard Archer (Richard Archer) - http://www.juggernaut.com.au
* Matteo Ferrari (matteo) - webmaster@cantincoro.org

This project has been sponsored by:
* UNLEASHED MIND
  Specialized in consulting and planning of Drupal powered sites, UNLEASHED
  MIND offers installation, development, theming, customization, and hosting
  to get you started. Visit http://www.unleashedmind.com for more information.

