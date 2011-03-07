<?php
/**
 * Filter by spotlight node type
 */
class feature_spotlight_handler_filter_node_type extends views_handler_filter_boolean_operator {

  function construct() {
    parent::construct();
    $this->value_value = t('Node type is a spotlight provider');
  }

  function get_value_options() {
    $this->value_options = array(1 => t('Yes'), 0 => t('No'));
  }

  function query() {
    $table = $this->ensure_my_table();
    $settings = module_invoke_all('spotlight_image');
    $content_types = array_keys($settings);
    $query = implode("','", $content_types);
    $operator = $this->options['value'] ? 'IN' : 'NOT IN';
    $this->query->add_where('AND', "$table.type $operator ('$query')");
  }

}


