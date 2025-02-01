#include<stdio.h>
int main()
{
    char ch;
    printf("Enter the letter: ");
    scanf("%c",&ch);
    if(ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u' ||
       ch=='A' || ch=='E' || ch=='I' || ch=='E' || ch=='U')
    {
        printf("The character %c is a vowel.",ch);
    }
    else if((ch>='a' && ch<='z') || (ch>='A' && ch<='Z'))
    {
        printf("The character %c is a consonant",ch);
    }
    else
    {
        printf("The character %c is a invalid character",ch);
    }
    return 0;
}
