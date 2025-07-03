let addbtn=document.getElementById("addbtn");
let one=document.getElementById("one");
let two=document.getElementById("two");


addbtn.addEventListener('click',search);
function search(){

    let onetext=one.value.toLowerCase().trim();
    let twotwxt=two.value.toLowerCase().trim();
let h1=document.createElement("h1");
document.body.appendChild(h1);
    if(onetext.includes(twotwxt)){
        h1.innerHTML=onetext.substring(twotwxt);

    }else{
        h1.innerHTML="-1";
    }


}

