#include<stdio.h>
int main()
{
    int num1,num2,num3;
    printf("Enter the first number: ");
    scanf("%d",&num1);
    printf("Enter the second number: ");
    scanf("%d",&num2);
    printf("Enter the third number: ");
    scanf("%d",&num3);

    if(num1>num2 && num1>num3)
    {
        printf("The first number is greater than %d and %d",num2,num3);
    }
    else if(num2>num1 && num2>num3)
    {
        printf("The second number is greater than %d and %d",num1,num3);
    }
    else
    {
        printf("The third number is greater one among %d and %d \n",num1,num2);
    }
    if(num1<num2 && num1<num3)
    {
        printf("The first number is smaller than %d and %d",num2,num3);
    }
    else if(num2<num1 && num2<num3)
    {
        printf("The second number is smaller than %d and %d",num1,num3);
    }
    else
    {
        printf("The third number is the smallest one among %d and %d",num1,num2);
    }
    return 0;
}
