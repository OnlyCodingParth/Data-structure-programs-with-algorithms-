#include<stdio.h>
int main()
{
    int arr[100], n, i, pos, value;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    printf("Enter the elements: \n");

    for(i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    printf("Enter the position where you want to insert the element: ");
    scanf("%d", &pos);

    printf("Enter the value to be inserted: ");
    scanf("%d", &value);

    //Important step- shift elements to the right to make space for the new element

    for(i = n; i >= pos; i--)
    {
        arr[i] = arr[i - 1];
    }

    //Place the new element at the specified position
    arr[pos - 1] = value; 

    n++; // Increment the number of elements after insertion

    printf("Array elements after insertion are: \n");
    
    for (i = 0; i < n; i++)
    {
        printf("%d", arr[i]);
    }

    return 0;
}

/*

Array Insertion- Algorithm

1. Start
2. Declare an array of size n
3. Read the number of elements n
4. Read the elements of the array
5. Read the position where the new element is to be inserted
6. Read the value of the new element
7. For i = n to pos do
8.     arr[i] = arr[i - 1]
9. arr[pos - 1] = value
10. Increment n
11. For i = 0 to n-1 do
12.     Print arr[i]
13. End

*/