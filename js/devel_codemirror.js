(function ($) {
  Drupal.behaviors.devel_codemirror = {
    attach: function (context) {
      var config = Drupal.settings.devel.codemirror;

      config.mode = 'text/x-php';
      config.tabSize = 2;

      CodeMirror.fromTextArea(document.getElementById('edit-code'), config);
    }
  }
}(jQuery));
