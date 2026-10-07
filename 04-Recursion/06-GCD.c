#include <stdio.h>

// Important function - Find GCD using recursion
int gcd(int a, int b)
{
    // Important step - Base case
    if (b == 0)
    {
        return a;
    }

    // Recursive case
    return gcd(b, a % b);
}

int main()
{
    // GCD using Recursion

    int a, b, result;

    printf("Enter two numbers: ");
    scanf("%d %d", &a, &b);

    // Important step - Call the recursive function
    result = gcd(a, b);

    printf("GCD of %d and %d = %d\n", a, b, result);

    return 0;
}

/*

GCD using Recursion - Algorithm

1. Start
2. Read two numbers a and b
3. Check if b is 0
4. If b is 0, return a
5. Otherwise, call gcd(b, a % b)
6. Repeat until b becomes 0
7. Return the GCD
8. Display the result
9. End

Example:

Input:
48 18

Calculation:

gcd(48, 18)
= gcd(18, 48 % 18)
= gcd(18, 12)
= gcd(12, 18 % 12)
= gcd(12, 6)
= gcd(6, 12 % 6)
= gcd(6, 0)

Therefore:
GCD = 6

Recursive Formula:

gcd(a, b) = gcd(b, a % b)

Base Case:

gcd(a, 0) = a

Time Complexity:
O(log(min(a, b)))

Space Complexity:
O(log(min(a, b)))

*/