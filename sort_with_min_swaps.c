#include<stdio.h>
void sort(int *p  , int len)
{
    int i,j  , t ,ctr=0;
    for(i=0;i<len ; i++)
    {
        for(j=i+1;j<len ; j++)
        {
            if(*(p+j)< *(p+i))
            {
                t = *(p+i);
                *(p+i) = *(p+j);
                *(p+j) = t;
                ctr++;
            }
        }
    }
    printf("\n");
    for(i=0;i<len;i++)
    {
        printf("%d ",*(p+i));
    }
    printf("\n The swapping occurs %d times ",ctr);
}
int main()
{
    int arr[10] ,i , n;
    printf("\n Enter the size of the array:- ");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        printf("\nEnter a no:- ");
        scanf("%d",&arr[i]);
    }
    sort(arr , n);

}
