#include<stdio.h>
int main()
{
    int num,sum,a,b,c,d,e;
    printf("Enter the 5 digit number: ");
    scanf("%d",&num);
    a=num%10;
    num=num/10;
    b=num%10;
    num=num/10;
    c=num%10;
    num=num/10;
    d=num%10;
    num=num/10;
    e=num%10;
    num=num/10;
    sum=a+b+c+d+e;
    printf("The sum of each digit: %d",sum);
    return 0;
}
