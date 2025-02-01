#include<stdio.h>
int main()
{
    int base,height,area;
    printf("Enter the value of base: ");
    scanf("%d",&base);
    printf("Enter the value of height: ");
    scanf("%d",&height);
    area=.5*base*height;
    printf("Area of triangle: %d",area);
    return 0;
}
