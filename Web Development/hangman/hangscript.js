let scores=[];
var counter=0;
let inter;
var x=[]
let l=[]
let usedel=[];
let n;
let c
let crt;
let canvas
words=[ 'CHENNAI','MUMBAI','DELHI','BANGALORE','AFRICA','AMSTERDAM','AMERICA','NEWZEALAND','PUNE','KOLKATA','JAIPUR','RANCHI','LAHORE','NEWYORK','CALIFORNIA','DUBAI','BERLIN','MOSCOW','COPENHAGEN','CAIRO']
function init(){
    const string=words[Math.floor(Math.random()*words.length)];
    x=string.split('');
    console.log(x)
    n=x.length;
    counter =0;
    console.log(string);
    usedel=[];
    const txt3=usedel.join(", ");
    document.getElementById('used').innerHTML="USED LETTERS: \n"+txt3;
    l=[];
    crt=0;
    //canvas
    canvas=document.querySelector('canvas')
    canvas.height =425;
    canvas.width =400;
    c=canvas.getContext("2d");
    c.beginPath();
    c.lineWidth=10;
    c.moveTo(150,400);
    c.lineTo(250,400);
    c.moveTo(200,400);
    c.lineTo(200,40);
    c.lineTo(300,40);
    c.lineTo(300,60);
    c.moveTo(340,100);
    c.stroke();
        //canvas

    for (let i=0;i<n;i++){
        l[i]='_ ';
    }
   
    const txtt =l.join(" ");
    document.getElementById('lines').innerHTML=txtt;}

function userinput(id, callback){
    var timer = setInterval(function(){
        if(document.getElementById(id)){
            clearInterval(timer);
            callback();
        }
    }, 100);
}

//loop/funx
function stuff(){
        if (['A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'].includes(y) ){
            
            clearInterval(inter);
            //begin();
        }
    }
const removekeyboardwin=()=>{
    const dispused=document.getElementById("used")
    dispused.innerHTML=''
    const buttonsgroup=document.getElementById("btn-group")
    buttonsgroup.innerHTML=' <p9 style="font-size=5em;">YOU WIN !!!</p9>';
}
const removekeyboardlose=()=>{
    const dispused=document.getElementById("used")
    dispused.innerHTML=''
    const buttonsgroup=document.getElementById("btn-group")
    buttonsgroup.innerHTML='<p10 style="font-size=5em;">YOU LOSE !!!</p10>';
}
const addLayout=()=>{
    const dispscr =document.getElementById("score")
    const disphighscr =document.getElementById("highscore")
    const buttonsgroup = document.getElementById("btn-group")
    disphighscr.innerHTML=''
    dispscr.innerHTML=''
    buttonsgroup.innerHTML=`
        <button id="q" class='alpha-div'>Q</button>
        <button id="w" class='alpha-div'>W</button>
        <button id="e" class='alpha-div'>E</button>
        <button id="r" class='alpha-div'>R</button>
        <button id="t" class='alpha-div'>T</button>
        <button id="y" class='alpha-div'>Y</button>
        <button id="u" class='alpha-div'>U</button>
        <button id="i" class='alpha-div'>I</button>
        <button id="o" class='alpha-div'>O</button>
        <button id="p" class='alpha-div'>P</button>
        <br></br>
        <button id="a" class='alpha-div'>A</button>
        <button id="s" class='alpha-div'>S</button>
        <button id="d" class='alpha-div'>D</button>
        <button id="f" class='alpha-div'>F</button>
        <button id="g" class='alpha-div'>G</button>
        <button id="h" class='alpha-div'>H</button>
        <button id="j" class='alpha-div'>J</button>
        <button id="k" class='alpha-div'>K</button>
        <button id="l" class='alpha-div'>L</button>
        <br></br>
        <button id="z" class='alpha-div'>Z</button>
        <button id="x" class='alpha-div'>X</button>
        <button id="c" class='alpha-div'>C</button>
        <button id="v" class='alpha-div'>V</button>
        <button id="b" class='alpha-div'>B</button>
        <button id="n" class='alpha-div'>N</button>
        <button id="m" class='alpha-div'>M</button>

        
    
    `
}
function start(){
    y=0;
    init()
    //let usedel=[];
    //let scr=0;
    addLayout()
    begin();

}
const updateY=(e)=>{
    let m=e.target.id;
    document.getElementById(m).style.backgroundColor='grey';
    document.getElementById(m).disabled=true;
    y=e.target.innerText;
    console.log(y)
    console.log(counter)
     rest()
    }

function begin(){
    //userinput("m",function(){
    const element=document.querySelectorAll(".alpha-div");
    
    element.forEach((x)=>x.addEventListener('click',updateY));
    var inter=setInterval(stuff,100);
   
}
    
    //userinput();
//let y='v';
//let y=prompt("please enter your letter in lowercase");

function rest(){
let chek=0;
//console.log(counter);
console.log(x);
for (i=0;i<n;i++){
    if (x[i]==y){
        l[i]=y; 
        chek++; 
        crt++;
    }
}
const txtX=x.join(" ");
const txtL=l.join(" ");
if(chek==0){
    counter++;
    }
switch (counter){
    case 1:
        c.arc(300,100,40,0,Math.PI*2);
        break;
    case 2:
        c.moveTo(300,140);
        c.lineTo(300,250);
        break;
    case 3:
        c.moveTo(300,170);
        c.lineTo(225,255);
        break;
    case 4:
        c.moveTo(300,170);
        c.lineTo(375,255);
        break;
    case 5:
        c.moveTo(300,250);
        c.lineTo(250,375);
        break;
    case 6:
        c.moveTo(300,250);
        c.lineTo(350,375);
        break;

}
c.stroke();
if(counter==6){
        removekeyboardlose();
        //alert("3 lives up. ggwp!!!");
        throw("ggwp bai !!!");
    }
let scr=crt +(6 -counter)*2;
if(counter!=6){
    usedel.push(y);
    const txt3=usedel.join(", ");
    document.getElementById('used').innerHTML="USED LETTERS: \n"+txt3;
    console.log(l);
    const txt2=l.join(" ");
    document.getElementById('lines').innerHTML=txt2;
    console.log(counter);
    
    if (txtX==txtL){
    //alert("YOU WIN");
    scores.push(scr);
    //localStorage.setItem("highscore",0);
    let hiscr=localStorage.getItem("highscore");
    if (hiscr<scr){
       localStorage.setItem("highscore",scr); 
    }
    removekeyboardwin();
    document.getElementById('score').innerHTML="SCORE :" + (crt +(6 -counter)*2) ;
    document.getElementById('highscore').innerHTML="HIGHSCORE :" + localStorage.getItem("highscore") ;
    //alert("you win.")
    throw("ggwp bai !!!");
}
    begin();
    //setTimeout(begin,3000);
}

}



