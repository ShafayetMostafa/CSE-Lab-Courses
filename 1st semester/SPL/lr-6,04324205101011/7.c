#include <stdio.h>

int main() {
    int num, firstdigit, lastdigit;
    printf("Enter a number: ");
    scanf("%d", &num);

    lastdigit = num % 10;

    firstdigit = num;
    while (firstdigit >= 10) {
        firstdigit /= 10;
    }

    printf("First digit: %d\n", firstdigit);
    printf("Last digit: %d\n", lastdigit);

    return 0;
}
