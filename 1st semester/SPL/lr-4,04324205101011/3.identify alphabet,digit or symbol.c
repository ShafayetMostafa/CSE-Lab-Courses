#include<stdio.h>
int main()
{
    char ch;
    printf("Enter alphabet/non-alphabet/symbol: ");
    scanf("%c",&ch);

    if(('A'<=ch && ch<='Z') || ('a'<=ch && ch<='z'))
    {
        printf("The input is an alphabet");
    }
    else if('0'<=ch && ch<='9')
    {
        printf("The input is a digit/number");
    }
    else
    {
        printf("The input is a symbol");
    }
    return 0;
}
