# Heap Sort

## 1. Introduction

Heap Sort is a comparison-based sorting algorithm that uses a Heap data structure.

Heap Sort is based on:

- Complete Binary Tree
- Max Heap
- Min Heap
- Heapify

Heap Sort can be performed using either a Max Heap or a Min Heap.

For the usual implementation:

- Max Heap → Ascending Order
- Min Heap → Descending Order

---

# 2. What is Heap Sort?

Heap Sort is a sorting algorithm that first converts the array into a Heap.

After building the Heap, the root element is repeatedly moved to its correct position.

For a Max Heap:

    Largest element = Root

Therefore, the largest element can be placed at the end of the array.

For a Min Heap:

    Smallest element = Root

Therefore, the smallest element can be placed at the end of the array.

---

# 3. Heap Sort Using Max Heap

To sort an array in ascending order:

1. Build a Max Heap.
2. The largest element becomes the root.
3. Swap the root with the last element.
4. Reduce the Heap size.
5. Apply Max Heapify.
6. Repeat until the array is sorted.

---

# 4. Example of Max Heap Sort

Consider:

    40 10 30 50 20

Build a Max Heap:

    50 20 30 10 40

Now swap root and last element:

    40 20 30 10 50

The 50 is now in its final position.

Heapify the remaining elements:

    40 20 30 10

After heapify:

    40 20 30 10

Swap root with last element of the unsorted portion:

    10 20 30 40 50

Heapify remaining portion.

Eventually:

    10 20 30 40 50

The array is sorted in ascending order.

---

# 5. Why Max Heap Gives Ascending Order

In a Max Heap:

    Largest element = Root

Every time the root is swapped with the last element:

    Largest remaining element
              ↓
       Final position

Therefore, the largest elements are placed from right to left.

At the end:

    Smallest → Largest

So the result is ascending order.

---

# 6. Heap Sort Using Min Heap

A Min Heap can also be used for Heap Sort.

In a Min Heap:

    Smallest element = Root

The smallest element is repeatedly moved to the end of the unsorted portion.

This produces:

    Largest → Smallest

Therefore, Min Heap normally gives descending order when the same root-to-end extraction approach is used.

---

# 7. Why Min Heap Gives Descending Order

In a Min Heap:

    Smallest element = Root

Every time the root is moved to the end:

    Smallest remaining element
              ↓
       Final position

Therefore, smaller elements are placed toward the right side.

At the end:

    Largest → Smallest

So the result is descending order.

---

# 8. Heap Sort Algorithm Using Max Heap

### Step 1

Build a Max Heap.

### Step 2

Swap the root with the last element.

### Step 3

Reduce the Heap size.

### Step 4

Apply Max Heapify.

### Step 5

Repeat Steps 2–4 until the Heap contains one element.

### Step 6

The array is sorted in ascending order.

---

# 9. Heap Sort Algorithm Using Min Heap

### Step 1

Build a Min Heap.

### Step 2

Swap the root with the last element.

### Step 3

Reduce the Heap size.

### Step 4

Apply Min Heapify.

### Step 5

Repeat Steps 2–4 until the Heap contains one element.

### Step 6

The array is sorted in descending order.

---

# 10. Heapify in Heap Sort

Heapify is a very important operation in Heap Sort.

After moving the root to the end, the remaining Heap may no longer satisfy the Heap property.

Therefore, Heapify is applied to the root.

For Max Heap:

    Max Heapify

For Min Heap:

    Min Heapify

Heapify restores the Heap property.

---

# 11. Building the Heap

To build a Heap from an array:

1. Find the last non-leaf node.
2. Start Heapify from that node.
3. Move toward the root.
4. Continue until index 0.

The last non-leaf node is:

    n / 2 - 1

where `n` is the number of elements.

---

# 12. Heap Sort Example

Suppose:

    20 50 10 40 30

Build Max Heap:

    50 40 10 20 30

Swap root with last:

    30 40 10 20 50

Heapify:

    40 30 10 20 50

Swap:

    20 30 10 40 50

Heapify:

    30 20 10 40 50

Swap:

    10 20 30 40 50

Final result:

    10 20 30 40 50

---

# 13. Time Complexity

Heap Sort has three main stages.

### Building Heap

    O(n)

### Repeated Heapify

There are approximately `n` Heapify operations.

Each Heapify takes:

    O(log n)

Therefore:

    O(n log n)

### Overall

    O(n log n)

Heap Sort has:

    Best Case    = O(n log n)
    Average Case = O(n log n)
    Worst Case   = O(n log n)

This is an important advantage of Heap Sort.

---

# 14. Space Complexity

Heap Sort can be performed in-place.

Therefore, its auxiliary space can be:

    O(1)

However, if recursive Heapify is used, the recursive call stack requires:

    O(log n)

