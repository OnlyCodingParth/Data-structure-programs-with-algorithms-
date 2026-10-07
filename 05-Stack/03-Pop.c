#include <stdio.h>

#define MAX 100

int main()
{
    // Pop Operation

    int stack[MAX];
    int top = -1;
    int n, i, value;

    printf("Enter the number of elements in the stack: ");
    scanf("%d", &n);

    if (n > MAX)
    {
        printf("Stack Overflow\n");
        return 0;
    }

    printf("Enter the elements:\n");

    // Important step - Push elements into the stack
    for (i = 0; i < n; i++)
    {
        top++;
        scanf("%d", &stack[top]);
    }

    // Important step - Check whether the stack is empty
    if (top == -1)
    {
        printf("Stack Underflow\n");
        return 0;
    }

    // Important step - Remove the top element
    value = stack[top];
    top--;

    printf("Popped element = %d\n", value);

    printf("Stack after Pop operation:\n");

    for (i = top; i >= 0; i--)
    {
        printf("%d\n", stack[i]);
    }

    return 0;
}

/*

Pop Operation - Algorithm

1. Start
2. Check whether the stack is empty
3. If top == -1, display Stack Underflow
4. Otherwise, store stack[top] in a variable
5. Decrease top by 1
6. Display the popped element
7. End

Important Formula:

value = stack[top]
top = top - 1

Time Complexity:
O(1)

Space Complexity:
O(n)

Principle:
LIFO (Last In, First Out)

*/