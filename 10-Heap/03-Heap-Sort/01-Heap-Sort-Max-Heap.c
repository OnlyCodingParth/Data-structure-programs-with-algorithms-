#include <stdio.h>

void heapify(int arr[], int n, int i)
{
    int largest;
    int left;
    int right;
    int temp;

    largest = i;
    left = 2 * i + 1;
    right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest])
    {
        largest = left;
    }

    if (right < n && arr[right] > arr[largest])
    {
        largest = right;
    }

    if (largest != i)
    {
        temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;

        heapify(arr, n, largest);
    }
}

void heapSort(int arr[], int n)
{
    int i;
    int temp;

    // Important step - Build a Max Heap.
    for (i = n / 2 - 1; i >= 0; i--)
    {
        heapify(arr, n, i);
    }

    // Important step - Move the largest element to the end.
    for (i = n - 1; i > 0; i--)
    {
        temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;

        heapify(arr, i, 0);
    }
}

void display(int arr[], int n)
{
    int i;

    for (i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }

    printf("\n");
}

int main()
{
    int arr[100];
    int n;
    int i;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter elements:\n");

    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    heapSort(arr, n);

    printf("\nSorted array in ascending order:\n");
    display(arr, n);

    return 0;
}

/*
    THEORY:

    Heap Sort is a comparison-based sorting algorithm that uses
    a Heap data structure.

    For ascending order, a Max Heap is normally used.

    Main steps:

    1. Build a Max Heap.
    2. The largest element is at the root.
    3. Swap the root with the last element.
    4. Reduce the Heap size.
    5. Apply Max Heapify.
    6. Repeat until all elements are sorted.

    ALGORITHM:

    1. Build a Max Heap from the array.
    2. Swap the root with the last element.
    3. Reduce the Heap size by one.
    4. Apply Max Heapify to the root.
    5. Repeat until only one element remains.

    RESULT:

    Max Heap + repeated root removal
    gives ascending order.

    TIME COMPLEXITY:

    Building Heap = O(n)

    Sorting = O(n log n)

    Overall = O(n log n)

    SPACE COMPLEXITY:

    O(log n) recursive stack space.

    IMPORTANT STEP:

    // Important step - Move the largest root element to the
    // end of the unsorted portion.
*/