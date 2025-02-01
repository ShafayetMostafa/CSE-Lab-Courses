#include<stdio.h>
int main()
{
    int num,a,b,c,d,e;
    printf("Enter the 5 digit num: ");
    scanf("%d",&num);
    a=(num%10)+1;
    num=num/10;
    b=(num%10)+1;
    num=num/10;
    c=(num%10)+1;
    num=num/10;
    d=(num%10)+1;
    num=num/10;
    e=(num%10)+1;
    num=num/10;

    printf("Adding one to each digit: %d%d%d%d%d",e,d,c,b,a);
    return 0;
}
