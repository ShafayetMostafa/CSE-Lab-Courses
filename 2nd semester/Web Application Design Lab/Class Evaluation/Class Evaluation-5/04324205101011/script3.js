///04324205101011

let n=parseInt(prompt("Enter a number:"));

for(let i=1;i<=n;i++){
  let line = '';
  for(let j=1;j<=i;j++){
    line += j;
  }
  console.log(line);
}

let m=parseInt(prompt("Enter a number"));

for (let i=1; i<=m;i++){
  let pattern='';
  let count =1;
  for (let j = 1; j<=2*m; ++j){
    if(i+j>=m + 1 && (i >= j- m + 1)){
  pattern += count.toString() + ' ';
  count++;}
  else{
    pattern+= ' ';
  }
}
  console.log(pattern);
}