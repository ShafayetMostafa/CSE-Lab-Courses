// Write a program to input angles of a triangle and check whether triangle is valid or not...

#include<stdio.h>
int main()
{
    float angle1,angle2,angle3,triangle=180;
    printf("Enter the three angles of a triangle: ");
    scanf("%f%f%f",&angle1,&angle2,&angle3);

    if((angle1+angle2+angle3)==triangle)
    {
        printf("The triangle is valid");
    }
    else
    {
        printf("The triangle is not valid check angles");
    }
    return 0;
}