In the programs in this folder, recursive Heapify is used, so the practical auxiliary stack space is:

    O(log n)

---

# 15. Is Heap Sort Stable?

Heap Sort is generally:

    Not Stable

A stable sorting algorithm preserves the relative order of equal elements.

Heap Sort does not guarantee this property.

---

# 16. Is Heap Sort In-Place?

Yes.

Heap Sort can sort the array within the same array without requiring another array of size `n`.

Therefore, Heap Sort is considered an:

    In-place sorting algorithm

---

# 17. Advantages of Heap Sort

1. Guaranteed O(n log n) worst-case time.
2. Can be performed in-place.
3. Does not require an additional array of size n.
4. Useful when worst-case performance is important.
5. Works efficiently for large datasets.
6. Based on a well-defined Heap structure.

---

# 18. Disadvantages of Heap Sort

1. It is not stable.
2. It is generally not as cache-friendly as some other sorting algorithms.
3. The implementation is more complex than simple sorting algorithms.
4. Heap operations can involve many element movements.
5. It is often slower in practice than Quick Sort for many typical datasets.

---

# 19. Heap Sort vs Quick Sort

| Feature | Heap Sort | Quick Sort |
|---------|-----------|------------|
| Average Time | O(n log n) | O(n log n) |
| Worst Time | O(n log n) | O(n²) |
| Stable | No | Usually No |
| In-place | Yes | Yes |
| Main Structure | Heap | Partitioning |
| Worst-case guarantee | Yes | No, in standard implementation |

---

# 20. Heap Sort vs Merge Sort

| Feature | Heap Sort | Merge Sort |
|---------|-----------|------------|
| Best Time | O(n log n) | O(n log n) |
| Average Time | O(n log n) | O(n log n) |
| Worst Time | O(n log n) | O(n log n) |
| Stable | No | Yes |
| In-place | Yes | Usually No for arrays |
| Extra Array | Not required | Usually required |

---

# 21. Important Heap Sort Concepts

### Max Heap

Used to produce ascending order with the standard root-to-end Heap Sort process.

### Min Heap

Used to produce descending order with the standard root-to-end Heap Sort process.

### Heapify

Restores the Heap property.

### Build Heap

Converts an array into a valid Heap.

### Root

Contains the highest-priority element:

    Max Heap → Maximum

    Min Heap → Minimum

---

# 22. Important Exam/Viva Questions

### Q1. What is Heap Sort?

Heap Sort is a comparison-based sorting algorithm that uses a Heap to sort elements.

### Q2. Which Heap is normally used for ascending order?

Max Heap.

### Q3. Which Heap is normally used for descending order?

Min Heap.

### Q4. What is the time complexity of Heap Sort?

    O(n log n)

### Q5. What is the worst-case complexity of Heap Sort?

    O(n log n)

### Q6. Is Heap Sort stable?

No.

### Q7. Is Heap Sort in-place?

Yes.

### Q8. What is the complexity of building a Heap?

    O(n)

### Q9. What operation is repeatedly used during Heap Sort?

Heapify.

### Q10. Where is the largest element in a Max Heap?

At the root.

---

# 23. Quick Revision

```text
                    HEAP SORT
                       |
             +---------+---------+
             |                   |
          MAX HEAP            MIN HEAP
             |                   |
       Ascending Order      Descending Order
             |                   |
       Largest at Root       Smallest at Root
             |                   |
          Swap Root            Swap Root
             |                   |
        Heapify Down         Heapify Down
             |                   |
             +---------+---------+
                       |
                  O(n log n)
                       |
                Not Stable
                       |
                  In-Place

24. Overall Concept

Heap Sort combines the power of a Heap with a sorting algorithm.

For ascending order:

Array
  ↓
Build Max Heap
  ↓
Largest element at root
  ↓
Swap root with last
  ↓
Reduce Heap size
  ↓
Max Heapify
  ↓
Repeat
  ↓
Sorted Array

For descending order:

Array
  ↓
Build Min Heap
  ↓
Smallest element at root
  ↓
Swap root with last
  ↓
Reduce Heap size
  ↓
Min Heapify
  ↓
Repeat
  ↓
Sorted Array

The most important complexity is:

Heap Sort = O(n log n)

for best, average and worst cases.

25. Conclusion

Heap Sort is an important comparison-based sorting algorithm based on the Heap data structure.

The most important concepts are:

Max Heap
Min Heap
Heapify
Build Heap
Root extraction
In-place sorting
O(n log n) time complexity
Not stable

Remember:

Max Heap → Ascending Order

Min Heap → Descending Order

Build Heap → O(n)

Heap Sort → O(n log n)

Heapify → O(log n)

Space → O(1) auxiliary for iterative in-place implementation
Recursive implementation may use O(log n) stack space.