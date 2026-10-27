
#include <stdio.h>
#include <ctype.h>
#include <string.h>

char stack[100];
int top = -1;

// PUSH Operation
void push(char x)
{
    stack[++top] = x;
}

// POP Operation
char pop()
{
    return stack[top--];
}

// Operator Precedence
int precedence(char x)
{
    if(x == '^')
        return 3;

    if(x == '*' || x == '/' || x == '%')
        return 2;

    if(x == '+' || x == '-')
        return 1;

    return 0;
}

// Check Right Associativity
int isRightAssociative(char x)
{
    return x == '^';
}

// Infix to Postfix Conversion
void infixToPostfix(char infix[])
{
    char postfix[100];
    int i, j = 0;
    char ch;

    for(i = 0; infix[i] != '\0'; i++)
    {
        ch = infix[i];

        if(isspace((unsigned char)ch))
            continue;

        // Operand
        if(isalnum((unsigned char)ch))
        {
            postfix[j++] = ch;
        }

        // Opening Bracket
        else if(ch == '(')
        {
            push(ch);
        }

        // Closing Bracket
        else if(ch == ')')
        {
            while(top != -1 && stack[top] != '(')
            {
                postfix[j++] = pop();
            }

            if(top == -1)
            {
                printf("Invalid Expression\n");
                return;
            }

            pop();
        }

        // Operator
        else if(ch == '+' || ch == '-' ||
                ch == '*' || ch == '/' ||
                ch == '%' || ch == '^')
        {
            while(top != -1 && stack[top] != '(' &&
                 (precedence(stack[top]) > precedence(ch) ||
                 (precedence(stack[top]) == precedence(ch) &&
                  !isRightAssociative(ch))))
            {
                postfix[j++] = pop();
            }

            push(ch);
        }
        else
        {
            printf("Invalid Expression\n");
            return;
        }
    }

    // Pop Remaining Operators
    while(top != -1)
    {
        if(stack[top] == '(')
        {
            printf("Invalid Expression\n");
            return;
        }

        postfix[j++] = pop();
    }

    postfix[j] = '\0';

    printf("Postfix Expression = %s\n", postfix);
}

// Main Function
int main()
{
    char infix[100];

    printf("Enter Infix Expression: ");
    scanf("%99s", infix);

    infixToPostfix(infix);

    return 0;
}
