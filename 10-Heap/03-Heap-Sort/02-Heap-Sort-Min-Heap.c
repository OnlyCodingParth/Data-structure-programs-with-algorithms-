#include <stdio.h>

void heapify(int arr[], int n, int i)
{
    int smallest;
    int left;
    int right;
    int temp;

    smallest = i;
    left = 2 * i + 1;
    right = 2 * i + 2;

    if (left < n && arr[left] < arr[smallest])
    {
        smallest = left;
    }

    if (right < n && arr[right] < arr[smallest])
    {
        smallest = right;
    }

    if (smallest != i)
    {
        temp = arr[i];
        arr[i] = arr[smallest];
        arr[smallest] = temp;

        heapify(arr, n, smallest);
    }
}

void heapSort(int arr[], int n)
{
    int i;
    int temp;

    // Important step - Build a Min Heap.
    for (i = n / 2 - 1; i >= 0; i--)
    {
        heapify(arr, n, i);
    }

    // Important step - Move the smallest element to the end.
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

    printf("\nSorted array in descending order:\n");
    display(arr, n);

    return 0;
}

/*
    THEORY:

    Heap Sort can also be performed using a Min Heap.

    When a Min Heap is used:

        Smallest element = Root

    The root is repeatedly moved to the end of the unsorted
    portion.

    This produces the elements in descending order.

    Main steps:

    1. Build a Min Heap.
    2. Swap the root with the last element.
    3. Reduce the Heap size.
    4. Apply Min Heapify.
    5. Repeat until the array is sorted.

    ALGORITHM:

    1. Build a Min Heap from the array.
    2. Swap the root with the last element.
    3. Reduce the Heap size by one.
    4. Apply Min Heapify to the root.
    5. Repeat until one element remains.

    RESULT:

    Min Heap + repeated root removal
    gives descending order.

    TIME COMPLEXITY:

    Building Heap = O(n)

    Sorting = O(n log n)

    Overall = O(n log n)

    SPACE COMPLEXITY:

    O(log n) recursive stack space.

    IMPORTANT STEP:

    // Important step - Move the smallest root element to the
    // end of the unsorted portion.
*/