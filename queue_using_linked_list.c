#include<stdio.h>
#include<stdlib.h>

void enqueue();
void dequeue();
void display();

typedef struct linknode
{
    int data;
    struct linknode * next;
}node;

node *temp,*front,*rear;


int main()
{
    int ch;
    while(1)
    {
        printf("\nchoose any one of the following operations = \n1.Enqueue\n2.Dequeue\n3.Display\n4.Exit\n\n");
        fflush(stdin);
        scanf("%d",&ch);
        switch (ch)
        {
        case 1:
            enqueue();
            break;
        
        case 2:
            dequeue();
            break;
    
        case 3:
            display();
            break;
        
        case 4:
            exit(0);
            break;
        
        default:
            printf("\nInvalid choice!!\n");
            break;
        }
    }
    return 0;
}

void enqueue()
{
    temp=(node *)malloc(sizeof(node));
    printf("Enter new element = \n");
    scanf("%d",&temp->data);
    temp->next=NULL;
    if (rear==NULL)
    {
        rear=temp;
        front=temp;
    } 
    else
    {
        rear->next = temp;
        rear=temp;
    }
}

void dequeue()
{
    if(front==NULL)
        printf("\nUnderflow!\n");

    else if(front==rear)
    {
        free(front);
        front=NULL;
        rear=NULL;
    }
    else
    {
        temp=front;
        front=front->next;
        free(temp);
        temp=NULL;
    }
}

void display()

{
    if(front==NULL) printf("\nUnderflow!\n");
    else
    {
        temp=front;
        while (temp!=NULL)
        {
            printf("%d ",temp->data);
            temp=temp->next;
        }
    }
}