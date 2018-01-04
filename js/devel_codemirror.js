Drupal.behaviors.develCodemirror = {
  attach: function (context, settings) {
    var config = settings.devel.codemirror;

    config.mode = 'text/x-php';
    config.tabSize = 2;

    CodeMirror.fromTextArea(document.getElementById('edit-code'), config);
  }
};
