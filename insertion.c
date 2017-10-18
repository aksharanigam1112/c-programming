#include<stdio.h>
int main()
{   int i,n,a[25];
    printf("Enter The size \n");
    scanf("%d",&n);
    printf("enter elements");
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    printf("YOU ENTERED \n");
    for(i=0;i<n;i++)
    {
        printf("%d",a[i]);
    }
    int num;
    printf("Enterthe number to be isnerted");
    scanf("%d",&num);
    int pos;
    printf("Enter the position at which you want to add element....");
    scanf("%d",&pos);
    int index=pos-1;
    n=n+1;
    for(i=n-1;i>index;i--)
    {   a[i]=a[i-1];
    }
    a[index]=num;
    printf("New Array\n");
    for(i=0;i<n;i++)
    {
        printf("%d",a[i]);
    }
}


