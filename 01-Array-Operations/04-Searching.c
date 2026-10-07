#include<stdio.h>
int main()
{
 
    // Array Searching

    int arr[100], n, i, value, found = 0;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    printf("Enter the elements: \n");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    printf("Enter the value to search: ");
    scanf("%d", &value);

    // Important step- Search for the value in the array
    for (i = 0; i < n; i++)
    {
        if (arr[i] == value)
        {
            found = 1;
            break;
        }
    }

    if (found == 1)
    {
        printf("Value %d found at position %d\n", value, i + 1);
    }
    else
    {
        printf("Value %d not found in the array\n", value);
    }

    return 0;
}