#include<stdio.h>
float main()
{
    float Fahrenheit,Celsius;
    printf("Enter the value of Fahrenheit: ");
    scanf("%f",&Fahrenheit);
    Celsius=(Fahrenheit-32)*5/9;
    printf("Converting Fahrenheit into Celsius: %f C",Celsius);
    return 0;
}
