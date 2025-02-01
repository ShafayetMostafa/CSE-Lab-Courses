#include<stdio.h>
int main()
{
    int a;
    printf("Enter the number of your choice: ");
    scanf("%d",&a);

    switch(a>0)
    {
    case 1:
        printf("The number %d is positive",a);
        break;
    case 0:
        switch(a<0)
        {
        case 1:
            printf("The number %d is negative",a);
            break;
        case 0:
            printf("The number %d is zero",a);
            break;
        }
    }
return 0;
}
