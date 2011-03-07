<?php

class feature_spotlight_handler_field_spotlight_image extends content_handler_field {

  function construct() {
    parent::construct();
    // Placeholder field, useful to get the right formatters.
    $this->content_field = array(
      'field_name'  => 'field_spotlight_image',
      'type'        => 'filefield',
      'module'      => 'filefield',
      'multiple'    => 0,
    );
  }

  function options_form(&$form, &$form_state) {
    parent::options_form($form, $form_state);
    unset($form['label']);
    unset($form['label_type']);
  }


  function render($values) {

    $settings = module_invoke_all('spotlight_image');
    if ($spotlight_image = $settings[$values->node_type]) {
      // Link the handler to the new field.
      if ($this->content_field = content_fields($spotlight_image, $values->node_type)) {
          $this->get_values($values);
          $this->aliases['delta'] = 'field_spotlight_image_delta';
          $values->{$this->aliases['delta']} = 0;     // Take the first of multiple images
          return parent::render($values);
      }
    }
    return '';
  }

  /**
   * Get values stored in the database.
   */
  function get_values(&$values) {

    $db_info = content_database_info($this->content_field);
    // Fetch field value from the database
    if ($field = db_fetch_array(db_query("SELECT * FROM {". $db_info['table'] ."} WHERE vid = %d", $values->node_vid))) {
      // Populate $values as it was obtained from running the view's query.
      foreach ($db_info['columns'] as $column => $attributes) {
        $field_name = $this->content_field['field_name'] .'_'. $column;
        $this->aliases[$attributes['column']] = $this->content_field['field_name'] .'_'. $attributes['column'];
        $values->{$this->aliases[$attributes['column']]} = $field[$attributes['column']];
      }
    }
  }

}
