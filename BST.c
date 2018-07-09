#include <stdio.h>
#include <stdlib.h>
#include<string.h>
struct btnode
{
    char website[100];
    char password[100];
    struct btnode *l,*r;
}*root = NULL, *temp = NULL, *t2, *t1;

void del();
void insert();
void deletenode(struct btnode * t , char web[]);
void update();
void create();
void search(struct btnode *t);
void retrieve(struct btnode *t , char web[]);
void inorder(struct btnode *t);
struct btnode* search1(struct btnode *t, char web[]);
struct btnode* smallest(struct btnode *t);
struct btnode* largest(struct btnode *t);

int flag = 1;

void main()
{
    int ch , n , i;
    char web[100];
    printf("\n \t\t WELCOME");
    printf("\n New User ? \n Press 1 for Yes and 2 for No ");
    scanf("\n%d",&ch);
    if(ch==1)
    {
        printf("\n Enter the number of passwords you want to store:- ");
        scanf("\n%d",&n);
        for(i=0;i<n;i++)
        {
            insert();
        }
    }
    do
    {
    printf("OPERATIONS ---\n");
    printf("1 - Insert a new account\n");
    printf("2 - Delete an account\n");
    printf("3 - Retrieve the password\n");
    printf("4 - Update a password\n");

        printf("\n Enter your choice : ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            insert();
            break;
        case 2:
            printf("\n Enter the website to be deleted :- ");
            fflush(stdin);
            gets(web);
            deletenode(root,web);
            inorder(root);
            break;
         case 3:
            printf("\n Enter the website for which you want to retrieve the password:- ");
            fflush(stdin);
            gets(web);
            retrieve(root,web);
            break;
         case 4:
            update();
            break;
         case 5:

        default :
            printf("\n Wrong choice, Please enter correct choice");
            break;
        }
    printf("\n Enter 0 to continue");
    scanf("%d",&ch);
    }while(ch==0);

    inorder(root);
    }


/* To insert a node in the tree */
void insert()
{
    create();
    if (root == NULL)
        root = temp;
    else
        search(root);
}

/* To create a node */
void create()
{
    char web[100];
    char pass[100];
    printf("\n Enter website :- ");
    fflush(stdin);
    gets(web);
    fflush(stdin);
    printf("\n Enter password of the website :- ");
    gets(pass);
    //fflush(stdin);

    temp = (struct btnode *)malloc(sizeof(struct btnode));
    strcpy(temp->website,web);
    strcpy(temp->password,pass);
    temp->l = temp->r = NULL;
}

/* Function to search the appropriate position to insert the new node */
void search(struct btnode *t)
{
    if (strcmp(temp->website, t->website)>0 && (t->r != NULL))      /* value more than root node value insert at right */
        search(t->r);
    if (strcmp(temp->website ,t->website) >0 && (t->r == NULL))
        t->r = temp;
    if (strcmp(temp->website, t->website)<0 && (t->l != NULL))
        search(t->l);
    if (strcmp(temp->website,t->website)<0 && (t->l == NULL))
        t->l = temp;
}
/*void deletenode()
{
    char web[100];
    struct btnode * t;
    if (root == NULL)
    {
        printf("\n No elements in a tree to delete");
        return;
    }
    printf("\n Enter the website to be deleted :- ");
    fflush(stdin);
    gets(web);
    t1 = root;
    t2 = root;
    t = search1(root,web);
    del(t);
}*/


/* To update value of the node */
void update()
{
    struct btnode * p;
    char web[100];
    char pass[100];

    if (root == NULL)
    {
        printf("No elements in a tree to update\n");
    }
    else
    {
        printf("\n Enter the website whose password is to be updated : ");
        fflush(stdin);
        gets(web);
        t1 = root;
    }

    t2 = root;
    p = search1(root,web);
    puts(p->password);
    fflush(stdin);
    printf("\n Enter the new password:- ");
    gets(p->password);
}

