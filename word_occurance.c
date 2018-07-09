#include<stdio.h>
#include<string.h>
int count(char *c , int l , char *w)
{
    int flag=0,ctr=0,i;
    while(*c!='\0')
    {
        if(*c==*w)
           {
               flag++;
                for(i=1;i<l;i++)
                {
                    if(*(c+i)==*(w+i))
                       flag++;
                    else
                        break;
                }
                if(flag==l)
                {
                    *c+=l;
                    ctr++;
                }
                else
                    *c++;
                flag=0;
           }
        else
            *c++;

    }
    return ctr;
}
int main()
{
    int ans, len;
    char word[100] , s[1000];
    printf("\nThe word is:- ");
    scanf("%s",word);
    fflush(stdin);
    printf("\nThe sentence is:- ");
    gets(s);

    len = strlen(word);
    ans = count(s , len , word);
    //fflush(stdin);
    printf("\n The word repeats by %d times",ans);

}
