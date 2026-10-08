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
        temp = heap[i];
        heap[i] = heap[smallest];
        heap[smallest] = temp;

        heapify(heap, n, smallest);
    }
}

int extractMin(int heap[], int *n)
{
    int min;

    if (*n <= 0)
    {
        printf("Heap is empty.\n");
        return -1;
    }

    min = heap[0];

    // Important step - Move the last element to the root.
    heap[0] = heap[*n - 1];
    (*n)--;

    if (*n > 0)
    {
        heapify(heap, *n, 0);
    }

    return min;
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
    int min;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter Min Heap elements:\n");

    for (i = 0; i < n; i++)
    {
        scanf("%d", &heap[i]);
    }

    min = extractMin(heap, &n);

    if (min != -1)
    {
        printf("\nExtracted Minimum = %d\n", min);

        printf("Min Heap after extraction:\n");
        display(heap, n);
    }

    return 0;
}

/*
    THEORY:

    Extract-Min is an operation performed on a Min Heap.

    Since the smallest element is always at the root:

        Minimum = heap[0]

    The root is removed.

    The last element is moved to the root.

    The Heap property may then be violated.

    Therefore, Min Heapify is performed to restore the Heap property.

    ALGORITHM:

    1. Check whether the Heap is empty.
    2. Store the root value.
    3. Move the last element to the root.
    4. Decrease the Heap size.
    5. Apply Min Heapify from the root.
    6. Return the removed minimum value.

    TIME COMPLEXITY:

    O(log n)

    SPACE COMPLEXITY:

    O(log n) because of recursive heapify.

    IMPORTANT STEP:

    // Important step - Replace the root with the last element
    // and apply Min Heapify.
*/