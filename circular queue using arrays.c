
#include <stdio.h>
#define MAX 5

int queue[MAX];
int front = -1, rear = -1;

// Insert an element
void enqueue()
{
    int value;

    if ((rear + 1) % MAX == front)
    {
        printf("Circular Queue is Full!\n");
        return;
    }

    printf("Enter element: ");
    scanf("%d", &value);

    if (front == -1)
    {
        front = 0;
        rear = 0;
    }
    else
    {
        rear = (rear + 1) % MAX;
    }

    queue[rear] = value;

    printf("%d inserted successfully\n", value);
}

// Delete an element
void dequeue()
{
    if (front == -1)
    {
        printf("Circular Queue is Empty!\n");
        return;
    }

    printf("Deleted element: %d\n", queue[front]);

    if (front == rear)
    {
        front = -1;
        rear = -1;
    }
    else
    {
        front = (front + 1) % MAX;
    }
}

// Display first element
void peek()
{
    if (front == -1)
    {
        printf("Circular Queue is Empty!\n");
    }
    else
    {
        printf("Front element: %d\n", queue[front]);
    }
}

// Display all elements
void display()
{
    int i;

    if (front == -1)
    {
        printf("Circular Queue is Empty!\n");
        return;
    }

    printf("Circular Queue elements: ");

    i = front;

    while (1)
    {
        printf("%d ", queue[i]);

        if (i == rear)
            break;

        i = (i + 1) % MAX;
    }

    printf("\n");
}

int main()
{
    int choice;

    while (1)
    {
        printf("\n--- CIRCULAR QUEUE ---\n");
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
