
#include <stdio.h>
#include <stdlib.h>

// Structure of Node
struct node
{
    int data;
    struct node *next;
};

struct node *top = NULL;

// 1. PUSH Operation
void push()
{
    struct node *newnode;

    newnode = (struct node*)malloc(sizeof(struct node));

    if(newnode == NULL)
    {
        printf("Stack Overflow\n");
        return;
    }

    printf("Enter element: ");
    scanf("%d", &newnode->data);

    newnode->next = top;
    top = newnode;

    printf("Element inserted successfully\n");
}

// 2. POP Operation
void pop()
{
    struct node *temp;

    if(top == NULL)
    {
        printf("Stack Underflow\n");
    }
    else
    {
        temp = top;

        printf("Deleted element = %d\n", top->data);

        top = top->next;

        free(temp);
    }
}

// 3. PEEK Operation
void peek()
{
    if(top == NULL)
    {
        printf("Stack is Empty\n");
    }
    else
    {
        printf("Top element = %d\n", top->data);
    }
}

// 4. DISPLAY Operation
void display()
{
    struct node *temp;

    if(top == NULL)
    {
        printf("Stack is Empty\n");
    }
    else
    {
        temp = top;

        printf("Stack elements are:\n");

        while(temp != NULL)
        {
            printf("%d\n", temp->data);
            temp = temp->next;
        }
    }
}

// Main Function
int main()
{
    int choice;

    while(1)
    {
        printf("\n--- STACK USING LINKED LIST ---\n");
        printf("1. PUSH\n");
        printf("2. POP\n");
        printf("3. PEEK\n");
        printf("4. DISPLAY\n");
        printf("5. EXIT\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                push();
                break;

            case 2:
                pop();
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
