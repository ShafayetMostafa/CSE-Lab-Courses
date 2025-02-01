#include<stdio.h>
int main()
{
    int C,D,X;
    printf("Enter the value of C: ");
    scanf("%d",&C);
    printf("Enter the value of D: ");
    scanf("%d",&D);
    X=C;
    C=D;
    D=X;
    printf("Interchanging: C=%d,D=%d",C, D);
    return 0;
}
