#include <stdio.h>

int main()
{
    int heap[100];
    int n, i;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter heap elements:\n");

    for (i = 0; i < n; i++)
    {
        scanf("%d", &heap[i]);
    }

    printf("\nHeap elements are:\n");

    for (i = 0; i < n; i++)
    {
        printf("%d ", heap[i]);
    }

    printf("\n");

    return 0;
}

/*
    THEORY:

    A Heap is a complete binary tree that satisfies a special
    ordering property.

    A heap is commonly stored using an array.

    For an element at index i (0-based indexing):

        Parent       = (i - 1) / 2
        Left Child   = 2 * i + 1
        Right Child  = 2 * i + 2

    In this basic program, the entered elements are stored in
    an array representing the heap.

    ALGORITHM:

    1. Read the number of elements.
    2. Read the heap elements.
    3. Store the elements in an array.
    4. Display the elements.

    TIME COMPLEXITY:

    Creating/storing n elements = O(n)

    SPACE COMPLEXITY:

    O(n)

    IMPORTANT STEP:

    // Important step - Store heap elements in an array.
*/