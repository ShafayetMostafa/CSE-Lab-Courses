#include <stdio.h>

int main() {
    int num, count = 0;

    printf("Enter a number: ");
    scanf("%d", &num);

    if (num < 0) {
        num = -num;
    }

    do {
        count++;
        num /= 10;
    } while (num > 0);


    printf("Number of digits: %d\n", count);

    return 0;
}
