#include<stdio.h>
int main()
{
    int number,sum,a,b,c;
    printf("Enter the 3digit number: ");
    scanf("%d",&number);
    a= number %10;
    number= number /10;
    b= number %10;
    number= number /10;
    c= number %10;
    number= number /10;
    sum=a+b+c;

    printf("Sum=%d",sum);
    return 0;
}