void retrieve(struct btnode *t , char web[])
{
    if (root == NULL)
    {
        printf("\n No elements");
    }
    if(strcmp(t->website , web)==0)
    {
        puts(t->password);
        return ;
    }
    else if(strcmp(web , t->website)>0)
    {
        retrieve(t->r , web);
    }
    else if(strcmp(web , t->website)<0)
        retrieve(t->l , web);
}
/* Search for the appropriate position to insert the new node */
struct btnode* search1(struct btnode *t, char web[])
{
    if(t==NULL)
        return(NULL);
    if (strcmp(web,t->website)>0)
    {
        t1 = t;
        search1(t->r, web);
    }
    else if (strcmp(web, t->website)<0)
    {
        t1 = t;
        search1(t->l, web);
    }
    else if (strcmp(web,t->website)==0)
    {
        return(t);
    }
}

/* To delete a node */
/*void del(struct btnode *t)
{
    struct btnode *k;

    /* To delete leaf node */
    /*if ((t->l == NULL) && (t->r == NULL))
    {
        if (t1->l == t)
        {
            t1->l = NULL;
        }
        else
        {
            t1->r = NULL;
        }
        //t = NULL;
        free(t);
        return;
    }

    /* To delete node having one left hand child */
   /* else if ((t->r == NULL))
    {
        if (t1 == t)
        {
            root = t->l;
            t1 = root;
        }
        else if (t1->l == t)
        {
            t1->l = t->l;
        }
        else
        {
            t1->r = t->l;
        }
        t = NULL;
        free(t);
        return;
    }

    /* To delete node having right hand child */
    /*else if (t->l == NULL)
    {
        if (t1 == t)
        {
            root = t->r;
            t1 = root;
        }
        else if (t1->r == t)
            t1->r = t->r;
        else
            t1->l = t->r;
        t == NULL;
        free(t);
        return;
    }

    /* To delete node having two child */
   /* else if ((t->l != NULL) && (t->r != NULL))
    {
        t2 = root;
        if (t->r != NULL)
        {
            k->r = smallest(t->r);
            flag = 1;
        }
        else
        {
            k->l = largest(t->l);
            flag = 2;
        }
        k=search1(root, k->website);
        strcpy(t->website,k->website);

    }

}*/

void deletenode(struct btnode *t , char web[])
{
    if (root == NULL)
     return ;

    if (strcmp(web,t->website)<0)
       deletenode(t->l, web);

    // If the key to be deleted is greater than the root's key,
    // then it lies in right subtree
    else if (strcmp(web, t->website)>0)
        deletenode(t->r, web);

    // if key is same as root's key, then This is the node
    // to be deleted
    else
    {
        // node with only one child or no child
        if (t->l == NULL)
        {
            //temp = t->r;
            free(t);
            //return temp;
        }
        else if (t->r == NULL)
        {
           // temp = t->l;
            free(t);
            //return temp;
        }

        // node with two children: Get the inorder successor (smallest
        // in the right subtree)
         temp = smallest(t->r);

        // Copy the inorder successor's content to this node
        strcpy(t->website,temp->website);

        // Delete the inorder successor
         deletenode(t->r, temp->website);
    }
    //return t;
}

struct btnode * smallest(struct btnode *t)
{
    t2 = t;
    if (t->l != NULL)
    {
        t2 = t;
        return(smallest(t->l));
    }
    else
        return (t);
}

/*struct btnode * largest(struct btnode *t)
{
    if (t->r != NULL)
    {
        t2 = t;
        return(largest(t->r));
    }
    else
        return(t);
}*/

void inorder(struct btnode *t)
{
    if(t!=NULL)
    {
        inorder(t->l);
        printf("\n");
        fflush(stdin);
        puts(t->website);
        fflush(stdin);
        printf("\t\t");
        fflush(stdin);
        puts(t->password);
        inorder(t->r);
    }
}


