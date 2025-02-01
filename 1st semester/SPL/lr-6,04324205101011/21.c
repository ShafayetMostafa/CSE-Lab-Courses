#include <stdio.h>
long long factorial(int n) {
    long long fact = 1;
    for (int i = 1; i <= n; i++) {
        fact *= i;
    }
    return fact;
}

int main() {
    int N;
    double sum = 0.0;

    printf("Enter a positive integer N: ");
    scanf("%d", &N);

    for (int i = 1; i <= N; i++) {
        sum += (double)i / factorial(i);
    }

    printf("Sum of the series 1/1! + 2/2! + 3/3! + ... + %d/%d! is: %.6lf\n", N, N, sum);

    return 0;
}
