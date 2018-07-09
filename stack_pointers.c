#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
struct stack
{
    int item;
    struct stack *next;

}*top = NULL;

void push(int item)
{
    struct stack * obj;
    obj = (struct stack *)malloc(sizeof(struct stack));
    if(obj == NULL)
        printf("\n Overflow");
    else
    {
        obj->item = item;
        obj->next = top;
        top = obj;
    }
}

int pop()
{
    struct stack *temp;
    int item= 0;
    if(top == NULL)
    {
        printf("\n Underflow");
    }
    else
    {
        item = top->item;
        temp = top;
        top  = top->next;
        free(temp);
    }
    return(item);
}
void traverse()
{
    struct stack *obj;
    obj = top;
    if(top!=NULL)
    {
        while(obj!=NULL)
        {
            printf("\n %d",obj->item);
            obj = obj->next;
        }
    }
    else
        printf("Stack is Empty");
}
    void main()
    {
      int ch , item;
      do
      {
          printf("\n 1... PUSH");
          printf("\n 2... POP");
          printf("\n 3... TRAVERSE");
          printf("\n Enter your choice:- ");
          scanf("\n %d",&ch);
          switch(ch)
          {
          case 1:
            scanf("\n %d",&item);
            push(item);
            break;
          case 2:
            item = pop();
            printf("\n Poped element %d",item);
            break;
          case 3:
            traverse();
            break;
          }
          printf("\n enter 0 to continue:- ");
          scanf("\n %d",&ch);
      }while(ch==0);
    }
