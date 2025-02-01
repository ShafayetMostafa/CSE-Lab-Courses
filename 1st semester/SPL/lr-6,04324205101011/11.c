#include <stdio.h>
#include <math.h>

int main() {
    int num, firstDigit, lastDigit, swappedNum, numDigits, divisor, middlePart;

    printf("Enter a number: ");
    scanf("%d", &num);

    if (num >= 0 && num < 10 || num > -10 && num < 0) {
        printf("Swapped number: %d\n", num);
        return 0;
    }

    int isNegative = 0;
    if (num < 0) {
        isNegative = 1;
        num = -num;
    }

    lastDigit = num % 10;

    firstDigit = num;
    while (firstDigit >= 10) {
        firstDigit /= 10;
    }

    numDigits = (int)log10(num) + 1;
    divisor = pow(10, numDigits - 1);
    middlePart = num % divisor;
    middlePart /= 10;

    swappedNum = lastDigit * divisor + middlePart * 10 + firstDigit;

    if (isNegative) {
        swappedNum = -swappedNum;
    }

    printf("Swapped number: %d\n", swappedNum);

    return 0;
}
