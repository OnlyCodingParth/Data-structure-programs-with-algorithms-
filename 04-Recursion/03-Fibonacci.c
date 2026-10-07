#include <stdio.h>

// Important function - Find Fibonacci term using recursion
int fibonacci(int n)
{
    // Important step - Base cases
    if (n == 0)
    {
        return 0;
    }

    if (n == 1)
    {
        return 1;
    }

    // Recursive case
    return fibonacci(n - 1) + fibonacci(n - 2);
}

int main()
{
    // Fibonacci Series using Recursion

    int n, i;

    printf("Enter the number of terms: ");
    scanf("%d", &n);

    printf("Fibonacci Series:\n");

    // Important step - Generate each Fibonacci term
    for (i = 0; i < n; i++)
    {
        printf("%d ", fibonacci(i));
    }

    return 0;
}

/*

Fibonacci Series using Recursion - Algorithm

1. Start
2. Read the number of terms
3. Start from the 0th term
4. Call the recursive Fibonacci function
5. If n is 0, return 0
6. If n is 1, return 1
7. Otherwise, return fibonacci(n-1) + fibonacci(n-2)
8. Repeat for all required terms
9. Display the Fibonacci series
10. End

Example:

Input:
7

Output:
0 1 1 2 3 5 8

Recursive Formula:

F(n) = F(n-1) + F(n-2)

Base Cases:

F(0) = 0
F(1) = 1

Time Complexity:
O(2^n)

Space Complexity:
O(n)

*/