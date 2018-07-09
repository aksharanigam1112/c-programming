#include<stdio.h>
#include<math.h>
void D2H(int num)
{
    int rem=0;
    if (num==0)
    {
       return ;
    }
    rem = num%16;
    if(rem>9)
    {
        rem+=55;
    }
    D2H(num/16);
    if(rem<9)
        printf("%d",rem);
    else
        printf("%c",(char)rem);
}
int main()
{
    int num,j;
    printf("\n Enter a decimal no:- ");
    scanf("\n %d",&num);
    printf("The equivalent hexadecimal form is:-\n");
    D2H(num);
}

