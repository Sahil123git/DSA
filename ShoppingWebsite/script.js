const bar = document.getElementById("bar");
const navbar = document.getElementById("navBar");
const close = document.getElementById("closeOptn");

if (bar) {
  bar.addEventListener("click", () => {
    //if navbar is clicked then add active class
    navbar.classList.add("active");
  });
}

if (close) {
  close.addEventListener("click", () => {
    //if close optn is clicked then remove active class
    navbar.classList.remove("active");
  });
}
