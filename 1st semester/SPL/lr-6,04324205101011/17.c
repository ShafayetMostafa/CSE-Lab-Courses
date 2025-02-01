#include <stdio.h>

int main() {
    int sum = 0;
    int term = 7;
    int commonDifference = 13;

    for (int i = 1; i <= 100; i++) {
        sum += term;
        term += commonDifference;
    }

    printf("Sum of the series 7 + 20 + 33 + ... up to 100 terms is: %d\n", sum);

    return 0;
}
