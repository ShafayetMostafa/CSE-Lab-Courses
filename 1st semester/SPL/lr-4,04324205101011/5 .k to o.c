#include<stdio.h>
int main()
{
    char alph;
    printf("Enter the alphabet: ");
    scanf("%c",&alph);

    if(alph>='k' && alph<='o')
    {
        printf("The alphabet %c is in between k and o",alph);
    }
    else
    {
        printf("The alphabet %c isn't between k and o",alph);
    }
    return 0;
}
