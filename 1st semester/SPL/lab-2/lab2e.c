#include<stdio.h>
float main()
{
    float angle1,angle2,angle3;
    printf("Enter the value of angle1: ");
    scanf("%f",&angle1);
    printf("Enter the value of angle2: ");
    scanf("%f",&angle2);
    angle3=180-(angle1+angle2);
    printf("Third angle: %f",angle3);
    return 0;
}
