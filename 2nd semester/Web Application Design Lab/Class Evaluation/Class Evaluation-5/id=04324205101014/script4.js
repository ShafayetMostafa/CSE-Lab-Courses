///04324205101011

function sumEvenOdd(start, end, isEven = true) {
  let sum = 0;
  for (let i = start; i <= end; i++) {
    if (isEven && i % 2 === 0) sum += i;
    if (!isEven && i % 2 !== 0) sum += i;
  }
  return sum;
}

console.log("Sum of even numbers:", sumEvenOdd(1, 10, true));
console.log("Sum of odd numbers:", sumEvenOdd(1, 10, false));