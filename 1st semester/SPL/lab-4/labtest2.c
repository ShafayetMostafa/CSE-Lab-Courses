//Write a program to take marks of 3 subject and calculate grades according to the following

#include<stdio.h>
int main()
{
    int sub1,sub2,sub3,avg;
    printf("Enter the marks of 3 subjects: ");
    scanf("%d%d%d",&sub1,&sub2,&sub3);
    avg=(sub1+sub2+sub3)/3;
    if(avg>100)
    {
        printf("Not valid");
    }
    else if (avg>=80)
    {
        printf("Grade A+");
    }
    else if (avg>=75)
    {
        printf("Grade A");
    }
    else if (avg>=70)
    {
        printf("Grade A-");
    }
    else if (avg>=65)
    {
        printf("Grade B+");
    }
    else if (avg>=60)
    {
        printf("Grade B");
    }
    else if (avg>=55)
    {
        printf("Grade B-");
    }
    else if (avg>=45)
    {
        printf("Grade C");
    }
    else if (avg>=40)
    {
        printf("Grade D");
    }
    else if (avg<40)
    {
        printf("Grade F");
    }
    else
    {
        printf("Not valid");
    }
    return 0;
}
