#include <stdio.h>

int main()
{
    // Array Merging

    int arr1[100], arr2[100], arr3[200];
    int n1, n2, n3, i;

    printf("Enter the number of elements in first array: ");
    scanf("%d", &n1);

    printf("Enter the elements of first array:\n");

    for (i = 0; i < n1; i++)
    {
        scanf("%d", &arr1[i]);
    }

    printf("Enter the number of elements in second array: ");
    scanf("%d", &n2);

    printf("Enter the elements of second array:\n");

    for (i = 0; i < n2; i++)
    {
        scanf("%d", &arr2[i]);
    }

    n3 = n1 + n2;

    // Important step - Copy both arrays into the third array

    for (i = 0; i < n1; i++)
    {
        arr3[i] = arr1[i];
    }

    for (i = 0; i < n2; i++)
    {
        arr3[n1 + i] = arr2[i];
    }

    printf("Array after merging:\n");

    for (i = 0; i < n3; i++)
    {
        printf("%d ", arr3[i]);
    }

    return 0;
}

/*

Array Merging - Algorithm

1. Start
2. Declare two arrays arr1 and arr2 of size n1 and n2 respectively
3. Read the number of elements n1 and n2
4. Read the elements of arr1 and arr2
5. Declare a third array arr3 of size n1 + n2
6. For i = 0 to n1-1 do
7.     arr3[i] = arr1[i]
8. For i = 0 to n2-1 do
9.     arr3[n1 + i] = arr2[i]
10. For i = 0 to n1+n2-1 do
11.     Print arr3[i]
12. End

Time Complexity:
Best Case    = O(n1 + n2)
Average Case = O(n1 + n2)
Worst Case   = O(n1 + n2)

Space Complexity:
Best Case    = O(n1 + n2)
Average Case = O(n1 + n2)
Worst Case   = O(n1 + n2)
*/