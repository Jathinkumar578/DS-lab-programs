
#include <stdio.h>
#include <stdlib.h>

// Structure of Node
struct node
{
    int data;
    struct node *next;
};

struct node *head = NULL;

// 1. Insertion at Beginning
void insert_begin()
{
    struct node *newnode, *temp;

    newnode = (struct node*)malloc(sizeof(struct node));

    printf("Enter data: ");
    scanf("%d", &newnode->data);

    if(head == NULL)
    {
        head = newnode;
        newnode->next = head;
    }
    else
    {
        temp = head;

        while(temp->next != head)
        {
            temp = temp->next;
        }

        newnode->next = head;
        temp->next = newnode;
        head = newnode;
    }

    printf("Node inserted at beginning\n");
}

// 2. Insertion at End
void insert_end()
{
    struct node *newnode, *temp;

    newnode = (struct node*)malloc(sizeof(struct node));

    printf("Enter data: ");
    scanf("%d", &newnode->data);

    if(head == NULL)
    {
        head = newnode;
        newnode->next = head;
    }
    else
    {
        temp = head;

        while(temp->next != head)
        {
            temp = temp->next;
        }

        temp->next = newnode;
        newnode->next = head;
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
        if(head == NULL)
        {
            head = newnode;
            newnode->next = head;
        }
        else
        {
            temp = head;

            while(temp->next != head)
            {
                temp = temp->next;
            }

            newnode->next = head;
            temp->next = newnode;
            head = newnode;
        }

        return;
    }

    if(head == NULL)
    {
        printf("Invalid position\n");
        free(newnode);
        return;
    }

    temp = head;

    for(i = 1; i < pos-1 && temp->next != head; i++)
    {
        temp = temp->next;
    }

    if(i != pos-1)
    {
        printf("Invalid position\n");
        free(newnode);
        return;
    }

    newnode->next = temp->next;
    temp->next = newnode;

    printf("Node inserted at position %d\n", pos);
}

// Display Circular Linked List
void display()
{
    struct node *temp;

    if(head == NULL)
    {
        printf("List is empty\n");
        return;
    }

    temp = head;

    printf("Circular Linked List: ");

    do
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    while(temp != head);

    printf("(HEAD)\n");
}

// Main Function
int main()
{
    int choice;

    while(1)
    {
        printf("\n--- CIRCULAR SINGLY LINKED LIST ---\n");
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
