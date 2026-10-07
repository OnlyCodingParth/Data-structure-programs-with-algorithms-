#include <stdio.h>
#include <ctype.h>

#define MAX 100

int main()
{
    // Postfix Expression Evaluation

    char postfix[MAX];
    int stack[MAX];
    int top = -1;
    int i;
    int a, b, result;

    printf("Enter a postfix expression: ");
    scanf("%s", postfix);

    // Important step - Scan the postfix expression from left to right
    for (i = 0; postfix[i] != '\0'; i++)
    {
        // If character is a digit, push it into the stack
        if (isdigit(postfix[i]))
        {
            top++;
            stack[top] = postfix[i] - '0';
        }

        // If character is an operator, perform the operation
        else
        {
            b = stack[top];
            top--;

            a = stack[top];
            top--;

            if (postfix[i] == '+')
            {
                result = a + b;
            }
            else if (postfix[i] == '-')
            {
                result = a - b;
            }
            else if (postfix[i] == '*')
            {
                result = a * b;
            }
            else if (postfix[i] == '/')
            {
                result = a / b;
            }

            // Important step - Push the result back into the stack
            top++;
            stack[top] = result;
        }
    }

    // Final element in the stack is the answer
    result = stack[top];

    printf("Result = %d\n", result);

    return 0;
}

/*

Postfix Expression Evaluation

Example:

Postfix:
23*54*+

Working:

2 → Push
3 → Push
* → 2 * 3 = 6 → Push

5 → Push
4 → Push
* → 5 * 4 = 20 → Push

+ → 6 + 20 = 26 → Push

Result = 26

Algorithm:

1. Start
2. Read the postfix expression
3. Scan from left to right
4. If the character is an operand, push it into the stack
5. If the character is an operator:
   a. Pop the second operand
   b. Pop the first operand
   c. Perform the operation
   d. Push the result back into the stack
6. Repeat until the expression ends
7. The remaining element is the final result
8. Display the result
9. End

Important Point:

For an operator:

b = stack[top]
a = stack[top]

Then perform:

a operator b

Example:

Postfix:
23-

Result:

2 - 3 = -1

Not:

3 - 2

Time Complexity:
O(n)

Space Complexity:
O(n)

Supported Operators:
+  -  *  /

*/