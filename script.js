let button = document.getElementById("submit");

function play(event) {
  event.preventDefault();
  const name = document.getElementById('name').value;
  const amount = document.getElementById('amount').value;
  localStorage.setItem('Name', name);
  localStorage.setItem('Amount', amount);
  window.location.href = "play.html";

}

const home = () => {
  if (localStorage.getItem('Name') === null && localStorage.getItem('Amount') === null) {
    window.location.href = "index.html";
  } else {
    localStorage.removeItem("Name");
    localStorage.removeItem("Amount");
    window.location.href = "index.html";
  };
};             