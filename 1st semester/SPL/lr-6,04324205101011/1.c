#include<stdio.h>
int main()
{
    int n;
    printf("Take n number to start: ");
    scanf("%d",&n);
    for(int i=n;i>=1;i--)
    {
        printf("%d\n",i);
    }
}
