#include<stdio.h>
float main()
{
    float a,Area;
    printf("Enter the value of a: ");
    scanf("%f",&a);
    Area=(sqrt(3)/4)*a*a;
    printf("The area of equilateral triangle: %f",Area);
    return 0;
}
