#include<stdio.h>
float main()
{
    float Celsius,Fahrenheit;
    printf("Enter the value of Celsius: ");
    scanf("%f",&Celsius);
    Fahrenheit=(Celsius*9/5)+32;
    printf("Converting celsius into Fahrenheit: %f F",Fahrenheit);
    return 0;
}
