<?php

class feature_spotlight_handler_field_spotlight_description extends views_handler_field_markup {

  function render($values) {
    $result = module_invoke_all('spotlight_description_' .$values->node_type, $values->nid);
    if ($result) {
      return $result[0];
    }
    else {
      return parent::render($values);  // Render teaser.
    }
  }

}
