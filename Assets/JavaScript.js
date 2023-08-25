// JavaScript to toggle between dark and light themes
document.getElementById('toggle').addEventListener('change', function() {
    if (this.checked) {
      document.body.classList.add('dark-mode');
    } else {
      document.body.classList.remove('dark-mode');
    }
  });

  
// JavaScript to toggle between dark and light themes and trigger slide animation
// JavaScript to toggle between dark and light themes
document.getElementById('toggle').addEventListener('change', function() {
  if (this.checked) {
    document.body.classList.add('dark-mode');
  } else {
    document.body.classList.remove('dark-mode');
  }
});







function CopyToClipboard(id)
{
var r = document.createRange();
r.selectNode(document.getElementById(id));
window.getSelection().removeAllRanges();
window.getSelection().addRange(r);
document.execCommand('copy');
window.getSelection().removeAllRanges();
}