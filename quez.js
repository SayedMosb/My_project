document.write("Entering the loop!<br /> ");
outerloop: // This is the label name
for (var i = 0; i < 3; i++)
{
document.write("Outerloop: " + i + "<br />");
for (var j = 0; j < 5; j++)
{
if (j == 3){
continue outerloop;
}
document.write("Innerloop: " + j + "<br />");
}
}
document.write("Exiting the loop!<br /> ");