<?php

/**
 * @file
 * Contains devel_codemirror admin settings.
 */

/**
 * Callback for devel codemirror settings form.
 */
function devel_codemirror_settings_form(array $form, array &$form_state) {
  $config = variable_get('devel_codemirror_settings', []);

  $form['devel_codemirror_settings'] = [
    '#tree' => TRUE,
  ];

  $form['devel_codemirror_settings']['theme'] = [
    '#type' => 'select',
    '#title' => t('Theme'),
    '#description' => t('The theme to style the editor with.'),
    '#options' => devel_codemirror_theme_options(),
    '#empty_value' => 'default',
    '#default_value' => $config['theme'] ?? 'default',
  ];
  $form['devel_codemirror_settings']['lineWrapping'] = [
    '#type' => 'checkbox',
    '#title' => t('Line wrapping'),
    '#description' => t('Whether CodeMirror should scroll or wrap for long lines.'),
    '#default_value' => $config['lineWrapping'] ?? FALSE,
  ];
  $form['devel_codemirror_settings']['lineNumbers'] = [
    '#type' => 'checkbox',
    '#title' => t('Line number'),
    '#description' => t('Whether to show line numbers to the left of the editor.'),
    '#default_value' => $config['lineNumbers'] ?? FALSE,
  ];
  $form['devel_codemirror_settings']['matchBrackets'] = [
    '#type' => 'checkbox',
    '#title' => t('Match brackets'),
    '#description' => t('When set to true or, causes matching brackets to be highlighted whenever the cursor is next to them.'),
    '#default_value' => $config['matchBrackets'] ?? FALSE,
  ];
  $form['devel_codemirror_settings']['autoCloseBrackets'] = [
    '#type' => 'checkbox',
    '#title' => t('Auto close brackets'),
    '#description' => t('Auto-close brackets and quotes when typed.'),
    '#default_value' => $config['autoCloseBrackets'] ?? FALSE,
  ];
  $form['devel_codemirror_settings']['styleActiveLine'] = [
    '#type' => 'checkbox',
    '#title' => t('Style active line'),
    '#default_value' => $config['styleActiveLine'] ?? FALSE,
  ];

  return system_settings_form($form);
}

/**
 * Returns all the options for the devel codemirror theme select list.
 *
 * @return array
 *   An #options array of all the available codemirror themes.
 */
function devel_codemirror_theme_options() {
  return [
    '3024-day' => '3024 day',
    '3024-night' => '3024 night',
    'abcdef' => 'ABCDEF',
    'ambiance' => 'Ambiance',
    'ambiance-mobile' => 'Ambiance mobile',
    'base16-dark' => 'Base16 dark',
    'base16-light' => 'Base16 light',
    'bespin' => 'Bespin',
    'blackboard' => 'Blackboard',
    'cobalt' => 'Cobalt',
    'colorfort' => 'Colorforth',
    'dracula' => 'Dracula',
    'duotone-dark' => 'DuoTone-Dark',
    'duotone-light' => 'DuoTone-Light',
    'eclipse' => 'Eclipse',
    'elegant' => 'Elegant',
    'erlang-dark' => 'Erlang dark',
    'hopscotch' => 'Hopscotch',
    'icecoder' => 'ICEcoder',
    'isotope' => 'Isotope',
    'lesser-dark' => 'Less CSS dark',
    'liquibyte' => 'Liquibyte',
    'material' => 'Material',
    'mbo' => 'Mbo',
    'mdn-like' => 'MDN-LIKE Theme - Mozilla',
    'midnight' => 'Midnight',
    'monokai' => 'Monokai',
    'neat' => 'Neat',
    'neo' => 'Neo',
    'night' => 'Night',
    'panda-syntax' => 'Panda Syntax',
    'paraiso-dark' => 'Paraíso (Dark)',
    'paraiso-light' => 'Paraíso (Light)',
    'pastel-on-dark' => 'Pastel On Dark',
    'railscasts' => 'Railscasts',
    'rubyblue' => 'Rubyblue',
    'seti' => 'Seti',
    'solarized' => 'Solarized',
    'the-matrix' => 'The matrix',
    'tomorrow-night-bright' => 'Tomorrow Night - Bright',
    'tomorrow-night-eighties' => 'Tomorrow Night - Eighties',
    'ttcn' => 'TTCN',
    'twilight' => 'Twilight',
    'vibrant-ink' => 'Vibrant ink',
    'xq-dark' => 'XQ dark',
    'xq-light' => 'XQ light',
    'yeti' => 'Yeti',
    'zenburn' => 'Zenburn',
  ];
}
