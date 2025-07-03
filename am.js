let addbtn=document.getElementById("addbtn");
let text=document.getElementById("text");

addbtn.addEventListener('click',addSay);

function addSay(){
    let textt= text.value;
    let speech=new SpeechSynthesisUtterance(textt);
    window.speechSynthesis.speak(speech);
}