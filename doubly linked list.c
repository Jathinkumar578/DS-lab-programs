
#include <stdio.h>
#include <stdlib.h>

// Structure of Node
struct node
{
    int data;
    struct node *prev;
    struct node *next;
};

struct node *head = NULL;

// 1. Insertion at Beginning
void insert_begin()
{
    struct node *newnode;

    newnode = (struct node*)malloc(sizeof(struct node));

    printf("Enter data: ");
    scanf("%d", &newnode->data);

    newnode->prev = NULL;
    newnode->next = head;

    if(head != NULL)
    {
        head->prev = newnode;
    }

    head = newnode;

    printf("Node inserted at beginning\n");
}

// 2. Insertion at End
void insert_end()
{
    struct node *newnode, *temp;

    newnode = (struct node*)malloc(sizeof(struct node));

    printf("Enter data: ");
    scanf("%d", &newnode->data);

    newnode->next = NULL;

    if(head == NULL)
    {
        newnode->prev = NULL;
        head = newnode;
    }
    else
    {
        temp = head;

        while(temp->next != NULL)
        {
            temp = temp->next;
        }

        temp->next = newnode;
        newnode->prev = temp;
    }

    printf("Node inserted at end\n");
}

// 3. Insertion at Specific Position
void insert_position()
{
    struct node *newnode, *temp;
    int pos, i;

    printf("Enter position: ");
    scanf("%d", &pos);

    if(pos < 1)
    {
        printf("Invalid position\n");
        return;
    }

    newnode = (struct node*)malloc(sizeof(struct node));

    printf("Enter data: ");
    scanf("%d", &newnode->data);

    if(pos == 1)
    {
        newnode->prev = NULL;
        newnode->next = head;

        if(head != NULL)
        {
            head->prev = newnode;
        }

        head = newnode;
        return;
    }

    temp = head;

    for(i = 1; i < pos-1 && temp != NULL; i++)
    {
        temp = temp->next;
    }

    if(temp == NULL)
    {
        printf("Invalid position\n");
        free(newnode);
        return;
    }

    newnode->next = temp->next;
    newnode->prev = temp;

    if(temp->next != NULL)
    {
        temp->next->prev = newnode;
    }

    temp->next = newnode;

    printf("Node inserted at position %d\n", pos);
}

// Display Doubly Linked List
void display()
{
    struct node *temp;

    if(head == NULL)
    {
        printf("List is empty\n");
        return;
    }

    temp = head;

    printf("Doubly Linked List: ");

    while(temp != NULL)
    {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }

    printf("NULL\n");
}

// Main Function
int main()
{
    int choice;

    while(1)
    {
        printf("\n--- DOUBLY LINKED LIST ---\n");
        printf("1. Insert at Beginning\n");
        printf("2. Insert at End\n");
        printf("3. Insert at Position\n");
        printf("4. Display\n");
        printf("5. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                insert_begin();
                break;

            case 2:
                insert_end();
                break;

            case 3:
                insert_position();
                break;

            case 4:
                display();
                break;

            case 5:
                exit(0);

            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}
