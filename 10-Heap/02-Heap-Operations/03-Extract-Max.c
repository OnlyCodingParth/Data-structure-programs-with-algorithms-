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
        temp = heap[i];
        heap[i] = heap[largest];
        heap[largest] = temp;

        heapify(heap, n, largest);
    }
}

int extractMax(int heap[], int *n)
{
    int max;
    int temp;

    if (*n <= 0)
    {
        printf("Heap is empty.\n");
        return -1;
    }

    max = heap[0];

    // Important step - Move the last element to the root.
    heap[0] = heap[*n - 1];
    (*n)--;

    if (*n > 0)
    {
        heapify(heap, *n, 0);
    }

    return max;
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
    int max;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter Max Heap elements:\n");

    for (i = 0; i < n; i++)
    {
        scanf("%d", &heap[i]);
    }

    max = extractMax(heap, &n);

    if (max != -1)
    {
        printf("\nExtracted Maximum = %d\n", max);

        printf("Max Heap after extraction:\n");
        display(heap, n);
    }

    return 0;
}

/*
    THEORY:

    Extract-Max is an operation performed on a Max Heap.

    Since the largest element is always at the root:

        Maximum = heap[0]

    The root is removed.

    The last element is moved to the root.

    The Heap property may then be violated.

    Therefore, Heapify Down is performed to restore the Max Heap.

    ALGORITHM:

    1. Check whether the Heap is empty.
    2. Store the root value.
    3. Move the last element to the root.
    4. Decrease the Heap size.
    5. Apply Max Heapify from the root.
    6. Return the removed maximum value.

    TIME COMPLEXITY:

    O(log n)

    SPACE COMPLEXITY:

    O(log n) because of recursive heapify.

    IMPORTANT STEP:

    // Important step - Replace the root with the last element
    // and apply Max Heapify.
*/