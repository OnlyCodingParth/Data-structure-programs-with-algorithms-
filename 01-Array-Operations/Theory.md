# Array Operations — Complete Theory

## Introduction

An **array** is a linear data structure used to store multiple elements of the **same data type** in a continuous block of memory.

Each element of an array is accessed using an **index**.

In C, array indexing starts from **0**.

For example:

```text
int arr[5] = {10, 20, 30, 40, 50};

Index:    0   1   2   3   4
Value:   10  20  30  40  50
```

Arrays support several basic operations that are commonly used in data structures.

The main array operations are:

1. Traversal
2. Insertion
3. Deletion
4. Searching
5. Updation
6. Reversal
7. Sorting
8. Merging

---

# 1. Array Traversal

## Definition

**Traversal** means visiting or accessing every element of an array one by one.

It is one of the simplest and most fundamental array operations.

## Working

The array is accessed from the first element to the last element using a loop.

Since C uses zero-based indexing, traversal generally starts from index `0` and continues until index `n - 1`.

### Example

```text
Array: 10 20 30 40 50

Traversal:
10 → 20 → 30 → 40 → 50
```

## Basic Logic

```text
Start from index 0
↓
Access the current element
↓
Move to the next index
↓
Continue until the last element
```

## Time Complexity

* **Best Case:** O(n)
* **Average Case:** O(n)
* **Worst Case:** O(n)

## Space Complexity

* **O(1)**

No extra array is required for traversal.

---

# 2. Array Insertion

## Definition

**Insertion** means adding a new element at a specified position in an array.

The new element can be inserted at:

* Beginning
* Middle
* End

## Working

When an element is inserted into the middle or beginning, the existing elements must be shifted **one position to the right** to create space.

### Example

Suppose:

```text
10 20 30 40
```

Insert `25` at position `3`.

Before insertion:

```text
10 20 30 40
```

Shift elements to the right:

```text
10 20 30 30 40
```

Insert `25`:

```text
10 20 25 30 40
```

## Basic Logic

```text
Choose the position
↓
Shift elements to the right
↓
Place the new element
↓
Increase the array size by 1
```

## Important Point

In C, the position given by the user is generally treated as **1-based**, while array indexing is **0-based**.

Therefore:

```c
arr[pos - 1] = value;
```

## Time Complexity

* **Beginning:** O(n)
* **Middle:** O(n)
* **End:** O(1) if space is available
* **Worst Case:** O(n)

## Space Complexity

* **O(1)** auxiliary space

---

# 3. Array Deletion

## Definition

**Deletion** means removing an existing element from a specified position in an array.

An element can be deleted from:

* Beginning
* Middle
* End

## Working

When an element is deleted, the elements after it are shifted **one position to the left** to fill the empty space.

### Example

Delete `30` from:

```text
10 20 30 40 50
```

After shifting:

```text
10 20 40 50
```

## Basic Logic

```text
Choose the position
↓
Remove the element
↓
Shift remaining elements to the left
↓
Decrease the array size by 1
```

## Important Operation

```c
arr[i] = arr[i + 1];
```

This moves the next element into the current position.

## Time Complexity

* **Beginning:** O(n)
* **Middle:** O(n)
* **End:** O(1)
* **Worst Case:** O(n)

## Space Complexity

* **O(1)**

---

# 4. Array Searching

## Definition

**Searching** means finding whether a particular element exists in an array and determining its position.

One of the simplest searching techniques for an array is **Linear Search**.

## Linear Search

In linear search, each element is checked one by one from the beginning until:

* The required element is found, or
* The end of the array is reached.

### Example

Search for `30`:

```text
10 20 30 40 50
```

Comparison:

```text
10 ≠ 30
20 ≠ 30
30 = 30 → Found
```

## Basic Logic

```text
Start from the first element
↓
Compare it with the required value
↓
If equal → Element found
↓
Otherwise → Move to the next element
↓
Continue until found or array ends
```

## Time Complexity — Linear Search

* **Best Case:** O(1)
* **Average Case:** O(n)
* **Worst Case:** O(n)

## Space Complexity

* **O(1)**

---

# 5. Array Updation

## Definition

**Updation** means changing or replacing the value of an existing element at a specified position.

Unlike insertion and deletion, updation does **not change the size of the array**.

### Example

Original array:

```text
10 20 30 40 50
```

Update position `3` with `100`.

Result:

```text
10 20 100 40 50
```

## Basic Logic

```text
Choose the position
↓
Choose the new value
↓
Replace the old value with the new value
```

The main operation is:

```c
arr[pos - 1] = value;
```

## Important Point

No shifting of elements is required.

The number of elements remains the same.

## Time Complexity

* **Best Case:** O(1)
* **Average Case:** O(1)
* **Worst Case:** O(1)

## Space Complexity

* **O(1)**

---

# 6. Array Reversal

## Definition

**Reversal** means changing the order of elements so that the first element becomes the last, the second becomes the second-last, and so on.

### Example

Original array:

```text
10 20 30 40 50
```

Reversed array:

```text
50 40 30 20 10
```

## Working

Elements are swapped from both ends of the array.

