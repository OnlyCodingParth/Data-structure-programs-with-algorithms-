#include <stdio.h>

// Important function - Reverse the number using recursion
int reverseNumber(int n, int reverse)
{
    // Important step - Base case
    if (n == 0)
    {
        return reverse;
    }

    // Take the last digit and add it to reverse
    reverse = reverse * 10 + n % 10;

    // Recursive case
    return reverseNumber(n / 10, reverse);
}

int main()
{
    // Reverse Number using Recursion

    int n, result;

    printf("Enter a number: ");
    scanf("%d", &n);

    // Important step - Call the recursive function
    result = reverseNumber(n, 0);

    printf("Reverse of %d = %d\n", n, result);

    return 0;
}

/*

Reverse Number using Recursion - Algorithm

1. Start
2. Read the number n
3. Extract the last digit using n % 10
4. Add the digit to the reverse number
5. Remove the last digit using n / 10
6. Call the function recursively
7. Repeat until n becomes 0
8. Return the reversed number
9. Display the result
10. End

Example:

Input:
1234

Calculation:

Last digit = 4
Reverse = 4

Last digit = 3
Reverse = 43

Last digit = 2
Reverse = 432

Last digit = 1
Reverse = 4321

Output:
Reverse of 1234 = 4321

Important Operations:

n % 10  -> Gets the last digit
n / 10  -> Removes the last digit

Time Complexity:
O(d)

Space Complexity:
O(d)

Where d = number of digits.

*/