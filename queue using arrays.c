
#include <stdio.h>
#define SIZE 100

int queue[SIZE];
int front = -1;
int rear = -1;

// 1. ENQUEUE Operation
void enqueue()
{
    int value;

    if(rear == SIZE - 1)
    {
        printf("Queue Overflow\n");
    }
    else
    {
        printf("Enter element: ");
        scanf("%d", &value);

        if(front == -1)
        {
            front = 0;
        }

        rear++;
        queue[rear] = value;

        printf("Element inserted successfully\n");
    }
}

// 2. DEQUEUE Operation
void dequeue()
{
    if(front == -1 || front > rear)
    {
        printf("Queue Underflow\n");
    }
    else
    {
        printf("Deleted element = %d\n", queue[front]);

        if(front == rear)
        {
            front = -1;
            rear = -1;
        }
        else
        {
            front++;
        }
    }
}

// 3. PEEK Operation
void peek()
{
    if(front == -1)
    {
        printf("Queue is Empty\n");
    }
    else
    {
        printf("Front element = %d\n", queue[front]);
    }
}

// 4. DISPLAY Operation
void display()
{
    int i;

    if(front == -1)
    {
        printf("Queue is Empty\n");
    }
    else
    {
        printf("Queue elements are:\n");

        for(i = front; i <= rear; i++)
        {
            printf("%d ", queue[i]);
        }

        printf("\n");
    }
}

// Main Function
int main()
{
    int choice;

    while(1)
    {
        printf("\n--- QUEUE USING ARRAY ---\n");
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
