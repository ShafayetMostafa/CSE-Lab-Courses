#include<stdio.h>
int main()
{
    int a,b;
    printf("Enter two number of your choice: ");
    scanf("%d%d",&a,&b);
    switch(a>b)
    {
    case 0:
        printf("%d is maximum than %d",b,a);
        break;
    case 1:
        printf("%d is maximum than %d",a,b);
        break;
    }
    return 0;

}
