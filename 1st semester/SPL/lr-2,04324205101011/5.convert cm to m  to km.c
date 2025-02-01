#include<stdio.h>
float main()
{
    float cm,m,km;
    printf("Enter the value of cm: ");
    scanf("%f",&cm);
    m=cm/100;
    printf("Cm to M: %f m",m);
    km=cm/100000;
    printf("Cm to KM: %f km",km);
    return 0;
}
