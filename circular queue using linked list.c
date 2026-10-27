
#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *front = NULL;
struct node *rear = NULL;

// Insert an element
void enqueue()
{
    struct node *newnode;
    int value;

    newnode = (struct node *)malloc(sizeof(struct node));

    if (newnode == NULL)
    {
        printf("Memory allocation failed!\n");
        return;
    }

    printf("Enter element: ");
    scanf("%d", &value);

    newnode->data = value;
    newnode->next = NULL;

    if (front == NULL)
    {
        front = rear = newnode;
        rear->next = front;
    }
    else
    {
        rear->next = newnode;
        rear = newnode;
        rear->next = front;
    }

    printf("%d inserted successfully\n", value);
}

// Delete an element
void dequeue()
{
    struct node *temp;

    if (front == NULL)
    {
        printf("Circular Queue is Empty!\n");
        return;
    }

    temp = front;

    printf("Deleted element: %d\n", front->data);

    if (front == rear)
    {
        front = rear = NULL;
    }
    else
    {
        front = front->next;
        rear->next = front;
    }

    free(temp);
}

// Display front element
void peek()
{
    if (front == NULL)
    {
        printf("Circular Queue is Empty!\n");
    }
    else
    {
        printf("Front element: %d\n", front->data);
    }
}

// Display all elements
void display()
{
    struct node *temp;

    if (front == NULL)
    {
        printf("Circular Queue is Empty!\n");
        return;
    }

    temp = front;

    printf("Circular Queue elements: ");

    do
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    while (temp != front);

    printf("\n");
}

int main()
{
    int choice;

    while (1)
    {
        printf("\n--- CIRCULAR QUEUE USING LINKED LIST ---\n");
        printf("1. ENQUEUE\n");
        printf("2. DEQUEUE\n");
        printf("3. PEEK\n");
        printf("4. DISPLAY\n");
        printf("5. EXIT\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
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
                printf("Invalid Choice!\n");
        }
    }

    return 0;
}
