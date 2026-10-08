#include <stdio.h>

void heapify(int heap[], int n, int i)
{
    int largest;
    int left;
    int right;
    int temp;

    largest = i;

    left = 2 * i + 1;
    right = 2 * i + 2;

    if (left < n && heap[left] > heap[largest])
    {
        largest = left;
    }

    if (right < n && heap[right] > heap[largest])
    {
        largest = right;
    }

    if (largest != i)
    {
        // Important step - Swap with the larger child.
        temp = heap[i];
        heap[i] = heap[largest];
        heap[largest] = temp;

        heapify(heap, n, largest);
    }
}

void buildMaxHeap(int heap[], int n)
{
    int i;

    // Important step - Start from the last non-leaf node.
    for (i = n / 2 - 1; i >= 0; i--)
    {
        heapify(heap, n, i);
    }
}

int main()
{
    int heap[100];
    int n, i;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter elements:\n");

    for (i = 0; i < n; i++)
    {
        scanf("%d", &heap[i]);
    }

    buildMaxHeap(heap, n);

    printf("\nMax Heap:\n");

    for (i = 0; i < n; i++)
    {
        printf("%d ", heap[i]);
    }

    printf("\n");

    return 0;
}

/*
    THEORY:

    A Max Heap is a complete binary tree in which every parent
    node is greater than or equal to its children.

    Max Heap property:

        Parent >= Left Child
        Parent >= Right Child

    Therefore, the largest element is always at the root.

    Example:

              90
            /    \
          70      80
         /  \    /
        40  50  60

    Array representation:

        90 70 80 40 50 60

    To build a Max Heap:

    1. Find the last non-leaf node.
    2. Start from that node.
    3. Apply heapify.
    4. Move toward the root.
    5. Continue until the root is heapified.

    Last non-leaf node:

        n / 2 - 1

    ALGORITHM:

    1. Read n elements.
    2. Store elements in an array.
    3. Start from index n/2 - 1.
    4. Apply Max Heapify.
    5. Move backward toward index 0.
    6. The resulting array represents a Max Heap.

    TIME COMPLEXITY:

    Building a Max Heap = O(n)

    Individual Heapify = O(log n)

    SPACE COMPLEXITY:

    O(log n) recursive stack space.

    IMPORTANT STEP:

    // Important step - Build the heap from the last non-leaf
    // node toward the root.
*/