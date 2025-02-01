#include<stdio.h>
float main()
{
    float radius,diameter,circum,area;
    printf("Enter the value of radius: ");
    scanf("%f",&radius);
    diameter=radius*2;
    printf("Diameter of circle: %f",diameter);
    circum=2*3.1416*radius;
    printf("\nCircumference of circle: %f",circum);
    area=3.1416*radius*radius;
    printf("\nArea of circle: %f",area);
    return 0;
}

