
#include <stdio.h>
#define SIZE 100

int stack[SIZE];
int top = -1;

// 1. PUSH Operation
void push()
{
    int value;

    if(top == SIZE - 1)
    {
        printf("Stack Overflow\n");
    }
    else
    {
        printf("Enter element: ");
        scanf("%d", &value);

        top++;
        stack[top] = value;

        printf("Element inserted successfully\n");
    }
}

// 2. POP Operation
void pop()
{
    if(top == -1)
    {
        printf("Stack Underflow\n");
    }
    else
    {
        printf("Deleted element = %d\n", stack[top]);
        top--;
    }
}

// 3. PEEK Operation
void peek()
{
    if(top == -1)
    {
        printf("Stack is Empty\n");
    }
    else
    {
        printf("Top element = %d\n", stack[top]);
    }
}

// 4. DISPLAY Operation
void display()
{
    int i;

    if(top == -1)
    {
        printf("Stack is Empty\n");
    }
    else
    {
        printf("Stack elements are:\n");

        for(i = top; i >= 0; i--)
        {
            printf("%d\n", stack[i]);
        }
    }
}

// Main Function
int main()
{
    int choice;

    while(1)
    {
        printf("\n--- STACK USING ARRAY ---\n");
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
