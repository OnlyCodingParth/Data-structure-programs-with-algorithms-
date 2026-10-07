#include <stdio.h>

int main()
{
    // Array Sorting

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

Array Sorting - Algorithm

1. Start
2. Declare an array of size n
3. Read the number of elements n
4. Read the elements of the array
5. For i = 0 to n-2 do
6.     For j = 0 to n-2-i do
7.         If arr[j] > arr[j+1] then
8.             Swap arr[j] and arr[j+1]
9. For i = 0 to n-1 do
10.     Print arr[i]
11. End

Time Complexity:
Best Case    = O(n^2)
Average Case = O(n^2)
Worst Case   = O(n^2)

Space Complexity:
Best Case    = O(1)
Average Case = O(1)
Worst Case   = O(1)
*/