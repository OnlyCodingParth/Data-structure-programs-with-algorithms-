# Sorting

## 1. Introduction

Sorting is the process of arranging data in a particular order.

Usually, elements are arranged in:

* **Ascending Order:** Smallest to largest
* **Descending Order:** Largest to smallest

### Example

Unsorted:

`40 10 30 20`

Ascending:

`10 20 30 40`

Descending:

`40 30 20 10`

---

# 2. Types of Sorting

Sorting algorithms can be broadly classified into:

### Simple Sorting Algorithms

* Bubble Sort
* Selection Sort
* Insertion Sort

### Advanced Sorting Algorithms

* Merge Sort
* Quick Sort
* Heap Sort

---

# 3. Bubble Sort

Bubble Sort is a simple sorting algorithm that repeatedly compares adjacent elements and swaps them if they are in the wrong order.

### Working

1. Compare two adjacent elements.
2. If the first element is greater than the second, swap them.
3. Continue comparing adjacent elements.
4. Repeat the passes until the array is sorted.

### Example

`5 3 8 1`

After sorting:

`1 3 5 8`

### Important Point

In each pass, the largest unsorted element moves toward the end of the array.

### Complexity

* Best Case: O(n²)
* Average Case: O(n²)
* Worst Case: O(n²)
* Space: O(1)

### Advantages

* Simple to understand and implement.
* Requires very little extra memory.

### Disadvantages

* Slow for large datasets.
* Requires many comparisons and swaps.

---

# 4. Selection Sort

Selection Sort repeatedly finds the smallest element from the unsorted part of the array and places it at the correct position.

### Working

1. Find the smallest element.
2. Swap it with the first unsorted element.
3. Move to the next position.
4. Repeat until the array is sorted.

### Example

`64 25 12 22 11`

After sorting:

`11 12 22 25 64`

### Important Point

Selection Sort selects the minimum element and places it in its correct position.

### Complexity

* Best Case: O(n²)
* Average Case: O(n²)
* Worst Case: O(n²)
* Space: O(1)

### Advantages

* Simple implementation.
* Performs fewer swaps compared to Bubble Sort.

### Disadvantages

* Slow for large datasets.
* Always requires O(n²) comparisons.

---

# 5. Insertion Sort

Insertion Sort builds the sorted array one element at a time by inserting each element into its correct position.

### Working

1. Consider the first element as sorted.
2. Take the next element.
3. Compare it with the sorted elements.
4. Shift larger elements to the right.
5. Insert the element at its correct position.
6. Repeat for all elements.

### Example

`5 3 8 1`

After sorting:

`1 3 5 8`

### Important Point

Insertion Sort is similar to arranging playing cards in your hand.

### Complexity

* Best Case: O(n)
* Average Case: O(n²)
* Worst Case: O(n²)
* Space: O(1)

### Advantages

* Simple and easy to implement.
* Efficient for small or nearly sorted arrays.
* Requires no extra array.

### Disadvantages

* Slow for large and unsorted datasets.

---

# 6. Merge Sort

Merge Sort is a sorting algorithm based on the **Divide and Conquer** technique.

It divides the array into smaller parts, sorts them, and then merges them.

### Working

1. Divide the array into two halves.
2. Recursively divide the halves until single elements remain.
3. Compare elements from the smaller parts.
4. Merge them in sorted order.
5. Continue until the complete array is sorted.

### Example

`38 27 43 3`

Divide:

`38 27 | 43 3`

Further divide:

`38 | 27 | 43 | 3`

Merge:

`27 38 | 3 43`

Final:

`3 27 38 43`

### Complexity

* Best Case: O(n log n)
* Average Case: O(n log n)
* Worst Case: O(n log n)
* Space: O(n)

### Advantages

* Guaranteed O(n log n) time.
* Efficient for large datasets.
* Stable sorting algorithm.

### Disadvantages

* Requires extra memory.
* Implementation is more complex than basic sorting algorithms.

---

# 7. Quick Sort

Quick Sort is a sorting algorithm based on the **Divide and Conquer** technique.

