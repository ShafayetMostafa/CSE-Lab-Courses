#include <stdio.h>

int main() {
    int num, firstDigit, lastDigit, sum;

    printf("Enter a number: ");
    scanf("%d", &num);

    if (num < 0) {
        num = -num;
    }

    lastDigit = num % 10;

    firstDigit = num;
    while (firstDigit >= 10) {
        firstDigit /= 10;
    }

    sum = firstDigit + lastDigit;

    printf("Sum of first and last digit: %d\n", sum);

    return 0;
}
