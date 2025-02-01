#include<stdio.h>
int main()
{
    int length=5,breadth=4,area,perimeter;
    area=length*breadth;
    printf("Area: %d*%d=%d",length,breadth,area);
    perimeter=(length+breadth)*2;
    printf("\nPerimeter: (%d+%d)*2=%d",length,breadth,perimeter);

    if(area>perimeter)
    {
        printf("\nArea of the rectangle with length = 5 and breadth = 4 is greater than its perimeter.");
    }
    else
    {
        printf("\nPerimeter of the rectangle with length = 5 and breadth = 4 is greater than its area.");
    }
}
