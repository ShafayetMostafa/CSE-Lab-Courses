#include <stdio.h>

int main() {
    int sum = 0;
    int term = 5;
    int commonDifference = 6;

    for (int i = 1; i <= 75; i++) {

        if (i % 2 != 0) {
            sum += term;
        } else {
            sum -= term;
        }

        term += commonDifference;
    }

    printf("Sum of the series 5 - 11 + 17 - ... up to 75 terms is: %d\n", sum);

    return 0;
}
