#include <stdio.h>
#include <stdlib.h>

// NODE STRUCTURE
struct Node
{
    int data;
    struct Node *next;
};

// INSERT A NODE INTO A CIRCULAR LINKED LIST
void insertbeg(struct Node **head_ref, int data)
{
    struct Node *ptr1 = (struct Node *)malloc(sizeof(struct Node));
    struct Node *temp = *head_ref;
    ptr1->data = data;
    ptr1->next = *head_ref;

    if (*head_ref != NULL)
    {
        while (temp->next != *head_ref)
            temp = temp->next;
        temp->next = ptr1;
    }
    else
        ptr1->next = ptr1;

    *head_ref = ptr1;
}

// DISPLAY THE ELEMETS IN LIST
void display(struct Node *head)
{
    struct Node *temp = head;
    if (head != NULL)
    {
        do
        {
            printf("%d ", temp->data);
            temp = temp->next;
        } while (temp != head);
    }
}

int main()
{
    struct Node *head = NULL;

    insertbeg(&head, 7);
    insertbeg(&head, 56);
    insertbeg(&head, 2);
    insertbeg(&head, 11);
    insertbeg(&head, 64);

    printf("Elements in Circular Linked List :\n");
    display(head);

    return 0;
}