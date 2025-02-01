#include<stdio.h>
 int main()
{
    char ms,sex;

    printf("You marital status?(M for married, U for unmarried): ");
    scanf(" %c",&ms);

    printf("Your gender?(M for Male, F for Female): ");
    scanf(" %c",&sex);
    int age;
    printf("Your age: ");
    scanf(" %d",&age);

    if(ms=='M' || (ms=='U' && ((sex=='M' && age>30) || (sex=='F' && age>25))))
    {
        printf("Insured");
    }
    else{
        printf("Not insured");
    }

    return 0;
}
