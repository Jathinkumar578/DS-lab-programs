
#include <stdio.h>
#include <ctype.h>

int stack[100];
int top = -1;

// PUSH Operation
void push(int x)
{
    stack[++top] = x;
}

// POP Operation
int pop()
{
    return stack[top--];
}

// Postfix Evaluation
int evaluate(char postfix[])
{
    int i, a, b, result;
    char ch;

    for(i = 0; postfix[i] != '\0'; i++)
    {
        ch = postfix[i];

        // If Operand
        if(isdigit((unsigned char)ch))
        {
            push(ch - '0');
        }

        // If Operator
        else if(ch == '+' || ch == '-' ||
                ch == '*' || ch == '/' || ch == '%')
        {
            if(top < 1)
            {
                printf("Invalid Expression\n");
                return 0;
            }

            b = pop();
            a = pop();

            switch(ch)
            {
                case '+':
                    result = a + b;
                    break;

                case '-':
                    result = a - b;
                    break;

                case '*':
                    result = a * b;
                    break;

                case '/':
                    if(b == 0)
                    {
                        printf("Division by zero error\n");
                        return 0;
                    }
                    result = a / b;
                    break;

                case '%':
                    if(b == 0)
                    {
                        printf("Division by zero error\n");
                        return 0;
                    }
                    result = a % b;
                    break;
            }

            push(result);
        }
        else
        {
            printf("Invalid Expression\n");
            return 0;
        }
    }

    if(top != 0)
    {
        printf("Invalid Expression\n");
        return 0;
    }

    return pop();
}

// Main Function
int main()
{
    char postfix[100];
    int result;

    printf("Enter Postfix Expression: ");
    scanf("%99s", postfix);

    if(postfix[0] == '\0')
    {
        printf("Empty Expression\n");
        return 0;
    }

    result = evaluate(postfix);

    if(top == -1)
        printf("Result = %d\n", result);

    return 0;
}
