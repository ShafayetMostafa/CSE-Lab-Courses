
#include <stdio.h>

int main() {
    int num;

    printf("Enter a number: ");
    scanf("%d", &num);

    if (num < 0) {
        printf("Factors of %d are the same as those of %d:\n", num, -num);
        num = -num;
    }

    printf("Factors of %d are:\n", num);
    for (int i = 1; i <= num; i++) {
        if (num % i == 0) {
            printf("%d ", i);
        }
    }
    printf("\n");
    return 0;
}
