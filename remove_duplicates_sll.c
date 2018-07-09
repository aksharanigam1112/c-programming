#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
};

struct node* newNode(int data)
{
   struct node *temp;
   temp = (struct node*)malloc(sizeof(struct node));
   temp->data = data;
   temp->next = NULL;
   return temp;
}


void removeDuplicates(struct Node *first)
{
    struct node *ptr1, *ptr2, *dup;
    ptr1 = first;

    while (ptr1 != NULL && ptr1->next != NULL)
    {
        ptr2 = ptr1;
        while (ptr2->next != NULL)
        {

            if (ptr1->data == ptr2->next->data)
            {

                dup = ptr2->next;
                ptr2->next = ptr2->next->next;
                delete(dup);
            }
            else
                ptr2 = ptr2->next;
        }
        ptr1 = ptr1->next;
    }
}
