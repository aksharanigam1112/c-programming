#include<stdio.h>
#include<math.h>
static int i=0;
static char arr[100];
int H2D(int len)
{
    int h=0;
    if(len<0)
        return 0;

    if(arr[len]>='A'&& arr[len]<='F')
        h = (int)arr[len]-55;
    else
        h = arr[len]-48;

    return( H2D(--len)+h*pow(16,i--) );
}

int main()
{
    int l=0,ans=0;
    printf("\n Enter a Hexadecimal No:- ");
    gets(arr);
    l = strlen(arr);
    i= l-1;
    ans = H2D(--l);
    printf("\n The Decimal equivalent of the given no is:- %d",ans);
}
