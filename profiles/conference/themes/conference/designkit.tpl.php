<style type='text/css'>
#top {
  border-top: 3px solid <?php print $background ?>;
}
body.rubik {
  background-color:<?php print $background ?>;
}

#header {
  background: transparent url("<?php print $header_image ?>") no-repeat;
  height: 180px;
  margin-top: -16px;
}
  
#page-title ul.links li.active a,
#page-title ul.links li a.active {
  background-color:<?php print $foreground ?>;
}

div.pager li.pager-current,
#tabs div.page-tabs li.active a,
#tabs div.page-tabs li a.active {
  background-color:<?php print $foreground ?>;
}

div.block ul.menu a:hover {
  background:<?php print designkit_colorshift($foreground, '#ffffff', .6) ?>;
}
div.block ul.menu a {
  background:<?php print designkit_colorshift($foreground, '#ffffff', .8) ?>;
  color:<?php print designkit_colorshift($foreground, '#000000', .5) ?>;
}

.block .block-title {
  background-color:<?php print designkit_colorshift($foreground, '#ffffff', .8) ?>;
}

.spotlight .subtitle,
.spotlight .title,
.spotlight .link a,
div.block ul.menu a.active, div.block ul.menu a.active:hover {
  background:<?php print designkit_colorshift($foreground, '#000000', .2) ?>;
  color:<?php print designkit_colorshift($foreground, '#ffffff', .95) ?>;
}
a {
  color:<?php print designkit_colorshift($foreground, '#000000', .5) ?>;
}

.spotlight .spotlight-container {
  border:5px solid <?php print designkit_colorshift($foreground, '#ffffff', .8) ?>;
}

input.form-submit:hover {
  border-color:<?php print designkit_colorshift($foreground, '#000000', .2) ?>;
  border-bottom-color:<?php print designkit_colorshift($foreground, '#000000', .4) ?>;
  background-color:<?php print $foreground ?>;
}
</style>
 