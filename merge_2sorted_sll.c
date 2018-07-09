#include<stdio.h>
#include<stdlib.h>
struct node
{
    int item;
    struct node *next;
}*first = NULL;

void insert(int item , struct node*first)
{
    struct node * temp , *ptr;
    temp = (struct node *)malloc(sizeof(struct node));
    if(temp==NULL)
        printf("\n Overflow");
    else
    {
        ptr = first;
            while(ptr->next !=NULL)
            {
                ptr = ptr->next;
            }
            temp->item = item;
            temp->next = NULL;
            ptr->next = temp;
        }
}
void traverse(struct node *first)
{
    if(first==NULL)
        printf("\nList is Empty");
    else
    {
        struct node * temp;
        for(temp=first ; temp!=NULL ; temp=temp->next)
          {
             printf(" %d " , temp->item);
          }
    }
}
struct node* append(struct node *temp , struct node *first)
{
    struct node * ptr;
    if(first==NULL)
        first = temp;
    else
    {
        ptr = first;
        while(ptr->next!=NULL)
        {
            ptr = ptr->next;
        }
        ptr->next = temp;
    }
    return(first);
}
struct node * merge(struct node * f1 , struct node * f2 )
{
    struct node *ptr=NULL , *f3=NULL;
    while(f1!=NULL & f2!=NULL)
    {
        if(f1->item < f2->item)
        {
            insert(f1->item , ptr);
            f3 = append(ptr,f1);
            f1 = f1->next;
        }
       else if(f1->item > f2->item)
        {
            insert(f2->item , ptr);
            f3 = append(ptr,f2);
            f2 = f2->next;
        }
        else
        {
                insert(f1->item , ptr);
                f3=append(ptr,f1);
                f1 = f1->next;
                f2=f2->next;
        }
    }
    while(f1!=NULL)
    {
        insert(f1->item , ptr);
        f3 = append(ptr,f1);
        ptr->item = f1->item;
        f1 = f1->next;
    }
    while(f2!=NULL)
    {
        insert(f2->item , ptr);
        f3=append(ptr,f2);
        ptr->item = f2->item;
        f2 = f2->next;
    }
    return(ptr);
}

void main()
{
    struct node *f1=NULL , *f2=NULL ,*f3=NULL;
    int i , n1 , n2 ,n3 , item;
    printf("\n How many nodes do you want to insert for First SLL:- ");
    scanf("\n %d",&n1);
    printf("\n How many nodes do you want to insert for Second SLL:- ");
    scanf("\n %d",&n2);
    fflush(stdin);
    printf("\n Enter elements in ascending order for 1st SLL");
    for(i=0;i<n1;i++)
    {
        scanf("\n %d",&item);
        insert(item,first);
    }
    printf("\n Enter elements in ascending order for 2nd SLL");
    for(i=0;i<n2;i++)
    {
        scanf("\n %d",&item);
        insert(item,f2);
    }
    printf("\n The elements of each SLL are:- ");
    traverse(f1);
    printf("\n");
    traverse(f2);
    f3 = merge(f1 , f2);
    traverse(f3);
}
