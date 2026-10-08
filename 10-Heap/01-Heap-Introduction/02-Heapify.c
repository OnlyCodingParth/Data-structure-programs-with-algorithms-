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
        // Important step - Swap parent with the larger child.
        temp = heap[i];
        heap[i] = heap[largest];
        heap[largest] = temp;

        heapify(heap, n, largest);
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

    // Important step - Apply heapify to the root.
    heapify(heap, n, 0);

    printf("\nAfter Heapify:\n");

    for (i = 0; i < n; i++)
    {
        printf("%d ", heap[i]);
    }

    printf("\n");

    return 0;
}

/*
    THEORY:

    Heapify is the process of adjusting a node and its subtree
    so that the heap property is maintained.

    This program performs MAX-HEAPIFY.

    In a Max Heap:

        Parent >= Children

    For a node at index i:

        Left Child  = 2 * i + 1
        Right Child = 2 * i + 2

    The node is compared with its left and right children.

    The largest value is selected.

    If the largest value is not the current node, the values
    are swapped and heapify is continued recursively.

    ALGORITHM:

    1. Assume the current node is the largest.
    2. Find the left child.
    3. Find the right child.
    4. Compare the current node with both children.
    5. Find the largest value.
    6. If the largest value is not the current node, swap them.
    7. Recursively heapify the affected subtree.

    TIME COMPLEXITY:

    O(log n)

    SPACE COMPLEXITY:

    O(log n) because of recursive calls.

    NOTE:

    Heapify of a single node does not necessarily create a
    complete heap from an arbitrary array.

    Full heap construction is normally done by applying heapify
    from the last non-leaf node toward the root.

    IMPORTANT STEP:

    // Important step - Compare the node with its children and
    // move the largest value upward.
*/