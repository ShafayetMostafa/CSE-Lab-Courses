#include<stdio.h>
int main()
{
    int a=5,b,c;
    b=a++;
    c=--a;
    a=b--;
    printf("A=%d\n",a);
    printf("B=%d\n",b);
    printf("C=%d",c);

    return 0;
}
