#include <stdio.h>

int main()
{
    // Linear Search

    int arr[100], n, i, value, found = 0;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    printf("Enter the elements:\n");

    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    printf("Enter the element to search: ");
    scanf("%d", &value);

    // Important step - Compare each element with the search value
    for (i = 0; i < n; i++)
    {
        if (arr[i] == value)
        {
            printf("Element found at position %d\n", i + 1);
            found = 1;
            break;
        }
    }

    if (found == 0)
    {
        printf("Element not found\n");
    }

    return 0;
}

/*

Linear Search - Algorithm

1. Start
2. Read the number of elements
3. Read the array elements
4. Read the element to be searched
5. Start from the first element
6. Compare each element with the search value
7. If the element is found, display its position
8. If the end of the array is reached, display "Element not found"
9. End

Time Complexity:
Best Case    = O(1)
Average Case = O(n)
Worst Case   = O(n)

Space Complexity:
O(1)

*/