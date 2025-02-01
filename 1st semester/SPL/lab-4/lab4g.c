#include<stdio.h>
int main()
{
    char ch;
    printf("Enter an alphabet: ");
    scanf("%c",&ch);
    if('a'<=ch && ch<='z')
    {
        printf("The given character is lower case Alphabet");
    }
    else if('A'<=ch && ch<='Z')
    {
        printf("The given character is upper case Alphabet");
    }
    else
    {
        printf("The given character is not an alphabet");
    }
    return 0;
}
