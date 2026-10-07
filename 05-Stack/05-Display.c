#include <stdio.h>

#define MAX 100

int main()
{
    // Display Operation

    int stack[MAX];
    int top = -1;
    int n, i;

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
        printf("Stack is empty\n");
        return 0;
    }

    printf("Stack elements from top to bottom:\n");

    // Important step - Display elements from top to bottom
    for (i = top; i >= 0; i--)
    {
        printf("%d\n", stack[i]);
    }

    return 0;
}

/*

Display Operation - Algorithm

1. Start
2. Check whether the stack is empty
3. If top == -1, display "Stack is empty"
4. Otherwise, start from top
5. Display stack[i]
6. Decrease i
7. Repeat until i becomes 0
8. End

Important Point:

Stack is displayed from TOP to BOTTOM.

Time Complexity:
O(n)

Space Complexity:
O(n)

Principle:
LIFO (Last In, First Out)

*/