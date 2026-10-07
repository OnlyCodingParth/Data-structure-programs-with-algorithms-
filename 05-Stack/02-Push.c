#include <stdio.h>

#define MAX 100

int main()
{
    // Push Operation

    int stack[MAX];
    int top = -1;
    int n, i, value;

    printf("Enter the number of elements to push: ");
    scanf("%d", &n);

    // Important step - Check whether the stack is full
    if (n > MAX)
    {
        printf("Stack Overflow\n");
        return 0;
    }

    // Important step - Push elements into the stack
    for (i = 0; i < n; i++)
    {
        printf("Enter element: ");
        scanf("%d", &value);

        top++;
        stack[top] = value;
    }

    printf("\nStack after Push operation:\n");

    for (i = top; i >= 0; i--)
    {
        printf("%d\n", stack[i]);
    }

    return 0;
}

/*

Push Operation - Algorithm

1. Start
2. Initialize top = -1
3. Check whether the stack is full
4. If the stack is full, display Stack Overflow
5. Otherwise, increment top
6. Insert the new element at stack[top]
7. Repeat for required elements
8. Display the stack
9. End

Important Formula:

top = top + 1
stack[top] = value

Time Complexity:
O(1) for one Push operation

Space Complexity:
O(n)

Principle:
LIFO (Last In, First Out)

*/