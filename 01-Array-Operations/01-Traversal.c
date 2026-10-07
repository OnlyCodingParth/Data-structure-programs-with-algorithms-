#include<stdio.h>
int main()
{
    int arr[100], n, i; 

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    printf("Enter the elements:\n");

    for(i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    printf("Array elements are: \n");

    //Important step- Visit each elements one by one
    for(i = 0; i < n; i++)
    {
        printf("%d", arr[i]);
    }

    return 0;
}

/*

Array Traversal - Algorithm

1. Start
2. Declare an array of size n
3. Read the number of elements n
4. Read the elements of the array
5. For i = 0 to n-1 do
6.     Print arr[i]
7. End

Time Complexity:
Best Case    = O(n)
Average Case = O(n)
Worst Case   = O(n)

Space Complexity:
Best Case    = O(1)
Average Case = O(1)
Worst Case   = O(1)

*/