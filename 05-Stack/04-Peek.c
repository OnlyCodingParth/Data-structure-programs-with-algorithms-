#include <stdio.h>

#define MAX 100

int main()
{
    // Peek Operation

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
        printf("Stack Underflow\n");
        return 0;
    }

    // Important step - Access the top element without removing it
    printf("Top element = %d\n", stack[top]);

    printf("Stack after Peek operation:\n");

    for (i = top; i >= 0; i--)
    {
        printf("%d\n", stack[i]);
    }

    return 0;
}

/*

Peek Operation - Algorithm

1. Start
2. Check whether the stack is empty
3. If top == -1, display Stack Underflow
4. Otherwise, access stack[top]
5. Display the top element
6. Do not change top
7. End

Important Formula:

stack[top]

Time Complexity:
O(1)

Space Complexity:
O(n)

Important Point:
Peek only views the top element.
It does not remove the element.

*/