#include <stdio.h>

// Important function - Calculate factorial using recursion
int factorial(int n)
{
    // Important step - Base case
    if (n == 0 || n == 1)
    {
        return 1;
    }

    // Recursive case
    return n * factorial(n - 1);
}

int main()
{
    // Factorial using Recursion

    int n, result;

    printf("Enter a number: ");
    scanf("%d", &n);

    // Important step - Call the recursive function
    result = factorial(n);

    printf("Factorial of %d = %d\n", n, result);

    return 0;
}

/*

Factorial using Recursion - Algorithm

1. Start
2. Read the number n
3. Check if n is 0 or 1
4. If yes, return 1
5. Otherwise, multiply n by factorial(n - 1)
6. Continue until the base case is reached
7. Return the result
8. Display the factorial
9. End

Example:

Input:
5

Calculation:
5 * 4 * 3 * 2 * 1

Output:
Factorial of 5 = 120

Time Complexity:
O(n)

Space Complexity:
O(n)

Main Concept:
factorial(n) = n * factorial(n - 1)

Base Case:
factorial(0) = 1
factorial(1) = 1

*/