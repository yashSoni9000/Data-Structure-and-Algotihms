#include<stdio.h>
#include<stdlib.h>

typedef struct studentlist {
    int rollnum;
    char name[30];
}stud;

int main()
{
    stud *p;
    int n;
    p = (stud*) malloc (n*sizeof(stud));
    printf ("Enter no. of students\n");
    scanf("%d", &n);
    for(int i=0; i<n; i++)
    {
        printf("Enter the roll number of the student:\n");
        scanf("%d", &(p+i)->rollnum);
        printf("Enter the name of the student:\n");
        fflush(stdin);
        gets((p+i)->name);
    }
    for (int i=0; i<n; i++)
    {
        printf ("The details of %d Student are:\n", (p+
        i)->rollnum);
        printf("Name:");
        puts((p+i)->name);
        printf("\n");
    }
    free(p);
    return 0;
}
