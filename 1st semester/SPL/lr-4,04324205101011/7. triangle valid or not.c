#include<stdio.h>
int main()
{
    float angle1,angle2,angle3,triangle=180;
    printf("Enter 3 angles of the triangle: ");
    scanf("%f %f %f",&angle1,&angle2,&angle3);

    if((angle1+angle2+angle3)==triangle)
    {
        printf("The triangle is valid");
    }
    else
    {
        printf("The triangle isn't valid check angles");
    }
    return 0;

}
