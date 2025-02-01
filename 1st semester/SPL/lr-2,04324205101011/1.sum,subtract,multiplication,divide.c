#include<stdio.h>
float main()
{
    float a,b,c,d;
    printf("\nPlease enter first value: ");
    scanf("%f",&a);
    printf("\nPlease enter second value: ");
    scanf("%f",&b);
    printf("\nPlease enter second value: ");
    scanf("%f",&c);
    d=a+b+c;
    printf("Addition: %f",d);
    d=c-b-a;
    printf("\nSubtraction: %f",d);
    d=a*b*c;
    printf("\nMultiplication: %f",d);
    d=a/b;
    printf("\nDivision: %f",d);

    return 0;
    }
