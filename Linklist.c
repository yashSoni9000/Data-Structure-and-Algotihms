#include<stdio.h>
#include<process.h>
#include<stdlib.h>
int num;
typedef struct employee{
    /* data */
    int data;
    struct employee *next;
    
}emp;

emp *last,*start,*temp;

void create_node()
{
    int no;
    temp=(emp*)malloc(sizeof(emp));
    printf("Enter Details : ");
    scanf("%d",&temp->data);
    temp->next=NULL;
    num++;
}

 void delete_first()
{
    if(start==NULL)
    {
        printf("No element to delete");
    }
    else
    {
        temp=start;
        start=start->next;
        free(temp);
        temp = NULL;
        count--;
    }
    if(start==NULL)
    {
        last = NULL;
    }
}

void create_list()
{
    int i,n;
    printf("Heyy, Bro its just linkedlist \n Enter value of n : ");
    scanf("%d",&n);

    for ( i=1; i<=n; i++)
    {
        /* code */
        create_node();
        if(start == NULL)
        {
            start = temp;
            last = temp; 
        }
        else
        {
            last->next = temp;
            last = temp;
        }
    }

}

void insertionLast()
{
    create_node();
    if(start==NULL)
    {
        start=temp;
        last=temp;
    }
    else
    {
        last->next=temp;
        last = temp;
    }
}

void insertion_first()
{
    create_node();
    if (start == NULL)
    {
        start = temp;
        last = temp;
    }
    else
    {
        temp->next = start;
        start = temp;
    }
}

void display()
{
    temp = start;
    while (temp !=  NULL)
    {
        /* code */
        printf("%d \n",temp->data);
        temp = temp->next;
    }

}


void insertionMid()
{
    int pos;
    create_node();
    if(start==NULL)
    {
        start=temp;
        last=temp;
    }
    else
    {
        printf("Enter Postion for new value : ");
        scanf("%d",&pos);
        if(num<pos)
        {
            printf("NOT POSSIBLE ");
        }
        else
        {
            if(pos==num)
            {
                last->next=temp;
                last=temp;
            }
            else
            {
                emp *p,*q;
                p=start;
                for(int i=1;i<pos-1;i++)
                    p=p->next;
                temp->next=p->next;
                p->next=temp;
            }
        }
    }
}

int main()
{
    int k;
    printf("---------Heyy Bro---------\n Enter number acoooring to your mind : \n   ");
    
    while (1)
    {
        printf("1) Create Linked Listn \n 2) Insertion at First \n 3)Insertion at Mid Postion \n 4) Insertion at Last Postion \n5) Display Linked List \n6) Exit : \n");
        scanf("%d",&k);
        /* code */

        switch (k)
    {
    case 1:
            create_list();
        break;

    case 2:
            insertion_first();
            break;

    case 3: 
            insertionMid();
        break;

    case 4:
            insertionLast();
        break;

    case 5:
            display();
            break;
    case 6: exit(0);
    break;
    
    default:
    printf("Error");
        break;
    }
    }
    
    
    
    
    return 0;
}




# added by jash hinger


#include <stdio.h>
#include <stdlib.h>
typedef struct linknode
{
    int data;
    struct linknode *next; //pointer variable of struct linknode type.
} node;
// declaring pointer variable having by-default value NULL.
node *start, *last, *temp;

//defining create_node function
void create_node()
{
    temp = (node *)malloc(sizeof(node));
    printf("\n <-----Enter new values--->\n");
    scanf("%d", &temp->data);
    temp->next = NULL;
}
int main()
{
    int n;
    printf("Enter how many values u want to enter:\n");
    scanf("%d", &n); // no of nodes we want to create.
    for (int i = 1; i <= n; i++)
    {
        create_node();
        // if start == null, means first time we have assign values in temp and now we will set start to temp and last to temp.
        if (start == NULL)
        {
            start = temp;
            last = temp;
        }
        else
        {
            last->next = temp;
            last = temp;
        }
    }
    //now we will start traversing from start till temp not reach null.
    temp = start;
    printf("The values are:\n");
    while (temp != NULL)
    {
        printf("%d", temp->data);
        temp = temp->next;
        printf("\n");
    }
    return 0;
}
