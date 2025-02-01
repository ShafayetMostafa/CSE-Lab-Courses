#include<stdio.h>
int main()
{
    int Celsius=25,Fahrenheit;
    Fahrenheit=(Celsius*9/5)+32;
    printf("Converting 25 degree Celsius into Fahrenheit\n");
    printf("25degree C:(%d*9/5)+32=%d F",Celsius,Fahrenheit);
    return 0;
}
