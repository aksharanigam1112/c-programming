#include<stdio.h>
#include<math.h>
static int i=0;
long D2B(int num)
{
    int rem;
    if(num==0)
        return 0;
    rem = num%2;
    return (rem*(pow(10,i++))+D2B(num/2));
}

int main()
{
    int n;
    long ans;
    printf("\n Enter a no:- ");
    scanf("\n%d",&n);
    ans = D2B(n);
    printf("The Binary equivalent of the given no %d is %d",n,ans);

}
