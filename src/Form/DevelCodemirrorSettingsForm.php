<?php

namespace Drupal\devel_codemirror\Form;

use Drupal\Core\Form\ConfigFormBase;
use Drupal\Core\Form\FormStateInterface;

/**
 * Class DevelCodemirrorSettingsForm.
 */
class DevelCodemirrorSettingsForm extends ConfigFormBase {

  const THEMES = [
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

  /**
   * {@inheritdoc}
   */
  protected function getEditableConfigNames() {
    return [
      'devel_codemirror.settings',
    ];
  }

  /**
   * {@inheritdoc}
   */
  public function getFormId() {
    return 'devel_codemirror_settings_form';
  }

  /**
   * {@inheritdoc}
   */
  public function buildForm(array $form, FormStateInterface $form_state) {
    $config = $this->config('devel_codemirror.settings');
    $form['theme'] = [
      '#type' => 'select',
      '#title' => $this->t('Theme'),
      '#options' => self::THEMES,
      '#required' => TRUE,
      '#default_value' => $config->get('theme'),
    ];
    $form['line_number'] = [
      '#type' => 'checkbox',
      '#title' => $this->t('Line number'),
      '#default_value' => $config->get('line_number'),
    ];
    return parent::buildForm($form, $form_state);
  }

  /**
   * {@inheritdoc}
   */
  public function submitForm(array &$form, FormStateInterface $form_state) {
    parent::submitForm($form, $form_state);

    $this->config('devel_codemirror.settings')
      ->set('theme', $form_state->getValue('theme'))
      ->set('line_number', $form_state->getValue('line_number'))
      ->save();
  }

}
