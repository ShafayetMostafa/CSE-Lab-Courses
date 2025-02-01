#include<stdio.h>
float main()
{
    float tsp,tp,cp;
    printf("Enter total selling price: ");
    scanf("%f",&tsp);
    printf("Enter total profit: ");
    scanf("%f",&tp);
    cp=(tsp-tp)/15;
    printf("Cost price of one item: %f",cp);
    return 0;
}
