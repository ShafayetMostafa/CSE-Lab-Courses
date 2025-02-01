//SIMPLE CALCULATOR

#include<stdio.h>
int main()
{
    char op;
    float n1,n2,result;

    printf("Enter first number: ");
    scanf("%f",&n1);
    printf("Enter second number: ");
    scanf("%f",&n2);
    printf("Choose a operator (+,-,*,/): ");
    scanf(" %c",&op);

    switch(op)
    {
        case '+':
        result=n1+n2;
        printf("%.4f %c %.4f = %.4f",n1,op,n2,result);
        break;
        case '-':
        result=n1-n2;
        printf("%.4f %c %.4f = %.4f",n1,op,n2,result);
        break;
        case '*':
        result=n1*n2;
        printf("%.4f %c %.4f = %.4f",n1,op,n2,result);
        break;
        case '/':
        result=n1/n2;
        printf("%.4f %c %.4f = %.4f",n1,op,n2,result);
        break;
        default:
        printf("Invalid operator  used");
        break;
    }

}