It selects an element called a **pivot** and partitions the array around it.

### Working

1. Select a pivot element.
2. Place smaller elements on the left side.
3. Place larger elements on the right side.
4. The pivot reaches its correct position.
5. Recursively sort the left and right parts.

### Example

`10 7 8 9 1 5`

If `5` is selected as the pivot, elements smaller than `5` are placed on its left and larger elements on its right.

### Important Point

The main operation in Quick Sort is **partitioning**.

### Complexity

* Best Case: O(n log n)
* Average Case: O(n log n)
* Worst Case: O(n²)
* Average Space: O(log n)

### Advantages

* Fast in practice.
* Requires less extra memory than Merge Sort.
* Efficient for large datasets.

### Disadvantages

* Worst-case time can be O(n²).
* Performance depends on pivot selection.

---

# 8. Heap Sort

Heap Sort is a comparison-based sorting algorithm that uses a **Heap** data structure.

For ascending order, a **Max Heap** is generally used.

### Working

1. Build a Max Heap.
2. The largest element is at the root.
3. Swap the root with the last element.
4. Reduce the heap size.
5. Apply heapify to restore the Max Heap.
6. Repeat until the array is sorted.

### Important Point

Heap Sort repeatedly removes the largest element from the Max Heap and places it at the end.

### Complexity

* Best Case: O(n log n)
* Average Case: O(n log n)
* Worst Case: O(n log n)
* Space: O(1)

### Advantages

* Guaranteed O(n log n) time.
* Requires constant extra space.
* Suitable for large datasets.

### Disadvantages

* More complex than Bubble, Selection and Insertion Sort.
* Generally not stable.

---

# 9. Comparison of Sorting Algorithms

| Algorithm      |       Best |    Average |      Worst |     Space |
| -------------- | ---------: | ---------: | ---------: | --------: |
| Bubble Sort    |      O(n²) |      O(n²) |      O(n²) |      O(1) |
| Selection Sort |      O(n²) |      O(n²) |      O(n²) |      O(1) |
| Insertion Sort |       O(n) |      O(n²) |      O(n²) |      O(1) |
| Merge Sort     | O(n log n) | O(n log n) | O(n log n) |      O(n) |
| Quick Sort     | O(n log n) | O(n log n) |      O(n²) | O(log n)* |
| Heap Sort      | O(n log n) | O(n log n) | O(n log n) |      O(1) |

`*` Average auxiliary recursion space for the implementation used.

---

# 10. Stable and Unstable Sorting

A **stable sorting algorithm** maintains the relative order of equal elements.

### Stable Sorting

* Bubble Sort
* Insertion Sort
* Merge Sort

### Generally Unstable Sorting

* Selection Sort
* Quick Sort
* Heap Sort

---

# 11. In-Place Sorting

An in-place sorting algorithm requires very little additional memory.

Examples:

* Bubble Sort
* Selection Sort
* Insertion Sort
* Quick Sort
* Heap Sort

Merge Sort generally requires additional memory for merging.

---

# 12. Applications of Sorting

Sorting is used in:

* Searching data efficiently
* Database management
* Ranking systems
* Student mark lists
* E-commerce product ordering
* Data analysis
* Scheduling
* File and record management

---

# 13. Important Points for Exams

1. **Bubble Sort** compares adjacent elements.
2. **Selection Sort** selects the minimum element.
3. **Insertion Sort** inserts an element into the sorted part.
4. **Merge Sort** uses Divide and Conquer and merging.
5. **Quick Sort** uses a pivot and partitioning.
6. **Heap Sort** uses a Heap data structure.
7. Binary Search works efficiently on sorted data.
8. Merge Sort has guaranteed O(n log n) time.
9. Quick Sort has O(n²) worst-case time.
10. Heap Sort has O(n log n) worst-case time and O(1) extra space.

---

# 14. Conclusion

Sorting is an important operation in Data Structures and Algorithms. Different sorting algorithms have different advantages and complexities. Simple algorithms such as Bubble, Selection and Insertion Sort are easy to understand, while Merge, Quick and Heap Sort are more efficient for large datasets.