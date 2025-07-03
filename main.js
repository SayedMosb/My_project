// document.write('hello world');
// let fisrt ="hello world";
// let scond ="sayed";
// console.log(fisrt+" "+scond);
// console.log(`${fisrt} ${scond}`);
// console.log(10/2);

// let a ="10";
// let b =20;
// console.log(a+b);
// let d =10;
// d +=20; // d =d +20 = 10+20=30
// d +=30;// d = 30 +30=60;

// d += 40;// d =60+40 =100;
// console.log(d);
// let x ="-100";
// let e ="20";
// let f="20";
// let g =true;

// console.log(-x * +e);//200
// console.log(-x * +e + +g);//100*20 +1=2001
// console.log(-d + +e +f + +e + +true 
//     + +true + +true
// );

// // 100 + 20 +"20"+20+1+1+1 =
// document.querySelector("h1").style.color='red';





// let a =100;
// let b =200.5;
// let c =1e2;
// let d =2.4;

// document.write(Math.round(Math.max(a,b,c,d)));
// console.log("hello world");
// let muy = ["ahmed", 2, 5, 5, 8, "mezero", "elham", "osama", "gamal", "ameer"];
// let anly = ["green", "yellow", "white"];

// for (let i = 0; i < muy.length; i++) {
//     document.write(`<div>`);
//     document.write(`<h1>[${i + 1}]: ${muy[i]}</h1>`);

//     for (let j = 0; j < anly.length; j++) {
//         document.write(`<p>[${j + 1}]: ${anly[j]}</p>`);
//     }

//     document.write(`</div>`);
// }

///challenge of using ternary operator
// function showDetails(name,age,bool){
//     document.write(`<div>`);
//     let result = typeof name == 'string' && typeof age=='number' &&
//         typeof bool=='boolean'?`<div><h1>hello ${name} your age is ${age} and your available for</h1><div>`:
//         typeof name=='number'&&typeof age=='string'&&typeof bool=='boolean'?
//         `<div><h1>hello ${age} your age is ${name} and your available for<h1></div>`:
//         typeof name=='boolean' && typeof age=='number'&&typeof bool=='string'?
//         `<div><h1>hello ${bool} your age is ${age} and your available for</h1></div>`:`<div><h1>hello ${age} your age is ${bool} and your not available for</h1></div>`;
//         document.write(`</div>`);
//         document.write(result);
    

// }


// showDetails("osama",39,true);

// showDetails(39,"osama",true);
// showDetails(true,39,"osama");
// showDetails(false,"osama",39);
// document.write("hello world");


// let p = [10,20,30,40,50,60,];
// let print =p.map(function(ele,index,arr){
//     document.write(`<div><h1>the current of element is ${ele}</h1></div>`);
//     document.write(`<div><h1>the current of idex is ${index}</h1></div>`);
//     document.write(`<div><h1>the current of array is ${arr}</h1></div>`);

// })
// console.log(print)
// let pr =["a","@","l","@","s","@","y","@","E","@","d"];

// let print = pr.filter(function(ele){
//     return ele !=="@";
// }).reduce(function(element,current){
//     return `${element} ${current}`;
// });

// console.log(print);
// let print ={
//     name:"sayed",
//     age:20,
//     sale:"hello",
//     names:{
//         hello:20,
//     }
// }
// console.log(print.name);
// console.log(print.names.hello);

// console.log(this);
// console.log(this == window);
// myvar=100;
// console.log(window.myvar);

// function fas(){
//     console.log(this);
//     return this;
// }
// fas();
// console.log(fas()===window);

// let print = document.getElementsByTagName("p");
// console.log(print[1]); 
// print[0].innerHTML = "test"; 

// let print = document.getElementsByClassName("my_span");
// console.log(print); 

// let print=document.querySelector(".my_span");
// console.log(print);
// console.log(document.forms[0]);
// console.log(document.forms[1]);
// document.forms[0].two.hello = "world";
// // console.log(document.forms[0].two.hello);
// let doc=document.querySelector(".js");
// console.log(doc);
// console.log(doc.textContent);
// console.log(doc.textContent);
// doc.innerHTML="text_form<span><h1>main.js</h1></span>";// تغيير المحتوي نفسه
// doc.textContent="text_form<span><h1>main.js</h1></span>";// تغيير ال attribute
// console.log(doc.innerHTML);
// console.log(doc.textContent);
// document.images[0].src = "images.jpeg";
// document.images[0].title="this is pictures";
// document.images[0].alt="this is pictures";
// document.images[0].width = 150;
// document.links[0].href="https://www.google.com";
// document.links[0].textContent="hello world";
// console.log(doc.getAttribute("class"));
// let print = document.getElementById("p");

// if (print && print.hasAttribute("data-src")) {
//     print.removeAttribute("data-src");
// } else {
//     console.log("not found");
// }

// let mydiv = document.createElement("div");
// console.log(mydiv);
// mydiv.className="product";
// let myh1 = document.createElement("h1");
// mydiv.append(myh1);
// myh1.textContent="hello world";
// document.body.appendChild(mydiv);
// let myin = document.createElement("div");
// myin.className = "one";

