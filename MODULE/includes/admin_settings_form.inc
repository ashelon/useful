<?php

/**
 * Implements hook_menu()
 *
 */
function MODULE_menu()
{
  $items['admin/content/settings'] = array(
    'page callback' => 'drupal_get_form',
    'page arguments' => array('_website_settings_form'),
    'access callback' => 'MODULE_checkaccess',
    'access arguments' => array(array('administrator', 'Content beheerder')),
    'title' => 'Admin settings form',
    'type' => MENU_NORMAL_ITEM,
  );

  return $items;
}


/**
 * Check access
 *
 */
function MODULE_checkaccess($roles) {
  global $user;
  foreach ($roles as $role) {
    if (in_array($role, $user->roles)) {
      return TRUE;
    }
  }
  return FALSE;
}


/**
 * Provide a form to set miscellaneous text fields
 *
 */
function _website_settings_form()
{
  $form = array();

  $form['intro'] = array(
    '#type' => 'item',
    '#markup' => 'Introductory text explaining the function of this form.'
  );

  $form['text_fieldset'] = array(
    '#type' => 'fieldset',
    '#title' => t('Feedback formulier'),
    '#weight' => 0,
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
  );

  $form['text_fieldset']['plain_text_field'] = array(
   '#title' => t('Some default plain text field.'),
    '#type' => 'textarea',
    '#description' => t('Lorem ipsum.'),
    '#default_value' => variable_get('plain_text_field', ''),
  );

  // Filtered HTML in a variable is stored serialised, so retrieve it first as an array.
  $fancy_text = variable_get('fancy_html_field');

  $form['text_fieldset']['fancy_text'] = array(
    '#title' => t('Fancy text'),
    '#type' => 'text_format',
    '#description' => t('Lorem ipsum with markup.'),
    '#default_value' => $fancy_text['value'],
    '#format' => 'filtered_html',
  );

  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Save')
  );

  return $form;
}


/**
 * _website_settings_form() submit handler
 *
 */
function _website_settings_form_submit($form, &$form_state) {
  //dpm($form_state, 'form in _website_settings_form_submit');
  variable_set('plain_text_field', $form_state['values']['plain_text_field']);
  variable_set('fancy_text', $form_state['values']['fancy_text']);
  drupal_set_message('Your changes have been saved.');
}