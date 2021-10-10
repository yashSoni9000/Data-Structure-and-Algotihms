#include <stdio.h>
#include <process.h>
#include <stdlib.h>

typedef struct linked_node
{
  int data;
  struct linked_node *next;
} node;
node *start, *temp, *last;

void create_node()
{
  temp = (node *)malloc(sizeof(node *));
  printf("Enter an element to enter in link list\n");
  scanf("%d", &temp->data);
  temp->next = NULL;
}

int main(int argc, char const *argv[])
{
  int i, n;
  printf("Enter how many node do you want to make \n");
  scanf("%d", &n);
  for (i = 1; i <= n; i++)
  {
    create_node();
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
  temp=start;
  while (temp != NULL)
  {
    printf("%d ", temp->data);
    temp = temp->next;
  }
  temp == NULL;
  free(temp);

  return 0;
}
