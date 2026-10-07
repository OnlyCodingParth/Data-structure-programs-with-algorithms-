#include <stdio.h>

int main()
{
    // Bubble Sort

    int arr[100], n, i, j, temp;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    printf("Enter the elements:\n");

    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    // Important step - Compare adjacent elements and swap if needed
    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - 1 - i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

    printf("Array after sorting in ascending order:\n");

    for (i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }

    return 0;
}

/*

Bubble Sort - Algorithm

1. Start
2. Read the number of elements
3. Read the elements of the array
4. Compare two adjacent elements
5. If the first element is greater than the second element,
   swap them
6. Repeat the comparison for the remaining elements
7. Repeat the passes until the array is sorted
8. Print the sorted array
9. End

Time Complexity:
Best Case    = O(n^2)
Average Case = O(n^2)
Worst Case   = O(n^2)

Space Complexity:
O(1)

*/