```text
First ↔ Last
Second ↔ Second-last
Third ↔ Third-last
```

For example:

```text
10 20 30 40 50

10 ↔ 50
20 ↔ 40

50 40 30 20 10
```

The middle element does not need to be swapped when the array has an odd number of elements.

## Basic Logic

```text
Start from both ends
↓
Swap the elements
↓
Move toward the center
↓
Continue until the middle is reached
```

## Important Operation

A temporary variable is commonly used for swapping:

```c
temp = arr[i];
arr[i] = arr[n - 1 - i];
arr[n - 1 - i] = temp;
```

## Time Complexity

* **O(n)**

## Space Complexity

* **O(1)**

Only a temporary variable is used.

---

# 7. Array Sorting

## Definition

**Sorting** means arranging the elements of an array in a particular order.

The two common orders are:

### Ascending Order

```text
10 20 30 40 50
```

### Descending Order

```text
50 40 30 20 10
```

For basic array programs, **Bubble Sort** is commonly used because its mechanism is easy to understand.

## Bubble Sort

Bubble Sort repeatedly compares **adjacent elements** and swaps them if they are in the wrong order.

### Example

Array:

```text
5 2 8 1
```

Compare adjacent elements:

```text
5 > 2 → Swap

2 5 8 1
```

Next:

```text
5 < 8 → No swap
```

Next:

```text
8 > 1 → Swap

2 5 1 8
```

The largest element gradually moves toward the end of the array.

This process is repeated until the array becomes sorted.

## Basic Logic

```text
Compare adjacent elements
↓
If they are in the wrong order, swap them
↓
Continue through the array
↓
Repeat the process for multiple passes
↓
Array becomes sorted
```

## Time Complexity

For standard Bubble Sort:

* **Best Case:** O(n²)
* **Average Case:** O(n²)
* **Worst Case:** O(n²)

With an optimized Bubble Sort using a swap flag:

* **Best Case:** O(n)
* **Average Case:** O(n²)
* **Worst Case:** O(n²)

## Space Complexity

* **O(1)**

Bubble Sort sorts the array in-place.

---

# 8. Array Merging

## Definition

**Merging** means combining two or more arrays into a single array.

For basic array merging, the elements of the first array are copied first, followed by the elements of the second array.

### Example

First array:

```text
10 20 30
```

Second array:

```text
40 50 60
```

Merged array:

```text
10 20 30 40 50 60
```

## Working

Suppose:

```text
arr1 = 10 20 30
arr2 = 40 50 60
```

First, copy `arr1`:

```text
arr3 = 10 20 30
```

Then copy `arr2` after `arr1`:

```text
arr3 = 10 20 30 40 50 60
```

## Basic Logic

```text
Create a third array
↓
Copy all elements of the first array
↓
Copy all elements of the second array after the first array
↓
The third array is the merged array
```

## Important Operation

```c
arr3[n1 + i] = arr2[i];
```

`n1` ensures that the second array starts after all elements of the first array.

## Time Complexity

If the first array contains `n1` elements and the second contains `n2` elements:

**O(n1 + n2)**

## Space Complexity

**O(n1 + n2)**

because a new array is used to store the merged result.

---

# Array Operations — Complexity Summary

| Operation             | Time Complexity | Space Complexity |
| --------------------- | --------------- | ---------------- |
| Traversal             | O(n)            | O(1)             |
| Insertion             | O(n)            | O(1)             |
| Deletion              | O(n)            | O(1)             |
| Searching (Linear)    | O(n)            | O(1)             |
| Updation              | O(1)            | O(1)             |
| Reversal              | O(n)            | O(1)             |
| Sorting (Bubble Sort) | O(n²)           | O(1)             |
| Merging               | O(n1 + n2)      | O(n1 + n2)       |

---

# Important Concepts to Remember

### 1. Array Indexing

C arrays use **zero-based indexing**.

```text
Position:  1   2   3   4   5
Index:     0   1   2   3   4
```

Therefore:

```c
arr[pos - 1]
```

is commonly used when the user enters a position starting from `1`.

### 2. Fixed Size

A normal C array has a fixed allocated size.

For example:

```c
int arr[100];
```

can store up to 100 integers.

The logical number of elements currently being used can be stored in `n`.

### 3. Shifting

**Insertion** generally requires shifting elements to the **right**.

**Deletion** generally requires shifting elements to the **left**.

### 4. Swapping

Reversal and sorting commonly use swapping.

A temporary variable can be used:

```c
temp = a;
a = b;
b = temp;
```

### 5. In-place Operations

An operation is called **in-place** when it uses only a small amount of extra memory instead of creating another array.

Examples:

* Updation → O(1)
* Reversal → O(1)
* Bubble Sort → O(1)

---

# Conclusion

Array operations are the foundation of many data structure concepts.

The eight basic operations covered in this folder are:

```text
Traversal
Insertion
Deletion
Searching
Updation
Reversal
Sorting
Merging
```

Understanding these operations helps in learning more advanced data structures such as:

* Linked Lists
* Stacks
* Queues
* Trees
* Graphs
* Hash Tables

The most important idea is to understand **how elements are accessed, shifted, compared, replaced, swapped, and combined** inside an array.