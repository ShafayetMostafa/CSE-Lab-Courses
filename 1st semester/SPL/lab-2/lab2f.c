#include<stdio.h>
float main()
{
    float subject1,subject2,subject3,total,average,percentage;
    printf("Enter the value of subject1: ");
    scanf("%f",&subject1);
    printf("Enter the value of subject2: ");
    scanf("%f",&subject2);
    printf("Enter the value of subject3: ");
    scanf("%f",&subject3);
    total=subject1+subject2+subject3;
    printf("Total: %f",total);
    average=(subject1+subject2+subject3)/3;
    printf("\nAverage: %f",average);
    percentage=(total/300)*100;
    printf("\nPercentage of 3 subject: %f",percentage);

    return 0;

}
