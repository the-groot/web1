const quotes=[
    {
        quote: "흘러가는 대로 살지마라. 항상 계획을 세우고 살아라."
    },
    {
        quote: "절대 집에서 공부하지 마라. 밖에서 공부해라."
    },
    {
        quote: "쉬는날을 제외하고 기상시간을 항상 정해놔라."
    },
    {
        quote: "공부할때는 핸드폰을 보지말자."
    },
    {
        quote: "쉬는날을 제외하고 취침시간은 절대 12시를 넘기지 말자."
    },
    {
        quote: "운동을 하는 것은 좋지만, 운동만 해서는 안 된다."
    },
    {
        quote: "잠을 줄일 필요가 있다. 잠을 못 줄이겠으면 낮에 공부를 많이 하자."
    },
    {
        quote: "생각을 하면서 살자. 미래에 어떤 사람이 되고싶은지 그러려면 어떻게 살아야하는지 생각하며 살자."
    },
    {
        quote: "혼자 공부할 자신이 없으면 학원의 힘을 빌리는 것도 하나의 방법이다."
    },
    {
        quote: "만약 나태해졌거나,  나태해질 것 같으면 7월 24일 휴가복귀한 날, 그때의 마음가짐을 다시 한 번 떠올려 보자. 난 할 수 있다."
    },
];

const quote=document.querySelector("#quote span:first-child");
const author=document.querySelector("#quote span:last-child");
const todaysQuote=quotes[Math.floor(Math.random()*quotes.length)];

quote.innerText=todaysQuote.quote;
author.innerText="임상우";