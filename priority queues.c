
#include <stdio.h>
#define MAX 5

struct item
{
    int data;
    int priority;
};

struct item pq[MAX];
int count = 0;

// Insert an element
void insert()
{
    int value, p;

    if (count == MAX)
    {
        printf("Priority Queue is Full!\n");
        return;
    }

    printf("Enter element: ");
    scanf("%d", &value);

    printf("Enter priority (smaller number = higher priority): ");
    scanf("%d", &p);

    pq[count].data = value;
    pq[count].priority = p;

    count++;

    printf("Element inserted successfully!\n");
}

// Delete highest-priority element
void deleteElement()
{
    int i, pos = 0;

    if (count == 0)
    {
        printf("Priority Queue is Empty!\n");
        return;
    }

    // Find highest priority
    for (i = 1; i < count; i++)
    {
        if (pq[i].priority < pq[pos].priority)
        {
            pos = i;
        }
    }

    printf("Deleted element: %d\n", pq[pos].data);

    // Shift remaining elements
    for (i = pos; i < count - 1; i++)
    {
        pq[i] = pq[i + 1];
    }

    count--;
}

// Display highest-priority element
void peek()
{
    int i, pos = 0;

    if (count == 0)
    {
        printf("Priority Queue is Empty!\n");
        return;
    }

    for (i = 1; i < count; i++)
    {
        if (pq[i].priority < pq[pos].priority)
        {
            pos = i;
        }
    }

    printf("Highest priority element: %d\n", pq[pos].data);
    printf("Priority: %d\n", pq[pos].priority);
}

// Display all elements
void display()
{
    int i;

    if (count == 0)
    {
        printf("Priority Queue is Empty!\n");
        return;
    }

    printf("\nElement\tPriority\n");

    for (i = 0; i < count; i++)
    {
        printf("%d\t%d\n", pq[i].data, pq[i].priority);
    }
}

int main()
{
    int choice;

    while (1)
    {
        printf("\n--- PRIORITY QUEUE ---\n");
        printf("1. INSERT\n");
        printf("2. DELETE\n");
        printf("3. PEEK\n");
        printf("4. DISPLAY\n");
        printf("5. EXIT\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                insert();
                break;

            case 2:
                deleteElement();
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
