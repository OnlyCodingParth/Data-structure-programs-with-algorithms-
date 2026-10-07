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

/*

Array Searching - Algorithm

1. Start
2. Declare an array of size n
3. Read the number of elements n
4. Read the elements of the array
5. Read the value to search
6. For i = 0 to n-1 do
7.     If arr[i] == value then
8.         found = 1
9.         Break
10. If found == 1 then
11.     Print "Value found at position i+1"
12. Else
13.     Print "Value not found in the array"
14. End

Time Complexity:
Best Case    = O(1)
Average Case = O(n)
Worst Case   = O(n)

Space Complexity:
Best Case    = O(1)
Average Case = O(1)
Worst Case   = O(1)
*/