# Searching — Theory

## Introduction

**Searching** is the process of finding a particular element, called the **search key**, in a data structure and determining whether it exists and, if required, its position.

The two basic searching techniques are:

1. Linear Search
2. Binary Search

---

# 1. Linear Search

## Definition

**Linear Search** is a searching technique in which each element of an array is checked sequentially from the beginning until the required element is found or the end of the array is reached.

## Working

Consider:

```text
10  25  30  45  50
```

To search for `45`:

```text
10 ≠ 45
25 ≠ 45
30 ≠ 45
45 = 45 → Found
```

The elements are compared **one by one**.

## Algorithm

1. Start from the first element.
2. Compare the current element with the search key.
3. If both are equal, the element is found.
4. Otherwise, move to the next element.
5. Repeat until the element is found or the array ends.
6. If the end is reached, report that the element is not found.

## Requirements

* The array does **not** need to be sorted.
* It can be used on both sorted and unsorted data.

## Complexity

* Best Case: **O(1)**
* Average Case: **O(n)**
* Worst Case: **O(n)**
* Space Complexity: **O(1)**

## Advantages

* Simple and easy to implement.
* Works on unsorted arrays.
* Requires no extra memory.

## Disadvantages

* Slow for large datasets.
* May require checking every element.

## Applications

* Searching small arrays.
* Searching unsorted data.
* Simple lookup operations.

---

# 2. Binary Search

## Definition

**Binary Search** is a searching technique that repeatedly divides a **sorted array** into two halves and eliminates the half that cannot contain the required element.

## Requirement

The array must be **sorted** before applying Binary Search.

## Working

Consider:

```text
10  20  30  40  50  60  70
```

Search for `60`.

Middle element:

```text
40
```

Since:

```text
60 > 40
```

the left half can be ignored.

Now search only:

```text
50  60  70
```

The middle element is `60`, so the element is found.

## Algorithm

1. Set `low = 0` and `high = n - 1`.
2. Find the middle position:
   `mid = (low + high) / 2`
3. Compare the middle element with the search key.
4. If they are equal, the element is found.
5. If the search key is greater, search the right half.
6. If the search key is smaller, search the left half.
7. Repeat until the element is found or `low > high`.
8. If `low > high`, the element is not present.

## Complexity

* Best Case: **O(1)**
* Average Case: **O(log n)**
* Worst Case: **O(log n)**
* Space Complexity: **O(1)** for iterative implementation.

## Advantages

* Much faster than Linear Search for large sorted arrays.
* Reduces the search area by half after each comparison.
* Requires no extra array.

## Disadvantages

* Requires sorted data.
* Slightly more complex than Linear Search.
* Maintaining sorted data can require additional work.

## Applications

* Searching in sorted arrays.
* Searching large datasets.
* Database and indexing systems.
* Dictionary-like searching.

---

# Linear Search vs Binary Search

| Feature          | Linear Search       | Binary Search      |
| ---------------- | ------------------- | ------------------ |
| Data sorted?     | Not required        | Required           |
| Searching method | Sequential          | Divide and conquer |
| Best Case        | O(1)                | O(1)               |
| Average Case     | O(n)                | O(log n)           |
| Worst Case       | O(n)                | O(log n)           |
| Implementation   | Simple              | Moderate           |
| Suitable for     | Small/unsorted data | Large/sorted data  |

---

# Important Points

* **Linear Search** checks elements one by one.
* **Binary Search** repeatedly divides the search range into two halves.
* Binary Search requires a **sorted array**.
* Linear Search can work on **unsorted data**.
* For large sorted arrays, Binary Search is generally much faster.
* Both methods use **O(1) auxiliary space** in their iterative implementations.

## Conclusion

Searching is an important operation in data structures. **Linear Search** is simple and suitable for small or unsorted data, while **Binary Search** is more efficient for large, sorted data because it reduces the search space by half at every step.
