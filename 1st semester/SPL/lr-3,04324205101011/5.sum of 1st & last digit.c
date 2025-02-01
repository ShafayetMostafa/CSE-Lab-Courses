#include<stdio.h>
int main()
{
    int num,sum,a,b,c,d;
    printf("Enter the 4 digit num: ");
    scanf("%d",&num);
    a=num%10;
    num=num/10;
    b=num%10;
    num=num/10;
    c=num%10;
    num=num/10;
    d=num%10;
    num=num/10;
    sum=a+d;
    printf("Sum of 1st and last digit: %d",sum);
    return 0;
}
