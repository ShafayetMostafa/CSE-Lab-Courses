///04324205101011

let string1=prompt("Enter a string:");
function countWords(str) {
  return str.trim().split(/\s+/).length;
}

console.log(countWords(string1));
