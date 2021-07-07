const LoginForm=document.querySelector("#login-form");
const LoginInput=LoginForm.querySelector("input");
const greeting=document.querySelector("#greeting");

const HIDDEN_CLASSNAME="hidden";
const USERNAME_KEY="username"

function onLoginSubmit(event){
    console.dir(LoginInput);
    const username=LoginInput.value;
    event.preventDefault();
    localStorage.setItem(USERNAME_KEY,username);
    LoginForm.classList.add(HIDDEN_CLASSNAME);
    paintGreetings(username);
}

function handleLinkClick(event){
    event.preventDefault();
    console.dir(event);
}

function paintGreetings(username){
    greeting.innerText=`Hello ${username}`;
    greeting.classList.remove(HIDDEN_CLASSNAME);
}


const savedUsername=localStorage.getItem(USERNAME_KEY);

if(savedUsername===null){
    LoginForm.classList.remove(HIDDEN_CLASSNAME);
    LoginForm.addEventListener("submit",onLoginSubmit);
}

else{
    paintGreetings(savedUsername);
}