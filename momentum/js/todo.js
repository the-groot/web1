const toDoForm=document.getElementById("todo-form");
const toDoInput=toDoForm.querySelector("input");
const toDoList=document.getElementById("todo-list");

const TODOS_KEY="todos";

let toDos=[];


function saveToDos(){   
    //데이터 localStorage에 저장하는 함수

    localStorage.setItem(TODOS_KEY, JSON.stringify(toDos)); //key : todos , value : {text, id} stringify는 string형태로 저장하는 것
}

function deleteTodo(event){
    //데이터 삭제하는 함수

    const li=event.target.parentElement;        //event.target.parentElement가 눌려진 버튼의 정보를 담고있음
    li.remove();                                //제거하고
    toDos=toDos.filter((toDo) => toDo.id !==parseInt(li.id));   //li.id와 다른것들은 toDos에 그대로 저장(li.id와 toDo.id가 같으면 배열에서 제거)
    saveToDos();        //saveToDos()호출
}

function paintToDo(newTodo){
    //화면에 데이터를 출력하는 함수

    const li=document.createElement("li");      //li를 html에 만들어줌
    li.id=newTodo.id;                           //li.id에 newTodo.id 저장
    const span=document.createElement("span");  //span을 html에 만들어줌
    span.innerText=newTodo.text;                //span에 newTodo.text를 출력
    const button=document.createElement("button");  //button을 만들어줌
    button.innerText="❌";                          //button을 x로 화면에 출력
    button.addEventListener("click",deleteTodo);    //x버튼이 눌렸을때 deleteTodo()호출
    li.appendChild(span);
    li.appendChild(button);
    toDoList.appendChild(li);
}

function handleToDoSubmit(event){
    //submit이 일어났을때 값을 toDos에 저장하는 함수

    event.preventDefault();     //submit했을때 새로고침 막아주고
    const newTodo=toDoInput.value;  //input값(text)를 newTodo 변수에 저장
    toDoInput.value="";     //그리고 toDoInput.value를 비워줌
    const newTodoObj={  //객체를 만들어 text와 id설정
        text: newTodo,
        id : Date.now(),
    };
    toDos.push(newTodoObj); //toDos에 객체 값 저장
    paintToDo(newTodoObj);  //paintToDo()호출
    saveToDos();            //saveToDos()호출
}

toDoForm.addEventListener("submit",handleToDoSubmit);       //클릭이나 엔터(submit)하면 handleToDoSubmit호출

function sayHello(){
    console.log("hello");
}

const savedToDos=localStorage.getItem(TODOS_KEY);   //localStorage에 저장된 값을 불러옴 

if(savedToDos){     //savedToDos가 비어있지 않으면
    const parsedToDos=JSON.parse(savedToDos);   //savedToDos는 saveToDos()로 인해 string형태로 저장돼있으므로
                                                //string을 array형태로 다시 저장해줌 
    toDos=parsedToDos;                          //그걸 다시 toDos에 저장해줌
    parsedToDos.forEach(paintToDo);             //각각 paintToDo호출
}
 