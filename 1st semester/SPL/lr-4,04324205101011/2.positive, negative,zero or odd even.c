#include<stdio.h>
int main()
{
    int num;
    printf("Enter the number: ");
    scanf("%d",&num);

    if(num<0)
    {
        printf("The given number is negative");
    }
    else if(num>0)
    {
        printf("The given number is positive");
    }
    else
    {
        printf("The given number is zero");
    }
    if(num%2==0)
    {
        printf("\nand the number is even");
    }
    else
    {
        printf("\nand the number is odd");
    }
    return 0;
}
