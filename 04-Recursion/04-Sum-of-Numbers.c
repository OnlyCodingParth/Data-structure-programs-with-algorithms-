#include <stdio.h>

// Important function - Calculate sum using recursion
int sum(int n)
{
    // Important step - Base case
    if (n == 0)
    {
        return 0;
    }

    // Recursive case
    return n + sum(n - 1);
}

int main()
{
    // Sum of N Numbers using Recursion

    int n, result;

    printf("Enter a number: ");
    scanf("%d", &n);

    // Important step - Call the recursive function
    result = sum(n);

    printf("Sum of first %d natural numbers = %d\n", n, result);

    return 0;
}

/*

Sum of N Numbers using Recursion - Algorithm

1. Start
2. Read the number n
3. Check if n is 0
4. If n is 0, return 0
5. Otherwise, add n to sum(n - 1)
6. Continue until the base case is reached
7. Return the result
8. Display the sum
9. End

Example:

Input:
5

Calculation:
5 + 4 + 3 + 2 + 1

Output:
Sum of first 5 natural numbers = 15

Recursive Formula:

sum(n) = n + sum(n - 1)

Base Case:

sum(0) = 0

Time Complexity:
O(n)

Space Complexity:
O(n)

*/