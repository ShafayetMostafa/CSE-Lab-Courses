#include<stdio.h>
int main()
{
    char ch;
    printf("Enter the character: ");
    scanf("%c",&ch);

    if(ch>='A' && ch<='Z')
    {
        printf("The character %c is uppercase alphabet",ch);
    }
    else if(ch>='a' && ch<='z')
    {
        printf("The character %c is lowercase alphabet",ch);
    }
    else
    {
        printf("The character %c is not an alphabet",ch);
    }
    return 0;
}
