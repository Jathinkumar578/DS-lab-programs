
#include <stdio.h>
#include <stdlib.h>

// Structure of Node
struct node
{
    int data;
    struct node *next;
};

struct node *front = NULL;
struct node *rear = NULL;

// 1. ENQUEUE Operation
void enqueue()
{
    struct node *newnode;

    newnode = (struct node*)malloc(sizeof(struct node));

    if(newnode == NULL)
    {
        printf("Memory not available\n");
        return;
    }

    printf("Enter element: ");
    scanf("%d", &newnode->data);

    newnode->next = NULL;

    if(front == NULL)
    {
        front = newnode;
        rear = newnode;
    }
    else
    {
        rear->next = newnode;
        rear = newnode;
    }

    printf("Element inserted successfully\n");
}

// 2. DEQUEUE Operation
void dequeue()
{
    struct node *temp;

    if(front == NULL)
    {
        printf("Queue Underflow\n");
    }
    else
    {
        temp = front;

        printf("Deleted element = %d\n", front->data);

        front = front->next;

        if(front == NULL)
        {
            rear = NULL;
        }

        free(temp);
    }
}

// 3. PEEK Operation
void peek()
{
    if(front == NULL)
    {
        printf("Queue is Empty\n");
    }
    else
    {
        printf("Front element = %d\n", front->data);
    }
}

// 4. DISPLAY Operation
void display()
{
    struct node *temp;

    if(front == NULL)
    {
        printf("Queue is Empty\n");
    }
    else
    {
        temp = front;

        printf("Queue elements are:\n");

        while(temp != NULL)
        {
            printf("%d -> ", temp->data);
            temp = temp->next;
        }

        printf("NULL\n");
    }
}

// Main Function
int main()
{
    int choice;

    while(1)
    {
        printf("\n--- QUEUE USING LINKED LIST ---\n");
        printf("1. ENQUEUE\n");
        printf("2. DEQUEUE\n");
        printf("3. PEEK\n");
        printf("4. DISPLAY\n");
        printf("5. EXIT\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                enqueue();
                break;

            case 2:
                dequeue();
                break;

            case 3:
                peek();
                break;

            case 4:
                display();
                break;

            case 5:
                return 0;

            default:
                printf("Invalid Choice\n");
        }
    }

    return 0;
}
