#include <stdio.h>

void insertMaxHeap(int heap[], int *n, int value)
{
    int i;
    int parent;
    int temp;

    // Important step - Add the new element at the end.
    i = *n;
    heap[i] = value;
    (*n)++;

    // Important step - Move the element upward until Max Heap property is restored.
    while (i > 0)
    {
        parent = (i - 1) / 2;

        if (heap[parent] >= heap[i])
        {
            break;
        }

        temp = heap[parent];
        heap[parent] = heap[i];
        heap[i] = temp;

        i = parent;
    }
}

void display(int heap[], int n)
{
    int i;

    for (i = 0; i < n; i++)
    {
        printf("%d ", heap[i]);
    }

    printf("\n");
}

int main()
{
    int heap[100];
    int n;
    int i;
    int value;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter Max Heap elements:\n");

    for (i = 0; i < n; i++)
    {
        scanf("%d", &heap[i]);
    }

    printf("Enter element to insert: ");
    scanf("%d", &value);

    insertMaxHeap(heap, &n, value);

    printf("\nMax Heap after insertion:\n");
    display(heap, n);

    return 0;
}

/*
    THEORY:

    Heap insertion means adding a new element to a Heap while
    maintaining the Heap property.

    In a Max Heap:

        Parent >= Child

    The new element is first inserted at the end of the array.

    Then it is compared with its parent.

    If the new element is greater than its parent, they are swapped.

    This process continues until the Max Heap property is restored.

    This process is called:

        Heapify Up
        or
        Sift Up

    ALGORITHM:

    1. Insert the new element at the end of the Heap.
    2. Find its parent using:

           Parent = (i - 1) / 2

    3. Compare the element with its parent.
    4. If the element is greater, swap them.
    5. Continue moving upward.
    6. Stop when the parent is greater or equal, or the root is reached.

    TIME COMPLEXITY:

    O(log n)

    SPACE COMPLEXITY:

    O(1)

    IMPORTANT STEP:

    // Important step - Move the newly inserted element upward
    // until the Max Heap property is restored.
*/