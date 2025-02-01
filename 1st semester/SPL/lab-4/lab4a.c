#include<stdio.h>
int main()
{
    int num;
    printf("Please enter a number: ");
    scanf("%d",&num);

    if(num %2 == 0)
    {
        printf("\n The given number is even");
    }
    else
    {
        printf("\n The given number is odd");
    }
    return 0;
}
