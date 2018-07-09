#include<stdio.h>
int main()
{
    int i , j , sp,rows,k=0;
    char ch='A';
    printf("Enter the no of rows:- ");
    scanf("\n%d",&rows);
    for (i=0  ;i<rows ; i++)
    {
        ch='A';
        for(j=rows;j>i;j--)
        {
            printf("%c",ch);
            ch++;
        }
        for(sp=1 ;sp<=(i*2-1);sp++)
        {
            printf(" ");
        }
        ch--;
        if(sp==1)
        {
            ch--;
        }
        for( ;ch>='A';ch--)
        {
            printf("%c",ch);

        }

        printf("\n");
    }
    k=1;
        for (i=rows-1  ;i>=0 ; i--)
        {
        ch='A';

        for(j=1;j<=k;j++)
        {
            printf("%c",ch);
            ch++;
        }
        k++;
        for(sp=(i*2-1) ;sp>=1;sp--)
        {
            printf(" ");
        }

         if(k!=rows)
        {
            ch--;
        }
        for( ;ch>='A';ch--)
        {
            printf("%c",ch);
        }
        printf("\n");
    }
    return(0);
}
