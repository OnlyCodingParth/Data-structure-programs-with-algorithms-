#include <stdio.h>

// Important function - Maintain Max Heap property
void heapify(int arr[], int n, int i)
{
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    int temp;

    if (left < n && arr[left] > arr[largest])
    {
        largest = left;
    }

    if (right < n && arr[right] > arr[largest])
    {
        largest = right;
    }

    // Important step - Swap if parent is not the largest
    if (largest != i)
    {
        temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;

        heapify(arr, n, largest);
    }
}

int main()
{
    // Heap Sort

    int arr[100], n, i, temp;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    printf("Enter the elements:\n");

    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    // Important step - Build a Max Heap
    for (i = n / 2 - 1; i >= 0; i--)
    {
        heapify(arr, n, i);
    }

    // Important step - Move the largest element to the end
    for (i = n - 1; i > 0; i--)
    {
        temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;

        heapify(arr, i, 0);
    }

    printf("Array after sorting in ascending order:\n");

    for (i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }

    return 0;
}

/*

Heap Sort - Algorithm

1. Start
2. Read the number of elements
3. Read the array elements
4. Build a Max Heap from the array
5. Swap the root element with the last element
6. Reduce the heap size
7. Apply heapify to maintain the Max Heap
8. Repeat until only one element remains
9. Print the sorted array
10. End

Time Complexity:
Best Case    = O(n log n)
Average Case = O(n log n)
Worst Case   = O(n log n)

Space Complexity:
O(1)

Main Concept:
Build Max Heap -> Swap Maximum -> Heapify -> Repeat

*/