// let name = ["ahmed", "mohamed", "sayed", "mahmoud", "yousef"];
// let color = ["red", "green", "yellow"]; 

// for (let i = 0; i < name.length; i++) {
//     let nameDiv = document.createElement("div"); 
//     let myh = document.createElement("h1"); 
//     myh.textContent = `Name [${i + 1}]: ${name[i]}`;
//     nameDiv.appendChild(myh);

//     for (let j = 0; j < color.length; j++) {
//         let colorSpan = document.createElement("span"); 
//         colorSpan.textContent = ` ${color[j]}`;
//         nameDiv.appendChild(colorSpan); 
//     }
    
//     myin.appendChijosnesld(nameDiv); 
// }

// document.body.append(myin); 
// let mydiv=document.createElement("div");
// let myh1=document.createElement("h1");
// let myp=document.createElement("p");
// mydiv.append(myh1);
// mydiv.append(myp);
// mydiv.className="one";
// myh1.textContent="hello my name josnes";
// myp.textContent="hello world";
// document.body.append(mydiv);
//  
// let userinput = document.querySelector("[name='username']");
// let ageinput = document.querySelector("[name='age']");

// document.forms[0].onsubmit = function (e) {
//     let uservalid = false;
//     let agevalid = false;

//     // Validate username (non-empty and <= 10 characters)
//     if (userinput.value.trim() !== "" && userinput.value.trim().length <= 10) {
//         uservalid = true;
//     }

//     // Validate age (non-empty and numeric)
//     if (ageinput.value.trim() !== "" && !isNaN(ageinput.value.trim()) && ageinput.value.trim() > 0) {
//         agevalid = true;
//     }

//     // Prevent submission if validation fails
//     if (!uservalid || !agevalid) {
//         e.preventDefault(); // Correct spelling
//         alert("Please provide a valid username and age.");
//     }
// };

// document.links[0].onclick = function (event) {
//     console.log(event);
//     event.preventDefault(); // Correct spelling
//     alert("Link click prevented!");
// };


// let two=document.querySelector(".two");

// window.onload=function(){
//     two.focus();
// }

// let one = document.querySelector("#one"); // Replace #one with the correct selector for your element

// one.onblur = function () {
//     document.links[0].click(); // Triggers the first link's click event
// // };
// let element = document.querySelector("#my_div");
// // console.log(element.classList);
// // console.log(typeof element.classList);
// // console.log(element.classList.length);
// // console.log(element.classList.contains("one"));
// // console.log(element.classList.item("0"));


// console.log("%cElzero",`color: blue;
// font-size: 80px;
// font-weight: bold;
// text-align: center;
// font-family: Arial`);

// console.log("%cElzero %cWep %cSchool","font-size:40px;color:red;","font-size:40px;color:green"," color : white;font-size:40px;background-color:blue;");
// console.group("Group 1");
// console.log("Message One");
// console.log("Message Two");

// console.group("Child Group");
// console.log("Message One");
// console.log("Message Two");

// console.group("Grand Child Group");
// console.log("Message One");
// console.log("Message Two");
// console.groupEnd(); // Ends "Grand Child Group"

// console.groupEnd(); // Ends "Child Group"

// console.groupEnd(); // Ends "Group 1"

// console.group("Group 2");
// console.log("Message One");
// console.log("Message Two");
// console.groupEnd(); // Ends "Group 2"
// console.log(Number.MAX_SAFE_INTEGER);
// console.log(Number.MAX_SAFE_INTEGER.toString(2).length); // 16
// let myVar = 10.4;
// console.log(Math.round(myVar));
// console.log(Math.floor(myVar));
// console.log(Math.trunc(myVar));
// console.log(parseInt(myVar))
// console.log(Math.floor(Math.random() * 5)); // 0 || 1 || 2 || 3 || 4


// let a = 20;
// let b = 30;
// let c = 10;

// console.log(a < b && a > c || a != b); // true
// console.log(a <b && a > c); // true
// console.log((a != b) && !(a == b) && !(a < c) && (a > c)); // true
// Edit What You Want Here

// Edit What You Want Here

// let num1 = 20;
// let num2 = 10;
// let num3 = 10;
// let num4 = 10;
// if (num1 > num2) {
//   console.log("True");
// } else {
//   console.log("False");
// }
// if (num1 > num2 && num1 < num4) {
//   console.log("True");
// } else {
//   console.log("False");
// }
// if (num1 > num2 && num1 === num3) {
//   console.log("True");
// } else {
//   console.log("False");
// }
// if ((num1 + num2) < num4) {
//   console.log("True");
// } else {
//   console.log("False");
// }
// if ((num1 + num3) < num4) {
//   console.log("True");
// } else {
//   console.log("False");
// }
// if ((num1 + num2 + num3) < num4) {
//   console.log("True");
// } else {
//   console.log("False");
// }

// // Condition 7

// if (num4 - (num1 + num3) + num2 === 21) {
//   console.log("True");
// } else {
//   console.log("False");
// }

