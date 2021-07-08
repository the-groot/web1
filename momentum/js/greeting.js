const LoginForm=document.querySelector("#login-form");
const LoginInput=LoginForm.querySelector("input");
const greeting=document.querySelector("#greeting");

const HIDDEN_CLASSNAME="hidden";
const USERNAME_KEY="username"

function onLoginSubmit(event){


    const username=LoginInput.value;        //username에 LoginInput text 저장
    event.preventDefault();                 //새로고침 막음
    localStorage.setItem(USERNAME_KEY,username);    //localStorage에 key : "username" , value : "text" 저장
    LoginForm.classList.add(HIDDEN_CLASSNAME);      //LoginForm hidden해줌
    paintGreetings(username);                       //paintGreetings()호출
}

function handleLinkClick(event){
    event.preventDefault();
    console.dir(event);
}

function paintGreetings(username){
    greeting.innerText=`Hello ${username}`;     //html의 greeting부분의 text를 Hello text형식으로 화면에 출력
    greeting.classList.remove(HIDDEN_CLASSNAME);    //greeting hidden해줌
}


const savedUsername=localStorage.getItem(USERNAME_KEY); //localStorage에 저장된 username값 받아옴

if(savedUsername===null){       //localStorage에 저장된 username이 비어있으면
    LoginForm.classList.remove(HIDDEN_CLASSNAME);   //hidden 지우고
    LoginForm.addEventListener("submit",onLoginSubmit);     //submit이벤트 기다림
                                                            //submit되면 onLoginSubmit()호출
}

else{       //localStorage에 저장된 username이 없으면
    paintGreetings(savedUsername);  //paintGreetings() 호출
}