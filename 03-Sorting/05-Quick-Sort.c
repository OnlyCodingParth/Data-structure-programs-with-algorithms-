#include <stdio.h>

// Important function - Merge two sorted parts
void merge(int arr[], int low, int mid, int high)
{
    int temp[100];
    int i = low;
    int j = mid + 1;
    int k = low;

    // Compare elements from both parts and store the smaller one
    while (i <= mid && j <= high)
    {
        if (arr[i] < arr[j])
        {
            temp[k] = arr[i];
            i++;
        }
        else
        {
            temp[k] = arr[j];
            j++;
        }

        k++;
    }

    // Copy remaining elements from the left part
    while (i <= mid)
    {
        temp[k] = arr[i];
        i++;
        k++;
    }

    // Copy remaining elements from the right part
    while (j <= high)
    {
        temp[k] = arr[j];
        j++;
        k++;
    }

    // Copy sorted elements back to the original array
    for (i = low; i <= high; i++)
    {
        arr[i] = temp[i];
    }
}

// Important function - Divide the array into smaller parts
void mergeSort(int arr[], int low, int high)
{
    int mid;

    if (low < high)
    {
        mid = (low + high) / 2;

        mergeSort(arr, low, mid);
        mergeSort(arr, mid + 1, high);

        merge(arr, low, mid, high);
    }
}

int main()
{
    // Merge Sort

    int arr[100], n, i;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    printf("Enter the elements:\n");

    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    // Important step - Sort the array using Merge Sort
    mergeSort(arr, 0, n - 1);

    printf("Array after sorting in ascending order:\n");

    for (i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }

    return 0;
}

/*

Merge Sort - Algorithm

1. Start
2. Read the number of elements
3. Read the array elements
4. Divide the array into two halves
5. Recursively divide each half until single elements remain
6. Compare elements of the two parts
7. Merge them in sorted order
8. Repeat the merging process until the complete array is sorted
9. Print the sorted array
10. End

Time Complexity:
Best Case    = O(n log n)
Average Case = O(n log n)
Worst Case   = O(n log n)

Space Complexity:
O(n)

Main Concept:
Divide -> Sort -> Merge

*/