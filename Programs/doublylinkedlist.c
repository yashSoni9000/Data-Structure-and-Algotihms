#include <stdio.h>
#include <stdlib.h>
typedef struct linknode {
    int data;
    struct linknode* next;
    struct linknode* prev;
}node;

node* start, * temp, * last;

void create_node()
{
    temp = (node*)malloc(sizeof(node));
    printf("\nEnter the element\n");
    scanf("%d", &temp->data);
    temp->prev = NULL;
    temp->next = NULL;
}
void insertatbeg();
void insertatend();
void insertatpos();
void delatbeg();
void delatend();
void delatpos();
void display();

int n = 0, pos;
int main() {
    int ch, j;
    while (1)
    {
        printf("\nSelect an operation\n1. Insert a node at beginning\n2. Insert a node at last\n3. Insert a node at a specific position\n4. Delete a node from beginning\n5. Delete a node from last\n6. Delete a node from specific position\n7. Display\n");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            insertatbeg();
            break;
        case 2:
            insertatend();
            break;
        case 3:
            insertatpos();
            break;
        case 4:
            delatbeg();
            break;
        case 5:
            delatend();
            break;
        case 6:
            delatpos();
            break;
        case 7:
            display();
            break;
        default:
            printf("Invalid Choice!\n");
            break;
        }
    }
    return 0;
}
void insertatbeg() {
    create_node();
    if (start == NULL)
    {
        start = temp;
        last = temp;
        n++;
    }
    else
    {
        temp->next = start;
        start->prev = temp;
        start = temp;
        n++;
    }
}

void insertatend() {
    create_node();
    if (last == NULL)
    {
        start = temp;
        last = temp;
        n++;
    }
    else
    {
        last->next = temp;
        temp->prev = last;
        last = temp;
        n++;
    }
}
void insertatpos() {
    if (start == NULL)
    {
        insertatbeg();
    }
    else
    {
        printf("Enter the position at which element will be inserted\n");
        scanf("%d", &pos);
        if (n + 1 < pos)
        {
            printf("Not Possible\n");
        }
        else if (pos == (n + 1))
        {
            insertatend();
        }
        else
        {
            node* p;
            p = start;
            for (int i = 1; i < pos - 1; i++)
            {
                p = p->next;
            }
            create_node();
            temp->prev = p;
            temp->next = p->next;
            p->next = temp;
            temp->next->prev = temp;
            n++;
        }
    }
}
void delatbeg() {
    if (start == NULL)
    {
        printf("List doesn't exist\n");
    }
    else
    {
        temp = start;
        printf("%d will be deleted from the list\n", temp->data);
        start = start->next;
        free(temp);
        temp = NULL;
        n--;
        if (start == NULL)
        {
            last == NULL;
        }
        else
        {
            start->prev = NULL;
        }
    }
}
void delatend() {
    if (last == NULL)
    {
        printf("List doesn't exist\n");
    }
    else
    {
        temp = last;
        printf("%d will be deleted from the list\n", temp->data);
        last = last->prev;
        free(temp);
        temp = NULL;
        n--;
        if (last == NULL)
        {
            start = NULL;
        }
        else
        {
            last->next = NULL;
        }
    }
}
void delatpos() {
    if (last == NULL)
    {
        printf("List doesn't exist\n");
    }
    else if (n == 1)
    {
        delatend();
    }
    else
    {
        node* p;
        printf("Enter the position of element to delete\n");
        scanf("%d", &pos);
        if (n < pos)
        {
            printf("Not possible\n");
        }
        else if (pos == n)
        {
            delatend();
        }
        else if (pos == 1)
        {
            delatbeg();
        }

        else {
            p = start;
            for (int i = 1; i < pos; i++)
            {
                p = p->next;
            }
            printf("%d will be deleted from the list\n", p->data);
            p->prev->next = p->next;
            p->next->prev = p->prev;
            free(p);
            p = NULL;
            n--;
        }
    }
}
void display() {
    if (start == NULL)
    {
        printf("List doesn't exist\n");
    }
    else
    {
        temp = start;
        while (temp != NULL)
        {
            printf("%d ", temp->data);
            temp = temp->next;
        }
    }
}
