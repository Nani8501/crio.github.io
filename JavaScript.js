//Data Fetching

document.addEventListener('DOMContentLoaded', () => {
  const dataButtons = document.querySelectorAll('.data-button');

  dataButtons.forEach(button => {
    button.addEventListener('click', () => {
      const datasetName = button.getAttribute('data-dataset');

      // Data Fetching
      fetch('data2.json')
        .then(response => {
          if (!response.ok) {
            throw new Error('Network response was not ok');
          }
          return response.json();
        })
        .then(data => {
          const searchPage = data.find(page => page.name === datasetName);

          if (searchPage) {
            // document.body.style.backgroundImage = `url('${searchPage.backgroundImage}')`;
            document.getElementById('navtext1').textContent = searchPage.name;
            document.getElementById('spec').textContent = searchPage.specifications.spe;
            document.getElementById('spec1').textContent = searchPage.specifications.spec1;
            document.getElementById('spec2').textContent = searchPage.specifications.spec2;
            document.getElementById('spec3').textContent = searchPage.specifications.spec3;
            document.getElementById('card').textContent = searchPage.card;
            document.getElementById('explanation').textContent = searchPage.explanation;
            document.getElementById('time-complexity').textContent = searchPage.complexity.time;
            document.getElementById('space-complexity').textContent = searchPage.complexity.space;

            const codeCPath = searchPage.code.c;
            const codeJavaPath = searchPage.code.java;
            const codePythonPath = searchPage.code.python;
        
            // Fetch code content from the paths
            fetch(codeCPath)
              .then(response => response.text())
              .then(codeC => {
                document.getElementById('code-c').textContent = codeC;
              })
              .catch(error => {
                console.error('Error fetching C code:', error);
              });
        
            fetch(codeJavaPath)
              .then(response => response.text())
              .then(codeJava => {
                document.getElementById('code-java').textContent = codeJava;
              })
              .catch(error => {
                console.error('Error fetching Java code:', error);
              });
        
            fetch(codePythonPath)
              .then(response => response.text())
              .then(codePython => {
                document.getElementById('code-py').textContent = codePython;
              })
              .catch(error => {
                console.error('Error fetching Python code:', error);
              });
            console.log(`Loaded data for ${datasetName}`);
          } else {
            console.error(`${datasetName} page not found.`);
          }
        })
        .catch(error => {
          console.error('Error fetching data:', error);
        });
    });
  });

  // Other code (e.g., theme toggling, copying to clipboard, etc.)

//Data Fetching Completed

document.addEventListener('DOMContentLoaded', function() {
  const dropdownMenu = document.querySelector('.dropdown-menu');
  const menuBtn = dropdownMenu.querySelector('.menu-btn');
  const menuContent = dropdownMenu.querySelector('.menu-content');

  menuBtn.addEventListener('click', function() {
     dropdownMenu.classList.toggle('active');
  });

  // Close the dropdown when clicking outside
  document.addEventListener('click', function(event) {
     if (!dropdownMenu.contains(event.target)) {
        dropdownMenu.classList.remove('active');
     }
  });
});

// JavaScript to toggle between dark and light themes
document.getElementById('toggle').addEventListener('change', function() {
    if (this.checked) {
        document.body.classList.add('dark-mode');
    } else {
        document.body.classList.remove('dark-mode');
    }
});
// JavaScript to toggle between dark and light themes Completed

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


var acc = document.getElementsByClassName("accordion");
var i;

for (i = 0; i < acc.length; i++) {
  acc[i].addEventListener("click", function() {
    /* Toggle between adding and removing the "active" class,
    to highlight the button that controls the panel */
    this.classList.toggle("active");

    /* Toggle between hiding and showing the active panel */
    var panel = this.nextElementSibling;
    if (panel.style.display === "block") {
      panel.style.display = "none";
    } else {
      panel.style.display = "block";
    }
  });
}
});
