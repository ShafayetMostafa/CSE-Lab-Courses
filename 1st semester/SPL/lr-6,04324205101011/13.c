
#include <stdio.h>

int main() {
    int num, reversedNum = 0, remainder;

    printf("Enter a number: ");
    scanf("%d", &num);

    int isNegative = 0;
    if (num < 0) {
        isNegative = 1;
        num = -num;
    }

    while (num != 0) {
        remainder = num % 10;
        reversedNum = reversedNum * 10 + remainder;
        num /= 10;
    }

    if (isNegative) {
        reversedNum = -reversedNum;
    }

    printf("Reversed number: %d\n", reversedNum);

    return 0;
}
