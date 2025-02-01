#include<stdio.h>
int main()
{
    float km,m,ft,in,cm;
    printf("Converting distance in KM to M,CM,In,Ft \n");
    printf("Enter the distance between two cities in km: ");
    scanf("%f",&km);
    m=km*1000; cm=m*100; in=39370.0787*km; ft=in/12;
    printf("M=%f \nCM=%f \nIn=%f \nFt=%f",m,cm,in,ft);
    return 0;
}
