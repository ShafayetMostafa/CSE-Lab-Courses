#include<stdio.h>
int main()
{
    int a=10,b=20,c=30,d;
    d=b-a+c;
    printf("Sum/Substract of 3 fixed values\n");
    printf("%d-%d+%d=%d",b,a,c,d);
    //d=b*a*c;
    //printf("Multiply\n");
    //printf("%d*%d*%d=%d",b,a,c,d);
    //d=c/a;
    //printf("Divide\n");
    //printf("%d/%d=%d",c,a,d);
    return 0;
}
