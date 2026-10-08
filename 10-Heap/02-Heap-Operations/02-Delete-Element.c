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

void deleteElement(int heap[], int *n, int value)
{
    int i;
    int temp;

    i = -1;

    for (int j = 0; j < *n; j++)
    {
        if (heap[j] == value)
        {
            i = j;
            break;
        }
    }

    if (i == -1)
    {
        printf("Element not found.\n");
        return;
    }

    // Important step - Replace the deleted element with the last element.
    heap[i] = heap[*n - 1];
    (*n)--;

    if (i < *n)
    {
        if (i > 0)
        {
            int parent = (i - 1) / 2;

            if (heap[i] > heap[parent])
            {
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
            else
            {
                heapify(heap, *n, i);
            }
        }
        else
        {
            heapify(heap, *n, i);
        }
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

    printf("Enter element to delete: ");
    scanf("%d", &value);

    deleteElement(heap, &n, value);

    printf("\nMax Heap after deletion:\n");
    display(heap, n);

    return 0;
}

/*
    THEORY:

    Deletion means removing an element from a Heap while
    maintaining the Heap property.

    In this program, an element is searched first.

    After finding the element:

    1. Replace it with the last element.
    2. Reduce the Heap size.
    3. Restore the Heap property.

    The replacement element may need to move:

        Upward
        or
        Downward

    depending on its value.

    For a Max Heap:

        Parent >= Children

    ALGORITHM:

    1. Search for the element.
    2. If the element is not found, display a message.
    3. Replace the element with the last Heap element.
    4. Reduce the Heap size.
    5. Compare the replacement element with its parent.
    6. If it is greater than its parent, move it upward.
    7. Otherwise, apply Heapify Down.
    8. Display the resulting Heap.

    TIME COMPLEXITY:

    Searching for an arbitrary element = O(n)

    Restoring Heap property = O(log n)

    Overall = O(n)

    SPACE COMPLEXITY:

    O(log n) because of recursive heapify.

    IMPORTANT STEP:

    // Important step - Replace the deleted element with the
    // last element and restore the Heap property.
*/