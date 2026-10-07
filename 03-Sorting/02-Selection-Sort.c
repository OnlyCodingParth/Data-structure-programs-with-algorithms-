#include <stdio.h>

int main()
{
    // Selection Sort

    int arr[100], n, i, j, min, temp;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    printf("Enter the elements:\n");

    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    // Important step - Find the smallest element and place it at the correct position
    for (i = 0; i < n - 1; i++)
    {
        min = i;

        for (j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[min])
            {
                min = j;
            }
        }

        temp = arr[i];
        arr[i] = arr[min];
        arr[min] = temp;
    }

    printf("Array after sorting in ascending order:\n");

    for (i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }

    return 0;
}

/*

Selection Sort - Algorithm

1. Start
2. Read the number of elements
3. Read the elements of the array
4. Assume the first unsorted element is the minimum
5. Compare it with the remaining unsorted elements
6. Find the smallest element
7. Swap the smallest element with the first unsorted element
8. Repeat the process for the remaining elements
9. Print the sorted array
10. End

Time Complexity:
Best Case    = O(n^2)
Average Case = O(n^2)
Worst Case   = O(n^2)

Space Complexity:
O(1)

*/