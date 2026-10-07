#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX 100

int main()
{
    // Infix to Prefix Conversion

    char infix[MAX], prefix[MAX], stack[MAX];
    char reverse[MAX];
    int top = -1;
    int i, j = 0, length;
    char ch;

    printf("Enter an infix expression: ");
    scanf("%s", infix);

    length = strlen(infix);

    // Important step - Reverse the infix expression
    for (i = 0; i < length; i++)
    {
        reverse[i] = infix[length - 1 - i];

        // Change brackets while reversing
        if (reverse[i] == '(')
        {
            reverse[i] = ')';
        }
        else if (reverse[i] == ')')
        {
            reverse[i] = '(';
        }
    }

    reverse[length] = '\0';

    // Important step - Convert reversed expression to postfix
    for (i = 0; reverse[i] != '\0'; i++)
    {
        ch = reverse[i];

        // If character is an operand, add it to output
        if (isalnum(ch))
        {
            prefix[j] = ch;
            j++;
        }

        // If opening bracket, push into stack
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
                prefix[j] = stack[top];
                j++;
                top--;
            }

            if (top != -1)
            {
                top--;
            }
        }

        // If operator
        else
        {
            while (top != -1 && stack[top] != '(')
            {
                prefix[j] = stack[top];
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
        prefix[j] = stack[top];
        j++;
        top--;
    }

    prefix[j] = '\0';

    // Important step - Reverse the result to get prefix
    length = strlen(prefix);

    for (i = 0; i < length / 2; i++)
    {
        ch = prefix[i];
        prefix[i] = prefix[length - 1 - i];
        prefix[length - 1 - i] = ch;
    }

    printf("Prefix expression: %s\n", prefix);

    return 0;
}

/*

Infix to Prefix

Example:

Infix:
A+B*C

Prefix:
+A*BC

Algorithm:

1. Start
2. Read the infix expression
3. Reverse the infix expression
4. Replace '(' with ')' and ')' with '('
5. Convert the reversed expression into postfix
6. Reverse the obtained postfix expression
7. The result is the prefix expression
8. Display the prefix expression
9. End

Important Concept:

Infix:
A+B*C

Prefix:
+A*BC

Operator Placement:

Infix:
A + B

Prefix:
+ A B

Postfix:
A B +

Time Complexity:
O(n)

Space Complexity:
O(n)

*/