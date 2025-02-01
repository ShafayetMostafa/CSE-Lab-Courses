#include<stdio.h>
float main()
{
    float sub1,sub2,sub3,sub4,sub5,total,average,percentage;
    printf("Enter the mark of 1st Subject: ");
    scanf("%f",&sub1);
    printf("Enter the mark of 2nd Subject: ");
    scanf("%f",&sub2);
    printf("Enter the mark of 3rd Subject: ");
    scanf("%f",&sub3);
    printf("Enter the mark of 4th Subject: ");
    scanf("%f",&sub4);
    printf("Enter the mark of 5th Subject: ");
    scanf("%f",&sub5);
    total=sub1+sub2+sub3+sub4+sub5;
    average=total/5;
    percentage=(total/500)*100;
    printf("Total: %f \nAverage: %f \nPercentage: %f",total,average,percentage);

    return 0;
}
