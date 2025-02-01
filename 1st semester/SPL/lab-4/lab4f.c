#include<stdio.h>
int main()
{
    char ch;
    printf("Please enter alphabet/non alphabet: ");
    scanf("%c",&ch);
    if(('A' <= ch && ch<='Z') || ( 'a' <= ch && ch<='z'))
    {
        printf("The given character is an Alphabet");
    }
    else
    {
        printf("The given character is not Alphabet");
    }
    return 0;
}
