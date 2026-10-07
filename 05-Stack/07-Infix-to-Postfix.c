#include <stdio.h>
#include <ctype.h>

#define MAX 100

int main()
{
    // Infix to Postfix Conversion

    char infix[MAX], postfix[MAX], stack[MAX];
    int top = -1;
    int i, j = 0;
    char ch;

    printf("Enter an infix expression: ");
    scanf("%s", infix);

    // Important step - Process each character of the expression
    for (i = 0; infix[i] != '\0'; i++)
    {
        ch = infix[i];

        // If character is an operand, add it directly to postfix
        if (isalnum(ch))
        {
            postfix[j] = ch;
            j++;
        }

        // If opening bracket, push it into stack
        else if (ch == '(')
        {
            top++;
            stack[top] = ch;
        }

        // If closing bracket, pop until opening bracket
        else if (ch == ')')
        {
            while (top != -1 && stack[top] != '(')
            {
                postfix[j] = stack[top];
                j++;
                top--;
            }

            if (top != -1)
            {
                top--;
            }
        }

        // If operator, handle according to precedence
        else
        {
            while (top != -1 && stack[top] != '(' &&
                   ((ch == '+' || ch == '-') &&
                    (stack[top] == '*' || stack[top] == '/')))
            {
                postfix[j] = stack[top];
                j++;
                top--;
            }

            top++;
            stack[top] = ch;
        }
    }

    // Important step - Pop remaining operators
    while (top != -1)
    {
        postfix[j] = stack[top];
        j++;
        top--;
    }

    postfix[j] = '\0';

    printf("Postfix expression: %s\n", postfix);

    return 0;
}

/*

Infix to Postfix

Infix:
A + B * C

Postfix:
ABC*+

Algorithm:

1. Start
2. Read the infix expression
3. Scan the expression from left to right
4. If the character is an operand, add it to postfix
5. If the character is '(', push it into the stack
6. If the character is ')', pop operators until '(' is found
7. If the character is an operator:
   - Pop operators having higher precedence
   - Push the current operator
8. After scanning the expression, pop all remaining operators
9. Display the postfix expression
10. End

Operator Precedence:

Highest:
*  /

Lower:
+  -

Important Concept:

Operands → Directly go to postfix
Operators → Temporarily stored in stack

Time Complexity:
O(n)

Space Complexity:
O(n)

*/