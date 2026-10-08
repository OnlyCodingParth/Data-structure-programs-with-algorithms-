#include <stdio.h>

void heapify(int heap[], int n, int i)
{
    int smallest;
    int left;
    int right;
    int temp;

    smallest = i;

    left = 2 * i + 1;
    right = 2 * i + 2;

    if (left < n && heap[left] < heap[smallest])
    {
        smallest = left;
    }

    if (right < n && heap[right] < heap[smallest])
    {
        smallest = right;
    }

    if (smallest != i)
    {
        // Important step - Swap with the smaller child.
        temp = heap[i];
        heap[i] = heap[smallest];
        heap[smallest] = temp;

        heapify(heap, n, smallest);
    }
}

void buildMinHeap(int heap[], int n)
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

    buildMinHeap(heap, n);

    printf("\nMin Heap:\n");

    for (i = 0; i < n; i++)
    {
        printf("%d ", heap[i]);
    }

    printf("\n");

    return 0;
}

/*
    THEORY:

    A Min Heap is a complete binary tree in which every parent
    node is smaller than or equal to its children.

    Min Heap property:

        Parent <= Left Child
        Parent <= Right Child

    Therefore, the smallest element is always at the root.

    Example:

              20
            /    \
          40      30
         /  \    /
        70  50  60

    Array representation:

        20 40 30 70 50 60

    To build a Min Heap:

    1. Find the last non-leaf node.
    2. Start from that node.
    3. Apply Min Heapify.
    4. Move toward the root.
    5. Continue until the root is heapified.

    Last non-leaf node:

        n / 2 - 1

    ALGORITHM:

    1. Read n elements.
    2. Store elements in an array.
    3. Start from index n/2 - 1.
    4. Apply Min Heapify.
    5. Move backward toward index 0.
    6. The resulting array represents a Min Heap.

    TIME COMPLEXITY:

    Building a Min Heap = O(n)

    Individual Heapify = O(log n)

    SPACE COMPLEXITY:

    O(log n) recursive stack space.

    IMPORTANT STEP:

    // Important step - Build the heap from the last non-leaf
    // node toward the root.
*/