#include <stdio.h>

// Important function - Function calls itself
void display(int n)
{
    if (n == 0)
    {
        return;
    }

    printf("%d ", n);

    display(n - 1);
}

int main()
{
    // Basic Recursion

    int n;

    printf("Enter a number: ");
    scanf("%d", &n);

    // Important step - Start the recursive function
    display(n);

    return 0;
}

/*

Recursion - Basic Example

Algorithm:

1. Start
2. Read a number n
3. Call the recursive function
4. Check the base condition
5. If n is 0, stop the function
6. Print n
7. Call the same function with n - 1
8. Repeat until the base condition is reached
9. End

Example:

Input:
5

Output:
5 4 3 2 1

Time Complexity:
O(n)

Space Complexity:
O(n)

Main Concept:
A function calling itself is called Recursion.

Important Terms:
1. Base Case
2. Recursive Case

*/