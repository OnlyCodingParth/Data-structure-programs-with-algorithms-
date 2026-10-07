#include <stdio.h>

int main()
{
    // Binary Search

    int arr[100], n, i, value;
    int low, high, mid, found = 0;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    printf("Enter the elements in sorted order:\n");

    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    printf("Enter the element to search: ");
    scanf("%d", &value);

    low = 0;
    high = n - 1;

    // Important step - Divide the search range into two halves
    while (low <= high)
    {
        mid = (low + high) / 2;

        if (arr[mid] == value)
        {
            printf("Element found at position %d\n", mid + 1);
            found = 1;
            break;
        }
        else if (arr[mid] < value)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }

    if (found == 0)
    {
        printf("Element not found\n");
    }

    return 0;
}

/*

Binary Search - Algorithm

1. Start
2. Read the number of elements
3. Read the sorted array
4. Read the element to be searched
5. Set low = 0 and high = n - 1
6. Find the middle element
7. If middle element equals the search value,
   display its position
8. If search value is greater than middle element,
   search the right half
9. If search value is smaller than middle element,
   search the left half
10. Repeat until the element is found or low > high
11. End

Time Complexity:
Best Case    = O(1)
Average Case = O(log n)
Worst Case   = O(log n)

Space Complexity:
O(1)

*/