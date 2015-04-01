<?php


/**
 * Implements hook_block_info()
 *
 * https://api.drupal.org/api/drupal/modules%21block%21block.api.php/function/hook_block_info/7
 */
function MODULE_block_info() {
  $blocks['your_block'] = array(
    'info' => t('Your block title.'),
    'cached' => 'optional caching constant if you need it.'
  );
  return $blocks;
}


/**
 * Implements hook_block_view()
 *
 */
function MODULE_block_view($delta = '') {
 $block = array();

 switch ($delta) {
   case 'your_block' :
     $result = build_your_block();
     $block['content'][]['#markup'] = $result;
     break; 

 return $block;
}


function build_your_block() { 
 $block_content = array('stuff', 'things', 'sundry');
 
 // theme() bekijkt de roland_products_submenu en geeft die door aan MODULE_NAME_theme() om die in een template file te rammen.
 $menu = theme('some_key', array("items" => $block_content));
 
 return $menu; 
}


/**
 * Implements hook_theme()
 *
 */
function MODULE_theme() {
  $path = drupal_get_path('module', 'MODULE') . '/templates';
  $variables = array();


  $themed = array(
    'some_key' => array(
      'template' => 'name_of_template_file',
      'variables' => $items,
      'path' => $path,
    )
  );

  return $themed;
}