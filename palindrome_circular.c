#include<stdio.h>
#include<stdlib.h>
#define max = 10;
char arr[max];
int front = rear = -1;
void insert(char ch)
{
    if(rear == max-1)
        printf("\nOverflow");
    else
    {
        if(front==-1)
            front++;
        rear = (rear+1)%max;
        arr[rear] = ch;
    }
}

char deletion()
{
    char ch='';
    if(front==-1)
        printf("\nUnderflow");
    else
    {
        ch = arr[front];
        if(front==rear)
            front=rear=-1;
        else
            front = (front+1)%max;

    }
    return(ch);
}
