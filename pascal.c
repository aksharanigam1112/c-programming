#include<stdio.h>
int fact(int);
int main()
{
    int line,i,j;

    printf("\n Enter the no. of lines: ");
    scanf("\n %d",&line);

    for(i=0;i<line;i++)
    {
         for(j=0;j<line-i-1;j++)
             printf(" ");

         for(j=0;j<=i;j++)
             printf("%2d ",fact(i)/(fact(j)*fact(i-j)));
         printf("\n");
    }
    return 0;
}

int fact(int num)
{
    int f=1;
    int i=1;
    while(i<=num)
    {
         f=f*i;
         i++;
  }
  return f;
 }
