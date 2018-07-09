#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
struct cqueue
{
    int item;
    struct cqueue *next;

}*front = NULL , *rear = NULL;

void insert(int item)
{
    struct cqueue * temp;
    temp = (struct cqueue *)malloc(sizeof(struct cqueue));
    if(temp==NULL)
        printf("\n Overflow");
    else
    {
        temp->item=item;
        if(front==NULL)
            front = rear = NULL;
        else
        {
            rear->next = temp;
            rear = temp;
        }
        rear->next = front;
    }
}

int deletion()
{
    struct cqueue * temp;
    int item = 0;
    if(front==NULL)
        printf("\n Underflow");
    else
    {
        temp = front;
        item = temp->item;
        if(front==rear)
            front = rear = NULL;
        else
        {
            front = front->next;
            rear->next = front;
        }
        free(temp);
    }
    return(item);
}

void traverse()
{
    struct cqueue * ptr;
    if(front==NULL)
        printf("\n Stack is Empty");
    else
    {
        for(ptr = front ; ptr!=NULL ; ptr=ptr->next)
            printf("\n %d",ptr->item);
    }
}

void main()
    {
      int ch , item;
      do
      {
          printf("\n 1... INSERT");
          printf("\n 2... DELETE");
          printf("\n 3... TRAVERSE");
          printf("\n Enter your choice:- ");
          scanf("\n %d",&ch);
          switch(ch)
          {
          case 1:
            scanf("\n %d",&item);
            insert(item);
            break;
          case 2:
            item = deletion();
            printf("\n Deleted element %d",item);
            break;
          case 3:
            traverse();
            break;
          }
          printf("\n enter 0 to continue:- ");
          scanf("\n %d",&ch);
      }while(ch==0);
}

