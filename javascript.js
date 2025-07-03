/*
this is password

let h1 = document.createElement("h1");
let text = document.createTextNode("password :");
h1.appendChild(text);

let span = document.createElement("span");
h1.appendChild(span);
document.body.appendChild(h1);


let spa = document.getElementsByTagName("span")[0];

let x = confirm("Enter the password");
let ismo = false; 

for (let i = 1; i < 5; i++) {
    y=Number(prompt("try "+i));
    if (y === 123) {
        spa.innerText = "Valid";
        ismo = true;
        break;
    }
}

if (!ismo) {
    spa.innerHTML = "Not valid";
}
*/


// task tow
// tag=prompt("enter the tage name element you element to change its color");
// index =Number(prompt("enter the index of element"));
// color = prompt("enter the color");
// let hed =document.getElementsByTagName("h1"); 
// let par =document.getElementsByTagName("p"); 
// if(tag ==="h1"){
//     hed[index].style.color=color;

// }else{
//     par[index].style.color=color;

// }


 ////////////////////     question 3

// let para =document.createElement("h1");
// let text =document.createTextNode("paragraph");
// para.appendChild(text);
// document.body.appendChild(para);

// let par =document.getElementsByTagName("h1")[0];
// element = Number(prompt("chose one of three font (20 || 30 || 40"));
// sure =confirm("are you sure to choose font");

// if(sure=== true && element >=20 && element <=40){
    
//    par.style.fontSize=element+"px";
// }



// let p=document.createElement("p");
// let textp=document.createTextNode("my first wep bage");
// p.appendChild(textp);
// document.body.appendChild(p);

// let h1=document.createElement("h1");
// let texth1=document.createTextNode("heading 1");
//   h1.appendChild(texth1);
//   document.body.appendChild(h1);
 

// let h2=document.createElement("h2");
// let texth2=document.createTextNode("welcome to java script");

//   h1.appendChild(texth2);
//   document.body.appendChild(h2);


//   let loream=document.createElement("p");
// let textloream=document.createTextNode("loream ispsum dolor sit amet consectetur adipsicuing elit ");

// loream.appendChild(textloream);
//   document.body.appendChild(loream);

//   let loream1=document.createElement("p");
// let textloream1=document.createTextNode("loream ispsum dolor sit amet consectetur ahmed");

// loream.appendChild(textloream1);
//   document.body.appendChild(loream1);


//   let span=document.createElement("span");
//   let textspan=document.createTextNode("loream ispsum dolor sit amet consectetur adipsicuing elit ");
  
// span.appendChild(textspan);
//     document.body.appendChild(span);

  
// let p1=document.getElementsByTagName("p")[0];
// p1.style.backgroundColor="green";


// let h11=document.getElementsByTagName("h1")[0];
// h11.style.backgroundColor="blue";

// let h22=document.getElementsByTagName("h2")[0];
// h22.style.color="red";



// let lor=document.getElementsByTagName("p")[1];
// lor.style.color="green";

// let ah=document.createElement("h4");
// let tes=document.createTextNode("ahmed");
// ah.appendChild(tes);
// document.body.appendChild(ah);

// let ahp=document.getElementsByTagName("h4")[0];
// ahp.style.color="blue";

/*
  <h1>hello</h1>
    <p>welcome to javascript</p>
    <h2>hello 2</h2>
    <h3>hello 3</h3>
    <h4>hello 4</h4>
    <h5> hello 5</h5>


*/

let head=document.getElementsByTagName("h1")[0];
num =Number(prompt("enter the font 20 | 30 | 40"));
num2 =confirm("are you sure to applay");

if(num2==true && num >=20 && num <=40){
  head.style.fontSize=num+"px";
}else{
  num2=confirm("wrong answer");
}