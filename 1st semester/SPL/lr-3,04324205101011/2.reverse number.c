#include<stdio.h>
int main()
{
    int num,a,b,c,d,e;
    printf("Enter the 5 digit num: ");
    scanf("%d",&num);
    a=(num%10);
    num=num/10;
    b=(num%10);
    num=num/10;
    c=(num%10);
    num=num/10;
    d=(num%10);
    num=num/10;
    e=(num%10);
    num=num/10;

    printf("The reverse number of 5 digit: %d%d%d%d%d",a,b,c,d,e);

    return 0;
}
