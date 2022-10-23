#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct linknode
{
    struct linknode *prev;
    int data;
    struct linknode *next;

} node;

node *temp, *start, *last;
int count = 0;

void create_node()
{
    temp = (node *)malloc(sizeof(node));
    printf("Enter the number:");
    scanf("%d", &temp->data);
    temp->next = NULL;
    temp->prev = NULL;
    count++;
}

void insert_first()
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
        start->prev = temp;
        start = temp;
    }
}

void insert_last()
{
    create_node();

    if (last == NULL)
    {
        start = temp;
        last = temp;
    }

    else
    {
        last->next = temp;
        temp->prev = last;
        last = temp;
    }
}

void insert_mid()
{
    int pos;
    if (start == NULL)
    {
        create_node();
        start = temp;
        last = temp;
    }

    else
    {
        printf("\nEnter the position:");
        scanf("%d", &pos);

        if (pos == count + 1)
        {
            insert_last();
        }

        else if (pos > count)
        {
            printf("Not possible\n");
        }

        else
        {
            create_node();

            node *p, *q;
            p = start;
            for (int i = 1; i < pos; i++)
            {
                q = p;
                p = p->next;
            }

            q->next = temp;
            temp->prev = q;
            temp->next = p;
            p->prev = temp;
        }
    }
}

void delete_first()
{
    if (start == NULL)
    {
        printf("No elemenets Exist\n");
    }

    else if (start == last)
    {
        free(start);
        start = NULL;
        last = NULL;
        count--;
    }

    else
    {
        temp = start;
        start = start->next;
        free(temp);
        temp = NULL;
        start->prev = NULL;
        count--;
    }
}

void delete_last()
{
    if (last == NULL)
    {
        printf("No elemenets Exist\n");
    }

    else if (last == start)
    {
        free(start);
        start = NULL;
        last = NULL;
        count--;
    }

    else
    {
        temp = last;
        last = last->prev;
        free(temp);
        temp = NULL;
        last->next = NULL;
        count--;
    }
}

void delete_mid()
{
    node *p, *q;
    int pos;
    if (start == NULL)
    {
        printf("No elemenets Exist\n");
    }

    else if (last == start)
    {
        free(start);
        start = NULL;
        last = NULL;
        count--;
    }

    else
    {
        printf("Enter the position:");
        scanf("%d", &pos);
        if (pos > count)
        {
            printf("Not possible\n");
        }

        else if (pos == count)
        {
            delete_last();
        }

        else
        {
            p = start;
            for (int i = 1; i < pos; i++)
            {
                q = p;
                p = p->next;
            }
            temp = p;
            p = p->next;
            q->next = p;
            p->prev = q;
            free(temp);
            temp = NULL;
            count--;
        }
    }
}

void front_display()
{
    if (start == NULL)

    {
        printf("No elemenets Exist\n");
    }
    else
    {
        node *p;
        p = start;
        do
        {
            printf("%d\n", p->data);
            p = p->next;
        } while ((p != NULL));
    }
}

void reverse_display()
{
    if (last == NULL)

    {
        printf("No elemenets Exist\n");
    }

    else
    {
        node *p;
        p = last;
        do
        {
            printf("%d\n", p->data);
            p = p->prev;
        } while ((p != NULL));
    }
}

int main()
{
    int ch;
    while (1)
    {
        printf("Enter the choice:");
        printf("\n1:Insert first\n2:Insert Mid\n3:Insert Last\n4:Delete first\n5:Delete mid\n6:Delete last\n7:Front Display\n8:Reverse Display\n9:Exit\n");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            insert_first();
            break;
        case 2:
            insert_mid();
            break;
        case 3:
            insert_last();
            break;
        case 4:
            delete_first();
            break;
        case 5:
            delete_mid();
            break;
        case 6:
            delete_last();
            break;
        case 7:
            front_display();
            break;
        case 8:
            reverse_display();
            break;
        case 9:
            exit(0);
            break;
        }
    }
    return 0;
}