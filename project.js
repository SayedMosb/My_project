let textEL = document.getElementById('text');
let  addbtn = document.getElementById('addbtn');

addbtn.addEventListener('click', speakText);
function speakText() {
    
    let  text = textEL.value;
    let  speech = new SpeechSynthesisUtterance(text);
    window.speechSynthesis.speak(speech);
}