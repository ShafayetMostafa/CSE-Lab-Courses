
#include<stdio.h>
int main()
{
    int length,breadth,area,perimeter;
    printf("Enter the value of length:");
    scanf("%d",&length);
    printf("Enter the value of breadth:");
    scanf("%d",&breadth);
    area=length*breadth;
    printf("Area: %d",area);
    perimeter=2*(length+breadth);
    printf("\nPerimeter: %d",perimeter);

    return 0;
}
