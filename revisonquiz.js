let addbtn=document.getElementById("addbtn");
let h1=document.getElementsByTagName("h1")[0];
let one=document.getElementById("one");
addbtn.addEventListener('click',function(){
    if(one.value =="search"){
let inputsearch=document.createElement("input");
inputsearch.type="text";
document.body.appendChild(inputsearch);

let buttomSearch=document.createElement("button");
buttomSearch.innerHTML="search";
document.body.appendChild(buttomSearch);

buttomSearch.addEventListener('click',function(){
    let h2=document.createElement("h2");
    document.body.appendChild(h2);

let textSearch=inputsearch.value.toLowerCase().trim();
let texth1=h1.innerText;
if(texth1.includes(textSearch)){
   
h2.innerHTML=texth1.indexOf(textSearch);
}else{
    h2.innerHTML="-1";
}
});
}else if(one.value =="substring"){
    let inputsubstr=document.createElement("input");
    inputsubstr.type="text";
    document.body.appendChild(inputsubstr);
    let inputsuubstrend=document.createElement("input");
    inputsuubstrend.type="text";
    document.body.appendChild(inputsuubstrend);

    let buutomsubstr=document.createElement("button");
    buutomsubstr.innerHTML="substr";
    document.body.appendChild(buutomsubstr);
    
    buutomsubstr.addEventListener('click',function(){
        let h3=document.createElement("h3");
        document.body.appendChild(h3);
        let start=parseInt(inputsubstr.value.trim());
        let end=parseInt(inputsuubstrend.value.trim());
        let texth1=h1.innerText;
        h3.innerHTML = texth1.substring(start, end);

    });


}else if(one.value =="replace"){
    let inputreplacestart=document.createElement("input");
    let inputreplaceend=document.createElement("input");
    document.body.appendChild(inputreplacestart);
    document.body.appendChild(inputreplaceend);

    let buutomReplace=document.createElement("button");
    buutomReplace.innerHTML="replace";
    document.body.appendChild(buutomReplace);


    buutomReplace.addEventListener('click',function (){
        let h2=document.createElement("h2");
        document.body.appendChild(h2);

        let inputreplacestarttext =inputreplacestart.value.trim().toLowerCase();
        let inputreplaceendtext=inputreplaceend.value.trim().toUpperCase();
        let texth11=h1.innerText;
        
       let textrep= texth11.replace(inputreplacestarttext,inputreplaceendtext);
        h2.innerHTML=textrep;

    });
}else{
    let inputSplit=document.createElement("input");
    document.body.appendChild(inputSplit);
    let buttomSplit=document.createElement("button");
    buttomSplit.innerHTML="Split";
    document.body.appendChild(buttomSplit);
    buttomSplit.addEventListener('click',function(){
        let h4=document.createElement("h4");
        document.body.appendChild(h4);
    let texttt=inputSplit.value.trim();
    let part=texttt.replaceAll('#',',');
    // let partjoin=part.join(',')
    
    h4.innerHTML=part+":length "+part.length;

    });

}
});