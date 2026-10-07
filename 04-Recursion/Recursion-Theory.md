# Recursion

## 1. Introduction

Recursion is a programming technique in which a function calls itself to solve a problem.

A recursive function solves a problem by breaking it into smaller versions of the same problem.

### Basic Structure

```c
return_type function(parameters)
{
    if (base_condition)
    {
        return value;
    }

    return function(smaller_problem);
}
```

A recursive function mainly contains:

1. **Base Case**
2. **Recursive Case**

---

# 2. Base Case

The base case is the condition that stops the recursion.

Without a proper base case, the function may continue calling itself indefinitely.

### Example

```c
if (n == 0)
{
    return 0;
}
```

When `n` becomes `0`, recursion stops.

---

# 3. Recursive Case

The recursive case is the part where a function calls itself with a smaller or simpler problem.

### Example

```c
return n + sum(n - 1);
```

Here, `sum()` calls itself with `n - 1`.

---

# 4. How Recursion Works

Consider:

```c
void display(int n)
{
    if (n == 0)
        return;

    printf("%d ", n);
    display(n - 1);
}
```

For `n = 3`:

```text
display(3)
   ↓
display(2)
   ↓
display(1)
   ↓
display(0)
   ↓
Stop
```

Each function call is stored in the **call stack** until the base case is reached.

---

# 5. Factorial Using Recursion

Factorial of a number is:

```text
n! = n × (n-1) × (n-2) × ... × 1
```

### Recursive Formula

```text
factorial(n) = n × factorial(n-1)
```

### Base Case

```text
factorial(0) = 1
```

### Example

```text
factorial(5)
= 5 × 4 × 3 × 2 × 1
= 120
```

### Complexity

* Time: O(n)
* Space: O(n)

---

# 6. Fibonacci Using Recursion

The Fibonacci series is a sequence in which each term is the sum of the previous two terms.

### Example

```text
0 1 1 2 3 5 8 13
```

### Recursive Formula

```text
F(n) = F(n-1) + F(n-2)
```

### Base Cases

```text
F(0) = 0
F(1) = 1
```

### Complexity

For the simple recursive implementation:

* Time: O(2^n)
* Space: O(n)

---

# 7. Sum of N Numbers Using Recursion

The sum of the first `n` natural numbers is calculated recursively.

### Recursive Formula

```text
sum(n) = n + sum(n-1)
```

### Base Case

```text
sum(0) = 0
```

### Example

```text
sum(5)
= 5 + 4 + 3 + 2 + 1
= 15
```

### Complexity

* Time: O(n)
* Space: O(n)

---

# 8. Reverse a Number Using Recursion

A number can be reversed by repeatedly extracting its last digit.

### Important Operations

```text
n % 10
```

gets the last digit.

```text
n / 10
```

removes the last digit.

### Example

```text
1234 → 4321
```

### Complexity

If `d` is the number of digits:

* Time: O(d)
* Space: O(d)

---

# 9. GCD Using Recursion

GCD means **Greatest Common Divisor**.

Euclid's algorithm can be implemented using recursion.

### Recursive Formula

```text
gcd(a, b) = gcd(b, a % b)
```

### Base Case

```text
gcd(a, 0) = a
```

### Example

```text
gcd(48, 18)

= gcd(18, 12)
= gcd(12, 6)
= gcd(6, 0)

GCD = 6
```

### Complexity

* Time: O(log(min(a,b)))
* Space: O(log(min(a,b)))

---

# 10. Advantages of Recursion

1. Makes some problems easier to understand.
2. Produces shorter code for certain problems.
3. Useful for problems that can be divided into smaller similar problems.
4. Useful in tree and graph algorithms.
5. Important for Divide and Conquer algorithms.

---

# 11. Disadvantages of Recursion

1. Uses extra memory because of function calls.
2. Recursive solutions can be slower than iterative solutions.
3. Too many recursive calls can cause stack overflow.
4. Debugging can be more difficult.
5. Incorrect or missing base cases can cause infinite recursion.

---

# 12. Applications of Recursion

Recursion is commonly used in:

* Factorial calculation
* Fibonacci series
* GCD
* Tree traversal
* Graph algorithms
* Binary Search
* Merge Sort
* Quick Sort
* Divide and Conquer
* Dynamic Programming

---

# 13. Recursion vs Iteration

| Recursion                            | Iteration                                  |
| ------------------------------------ | ------------------------------------------ |
| Function calls itself                | Uses loops                                 |
| Uses call stack                      | Usually uses less memory                   |
| Needs a base case                    | Needs a loop condition                     |
| Can be easier for recursive problems | Usually more memory-efficient              |
| May cause stack overflow             | Does not normally use recursive call stack |

---

# 14. Important Terms

### Base Case

Condition that stops recursion.

### Recursive Case

Part where the function calls itself.

### Call Stack

Memory area used to store active function calls.

### Stack Overflow

Occurs when too many recursive calls use the available stack memory.

---

# 15. Important Points for Exams

1. Recursion is a technique in which a function calls itself.
2. Every recursive solution should have a proper stopping condition.
3. The stopping condition is called the **base case**.
4. The self-calling part is called the **recursive case**.
5. Recursive calls are stored in the call stack.
6. Recursion is useful in Divide and Conquer algorithms.
7. Merge Sort and Quick Sort use recursion.
8. Trees are commonly processed using recursive algorithms.
9. Recursion may require more memory than iteration.
10. Missing or incorrect base cases can lead to infinite recursion.

---

# 16. Conclusion

Recursion is an important concept in Data Structures and Algorithms. It solves a problem by repeatedly solving smaller versions of the same problem. Understanding the base case, recursive case, and call stack is essential before learning advanced topics such as trees, Divide and Conquer, and Dynamic Programming.