#include<stdio.h>
int main()
{
    // Array Updation

    int arr[100], n, i, pos, value;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    printf("Enter the elements: \n");

    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    printf("Enter the position to update the element: ");
    scanf("%d", &pos);

    printf("Enter the new value: ");
    scanf("%d", &value);

    // Important step- Update the element at the specified position
    arr[pos - 1] = value;

    printf("Array after updating the element: \n");
    for (i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    
    return 0;
}

/*

Array Updation- Algorithm

1. Start
2. Declare an array of size n
3. Read the number of elements n
4. Read the elements of the array
5. Read the position where the element is to be updated
6. Read the new value
7. arr[pos - 1] = value
8. For i = 0 to n-1 do
9.     Print arr[i]
10. End

*/