#include<stdio.h>
int main()
{
    int Ram,Shyam,Ajay;
    printf("Enter the age of Ram: ");
    scanf("%d",&Ram);
    printf("Enter the age of Shyam: ");
    scanf("%d",&Shyam);
    printf("Enter the age of Ajay: ");
    scanf("%d",&Ajay);
    if(Ram>Shyam && Ajay>Shyam)
        printf("Shyam is youngest");
    else if(Shyam>Ram && Ajay>Ram)
        printf("Ram is youngest");
    else if(Shyam>Ajay && Ram>Ajay)
        printf("Ajay is youngest");
    else
        printf("There is a tie in ages");
    return 0;
}
