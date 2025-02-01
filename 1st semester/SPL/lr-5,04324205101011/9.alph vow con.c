#include<stdio.h>
int main()
{
    char alph;
    printf("Enter the alphabet of your choice: ");
    scanf("%c",&alph);

    switch(alph)
    {
    case 'a':case 'e':case 'i':case 'o':case 'u':
    case 'A':case 'E':case 'I':case 'O':case 'U':
        printf("VOWEL");
        break;
    default:
        if(alph>='a'&&alph<='z' || alph>='A'&&alph<='Z')
            printf("CONSONANT");
        else
            printf("%c isn't a alphabet",alph);
    }
    return 0;
}
