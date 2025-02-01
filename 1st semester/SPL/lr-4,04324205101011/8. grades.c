#include<stdio.h>
int main()
{
    float phy,chem,bio,maths,computer,totalmarks,percentage;
    printf("Enter mark of Physics: ");
    scanf("%f",&phy);
    printf("Enter mark of Chemistry: ");
    scanf("%f",&chem);
    printf("Enter mark of Biology: ");
    scanf("%f",&bio);
    printf("Enter mark of Mathematics: ");
    scanf("%f",&maths);
    printf("Enter mark of Computer: ");
    scanf("%f",&computer);
totalmarks=phy+chem+bio+maths+computer;
percentage=(totalmarks/500)*100;

if(phy>=0 && phy<=100 && chem>=0 && chem<=100 && bio>=0 && bio<=100 && maths>=0 && maths<=100 && computer>=0 && computer<=100)
{
    if(percentage>=90 && percentage<=100)
    {
        printf("Grade A");
    }
    else if(percentage>=80 && percentage<=89)
    {
        printf("Grade B");
    }
    else if(percentage>=70 && percentage<=79)
    {
        printf("Grade C");
    }
    else if(percentage>=60 && percentage<=69)
    {
        printf("Grade D");
    }
    else if(percentage>=40 && percentage<=59)
    {
        printf("Grade E");
    }
    else if(percentage>=0 && percentage<=39)
    {
        printf("Grade F");
    }
}
else
    {
        printf("Invalid");
    }
printf("\nPercentage: %f",percentage);
    return 0;
}
