#include<stdio.h>
#include<conio.h>
#include<math.h>
int binary(int);

int binary(int n)
    {
        int r,x=n,i=0;
       int b=0;
       while(x>0)
       {
           r=x%2;
           b=b+(r*pow(10,i));
           x=x/2;
           i++;
       }
       return b;
    }

int main()
{
    int c;
    int b;
    int n;
    printf("choose the option from the give:-\n");
    printf("1. to convert decimal to binary\n");
    printf("2. to convert decimal to octal\n");
    printf("3. to convert decimal to hexadecimal\n");
    printf("4. to convert binary to decimal\n");
    printf("5. to convert binary to octal\n");
    printf("6. to convert binary to hexadecimal\n");
    printf("7. to convert octal to decimal\n");
    printf("8. to convert octal to binary\n");
    printf("9. to convert octal to hexadecimal\n");
    printf("10. to convert hexadecimal to decimal\n");
    printf("11. to convert hexadecimal to binary\n");
    printf("12. to convert hexadecimal to octal\n");
    printf("\n Enter your choice:- ");
    scanf("%d\n",&c);



    switch(c)
    {


    case 1:
    {



            printf("\n enter the no. in decimal form ");

            scanf("\n%d",&n);
            b=binary(n);
            printf("binary is %d",b);
            break;

    }
   /* case 2:
        {
            long long o;
            printf("enter the no. in decimal form ");
            int n;
            scanf("%d",&n);
            o=octal(n);
            printf("octal is %ld",o);
            break;
        }
    case 3:
        {
            long long h1;
            printf("enter the no. in decimal form ");
            int n;
            scanf("%d",&n);
            h1=octal(n);
            printf("octal is %s",h1);
            break;
        }
    }*/
        }
    return 0;
}


