const LoginForm=document.querySelector("#login-form");
const LoginInput=LoginForm.querySelector("input");
const greeting=document.querySelector("#greeting");

const HIDDEN_CLASSNAME="hidden";

function onLoginSubmit(event){
    console.dir(LoginInput);
    const username=LoginInput.value;
    event.preventDefault();
    LoginForm.classList.add(HIDDEN_CLASSNAME);
    greeting.innerText=`Hello ${username}`;
    greeting.classList.remove(HIDDEN_CLASSNAME);
}

function handleLinkClick(event){
    event.preventDefault();
    console.dir(event);
}

LoginForm.addEventListener("submit",onLoginSubmit);
