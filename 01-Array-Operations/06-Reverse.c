#include <stdio.h>

int main()
{
    // Array Reversal

    int arr[100], n, i, temp;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    printf("Enter the elements:\n");

    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    // Important step - Swap elements from both ends
    for (i = 0; i < n / 2; i++)
    {
        temp = arr[i];
        arr[i] = arr[n - 1 - i];
        arr[n - 1 - i] = temp;
    }

    printf("Array after reversal:\n");

    for (i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }

    return 0;
}

/*

Array Reversal- Algorithm

1. Start
2. Declare an array of size n
3. Read the number of elements n
4. Read the elements of the array
5. For i = 0 to n/2 do
6.     temp = arr[i]
7.     arr[i] = arr[n - 1 - i]
8.     arr[n - 1 - i] = temp
9. For i = 0 to n-1 do
10.     Print arr[i]
11. End

*/