#include <stdio.h>

#define MAX 100

int main()
{
    // Stack using Array

    int stack[MAX];
    int top = -1;
    int n, i;

    printf("Enter the number of elements to push: ");
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
        scanf("%d", &stack[++top]);
    }

    printf("Stack elements are:\n");

    // Display from top to bottom
    for (i = top; i >= 0; i--)
    {
        printf("%d\n", stack[i]);
    }

    return 0;
}

/*

Stack Using Array - Algorithm

1. Start
2. Create an array to store stack elements
3. Initialize top = -1
4. Read the number of elements
5. Check if the stack is full
6. Increment top
7. Insert the element at stack[top]
8. Repeat for all elements
9. Display the elements from top to bottom
10. End

Important Stack Operations:

Push  -> Insert an element
Pop   -> Remove the top element
Peek  -> View the top element

Initial Condition:

top = -1

When one element is inserted:

top = 0

When two elements are inserted:

top = 1

Time Complexity:
Push    = O(1)
Display = O(n)

Space Complexity:
O(n)

Principle:
LIFO (Last In, First Out)

*/