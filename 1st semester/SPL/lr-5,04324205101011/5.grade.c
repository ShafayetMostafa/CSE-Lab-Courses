#include<stdio.h>
int main()
{   float s1,s2,s3,s4,s5,total,percent;
    printf("Enter the marks obtained in 5 subs: ");
    scanf("%f%f%f%f%f",&s1,&s2,&s3,&s4,&s5);
    total=s1+s2+s3+s4+s5;
    printf("Total marks obtained in 5subs: %.2f\n",total);
    percent=(total/500)*100;
    printf("In percentage: %.2f",percent);printf("%%\n");
    if((s1>0&&s2>0&&s3>0&&s4>0&&s5>0) && (s1<101&&s2<101&&s3<101&&s4<101&&s5<101))
    {
        if(percent>=60 && percent<=100)
        {
            printf("First division");
        }
        else if(percent>=50 && percent<=59)
        {
            printf("Second division");
        }
        else if(percent>=40 && percent<=49)
        {
            printf("Third division");
        }
        else
        {
            printf("Fail");
        }
    }
    else {printf("Invalid");}
}
