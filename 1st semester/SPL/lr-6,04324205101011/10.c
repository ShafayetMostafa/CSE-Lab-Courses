
#include <stdio.h>

int main() {
    int num, product = 1, digit;

    printf("Enter a number: ");
    scanf("%d", &num);

    if (num < 0) {
        num = -num;
    }

    if (num == 0) {
        product = 0;
    } else {

        while (num > 0) {
            digit = num % 10;
            product *= digit;
            num /= 10;
        }
    }

    printf("Product of digits: %d\n", product);

    return 0;
}
