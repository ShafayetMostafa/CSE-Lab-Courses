#include<stdio.h>
int main()
{
    int hard,t_strength;
    float carbon;
    printf("Enter Hardness level: ");
    scanf("%d",&hard);
    printf("Enter strenth level: ");
    scanf("%d",&t_strength);
    getchar();
    printf("Enter carbon level: ");
    scanf("%f",&carbon);

    if(hard>50 && carbon<0.7 && t_strength>5600)
    {
        printf("Grade 10.\n");
    }
    else if(hard>50 && carbon<0.7)
    {
        printf("Grade 9.\n");
    }
    else if()
}