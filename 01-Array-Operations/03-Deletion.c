#include<stdio.h>
int main()
{
    int arr[100], n, i, pos;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    printf("Enter the elements: \n");

    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    printf("Enter the position to delete the element: ");
    scanf("%d", &pos);

    // Imporatant Step- Shift elements to the left to remove the element at the specified position  
    for (i = pos - 1; i < n - 1; i++)
    {
        arr[i] = arr[i + 1];
    }

    n--; // Decrement the number of elements after deletion

    printf("Array elements after deletion are: \n");
    
    for (i = 0; i < n; i++)
    {
        printf("%d", arr[i]);
    }
    
    return 0;
}

/*

Array Deletion- Algorithm

1. Start
2. Declare an array of size n
3. Read the number of elements n
4. Read the elements of the array
5. Read the position where the element is to be deleted
6. For i = pos-1 to n-2 do
7.     arr[i] = arr[i + 1]
8. Decrement n
9. For i = 0 to n-1 do
10.     Print arr[i]
11. End

*/