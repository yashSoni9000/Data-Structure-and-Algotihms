#include<stdio.h>
#include<stdlib.h>

void create ();	
void display();	
void insertbeg();
void insrtend();
void count();
void delbeg();
void delend();
void posdel();
void posinsrt();
struct node
{
	int data;
	struct node *next;
};
struct node *head=0,*temp,*newnode,*pre,*nextnode,*current;
								
void create()//--------------------------------------------//create funct 
{
	
	int size,i,a=1;
	printf("enter your size");
	printf("\n");
	scanf("%d",&size);
	printf("enter your data\n");
	printf("\n");
		for (i=0;i<=size-1;i++)
		{
				newnode=(struct node*)malloc(sizeof(struct node));
				scanf("%d",&newnode->data);
				newnode->next=0;
				if (head==0)
					head=temp=newnode;
				else
				{
					temp->next=newnode;
					temp=newnode;
				}
		}
	printf("success full implementation\n");
}

void display()//------------------------------------------//display funct 
{
	if(head==0)
	{
		printf("empty linked list\n");
	}
	else 
	{
	
	temp = head ;
	printf("your data are \n");
	while (temp!=0)
		{
			printf("%d\t",temp->data);
			temp=temp->next;
		}
	}
}
void insertbeg()//----------------------------------------//insert at beg
{
	if (head==0)
	{
		printf("empty linked list\n");
	}
	
	else
	{
		newnode=(struct node*)malloc(sizeof(struct node));
		printf("enter your data\n");
		scanf("%d",&newnode->data);
		newnode->next=head;
		head=newnode;
	}
	if (newnode==head)
	{
		printf("successful\n");
	}
	else
	{
		printf("failure\n");
	}

}

void insrtend()//------------------------------------------//insert at end 
{
	if(head==0)
	printf("list is empty\n");
	else
	{
		temp=head;
		while(temp->next!=0)
		{
			temp=temp->next;
		}
		newnode=(struct node*)malloc(sizeof(struct node));
		printf("enter your data\n");
		scanf("%d",&newnode->data);
		newnode->next=0;
		temp->next=newnode;	
	}
}
void delbeg ()//----------------------------------------- //del from begining
{
	temp=head;
	head=head->next;
	free(temp);
	printf("successfully deleted\n");
}

void delend()  //-------------------------------------------- //DELETE END 
{
    temp=head;
    while (temp->next!=0)
    {
        pre=temp;
        temp=temp->next;
    }
    pre->next=0;
    free(temp);
}

void exit (int);

void count()//------------------------------------------------------  //count
{
    int c=0;
    temp=head;
    while(temp!=0)
    {
        temp=temp->next;
        c++;
    }
    printf("number of elements in list so far is %d\n",c);
}
void posdel()//------------------------------------------------//position delete 
{
    int pos,i;
    printf("enter your position which elemnet you want to delete\n");
    scanf("%d",&pos);
    if (head==0)
    printf("your list is empty");
    else if (pos==1)
    delbeg();
    else 
    {
        temp=head;
        while (i<pos-1)
        {
           temp=temp->next;
           i++;
        }
    nextnode=temp->next;
    temp->next=nextnode->next;
    free(nextnode);
    }

}
void posinsrt()
{
	int i=1,pos; 
	if (head==0)
	printf("empty list");
	else
	{
		printf("enter your position");
		scanf("%d",&pos);
		if (pos==1)
		{
			insertbeg();
		}
		temp=head;
		while(i<pos)
		{
			temp=temp->next;
			i++;
		}
		newnode=(struct node*)malloc(sizeof(struct node));
		scanf("%d",&newnode->data);
		newnode->next=temp->next;
		temp->next=newnode;
	}
}
void main()//--------------------------------------------------//main funct
{
	int a;
	do
	{
		printf("what you want\ncase 1 :create()\ncase 2 :display()\ncase 3:insertbeg()\ncase 4:delbeg()\ncase 5:insrtend()\ncase 6: count()\ncase 7:delend()\ncase 8:posdel()\ncase 9:posinsrt()\n");	
		printf("if you want to stop the progrsm you can press '0' \n thank you \n");		
		scanf("%d",&a);
		switch(a)
		{
			case 1:create();
			break;
			case 2:display();
			break;
			case 3:insertbeg();
			break;
			case 4:delbeg();
			break;
			case 5:insrtend();
			break;
			case 6:count();
			break;
			case 7:delend();
			break;
			case 8:posdel();
			break;
			case 0:exit(0);
			break;
			case 9:posinsrt();
			break;
			default:printf("enter vaild no\n");
		}
	}while(a!=0);	
}
