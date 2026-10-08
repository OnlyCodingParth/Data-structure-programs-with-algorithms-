# Heap Operations

## 1. Introduction

Heap operations are used to add, remove and access elements while maintaining the Heap property.

The important Heap operations are:

1. Insertion
2. Deletion
3. Extract-Max
4. Extract-Min
5. Heapify Up
6. Heapify Down

There are two main types of Heaps:

- Max Heap
- Min Heap

---

# 2. Max Heap

In a Max Heap:

    Parent >= Children

Therefore:

    Maximum element = Root

Example:

                90
              /    \
            70      80
           /  \    /  \
         40   50  60   30

---

# 3. Min Heap

In a Min Heap:

    Parent <= Children

Therefore:

    Minimum element = Root

Example:

                10
              /    \
            30      20
           /  \    /  \
         50   40  60   70

---

# 4. Heap Insertion

Heap insertion means adding a new element while maintaining the Heap property.

The new element is always added at the end of the Heap.

After insertion, the new element may violate the Heap property.

Therefore, it is moved upward.

This is called:

    Heapify Up

or:

    Sift Up

---

# 5. Insertion in Max Heap

Consider:

                50
              /    \
            30      40
           /  \
         10   20

Array:

    50 30 40 10 20

Insert:

    60

First place 60 at the end:

                50
              /    \
            30      40
           /  \    /
         10   20  60

60 is greater than its parent 40.

Swap:

                50
              /    \
            30      60
           /  \    /
         10   20  40

60 is greater than its parent 50.

Swap again:

                60
              /    \
            30      50
           /  \    /
         10   20  40

Now the Max Heap property is restored.

---

# 6. Insertion Algorithm

1. Add the new element at the end.
2. Find its parent.
3. Compare the element with its parent.
4. If the element violates the Heap property, swap them.
5. Continue upward.
6. Stop when the Heap property is restored.

For a zero-based array:

    Parent = (i - 1) / 2

---

# 7. Time Complexity of Insertion

A newly inserted element can move from a leaf to the root.

The height of a Heap is:

    O(log n)

Therefore:

    Insertion = O(log n)

Space complexity:

    O(1)

---

# 8. Heapify Up

Heapify Up is used after insertion.

The newly inserted element starts at the bottom.

It is repeatedly compared with its parent.

For Max Heap:

    If Child > Parent
        Swap

For Min Heap:

    If Child < Parent
        Swap

This continues until the correct position is reached.

---

# 9. Heap Deletion

Deletion means removing an element from a Heap.

In general deletion:

1. Find the element.
2. Replace it with the last element.
3. Reduce the Heap size.
4. Restore the Heap property.

The replacement element may need to move:

- Upward
- Downward

---

# 10. Deletion in Max Heap

Suppose:

                80
              /    \
            50      70
           /  \    /
         20   40  60

Delete 50.

Replace 50 with the last element 60.

The tree becomes:

                80
              /    \
            60      70
           /  \
         20   40

The Heap property is restored.

---

# 11. General Deletion Algorithm

1. Search for the element.
2. If it does not exist, stop.
3. Replace it with the last Heap element.
4. Reduce the Heap size.
5. Compare the replacement with its parent.
6. If necessary, move it upward.
7. Otherwise, move it downward using Heapify.
8. Continue until the Heap property is restored.

---

# 12. Time Complexity of General Deletion

Searching for an arbitrary element requires:

    O(n)

Restoring the Heap property requires:

    O(log n)

Therefore, general deletion is:

    O(n)

The O(n) comes from searching for the element.

---

# 13. Extract-Max

Extract-Max is specifically used with a Max Heap.

Since the maximum value is always at the root:

    Maximum = Root

Example:

                90
              /    \
            70      80
           /  \    /
         40   50  60

Extract-Max removes:

    90

The last element is moved to the root.

Then Max Heapify is performed.

---

# 14. Extract-Max Algorithm

1. Store the root.
2. Move the last element to the root.
3. Reduce Heap size.
4. Apply Max Heapify.
5. Return the removed root.

---

# 15. Extract-Max Complexity

The root is directly accessible:

    O(1)

Restoring the Heap requires:

    O(log n)

Therefore:

    Extract-Max = O(log n)

---

# 16. Extract-Min

Extract-Min is specifically used with a Min Heap.

Since the minimum value is always at the root:

    Minimum = Root

Example:

                10
              /    \
            30      20
           /  \    /
         50   40  60

Extract-Min removes:

    10

The last element is moved to the root.

Then Min Heapify is performed.

---

# 17. Extract-Min Algorithm

1. Store the root.
2. Move the last element to the root.
3. Reduce Heap size.
4. Apply Min Heapify.
5. Return the removed root.

---

# 18. Extract-Min Complexity

The root is directly accessible:

    O(1)

Restoring the Heap requires:

    O(log n)

Therefore:

    Extract-Min = O(log n)

---

# 19. Heapify Down

Heapify Down is used when a node may violate the Heap property with its children.

For Max Heap:

    Find the larger child.

For Min Heap:

    Find the smaller child.

Swap when required.

Continue downward until the Heap property is restored.

---

# 20. Heapify Up vs Heapify Down

| Feature | Heapify Up | Heapify Down |
|---------|------------|--------------|
| Main use | Insertion | Deletion/Extraction |
| Direction | Bottom to Top | Top to Bottom |
| Comparison | With Parent | With Children |
| Max Heap | Move larger value upward | Move smaller root downward |
| Min Heap | Move smaller value upward | Move larger root downward |
| Complexity | O(log n) | O(log n) |

---

# 21. Important Array Formulas

For zero-based indexing:

### Parent

    Parent = (i - 1) / 2

### Left Child

    Left Child = 2 * i + 1

### Right Child

    Right Child = 2 * i + 2

These formulas are extremely important for Heap implementation.

---

# 22. Example of Heap Operations

Initial Max Heap:

                50
              /    \
            30      40
           /  \
         10   20

Array:

    50 30 40 10 20

### Insert 60

Add 60 at the end:

    50 30 40 10 20 60

Heapify Up:

    50 30 60 10 20 40

Again:

    60 30 50 10 20 40

Final Heap:

                60
              /    \
            30      50
           /  \    /
         10   20  40

---

# 23. Extract-Max Example

Max Heap:

    60 30 50 10 20 40

Extract-Max:

    60

Move last element to root:

    40 30 50 10 20

Apply Heapify Down:

    50 30 40 10 20

Final Heap:

                50
              /    \
            30      40
           /  \
         10   20

---

# 24. Heap Operations Complexity

| Operation | Max Heap | Min Heap |
|-----------|----------|----------|
| Insert | O(log n) | O(log n) |
| Extract-Max | O(log n) | Not applicable |
| Extract-Min | Not applicable | O(log n) |
| General Delete | O(n) | O(n) |
| Heapify | O(log n) | O(log n) |
| Root Access | O(1) | O(1) |

General deletion is O(n) because finding an arbitrary element may require searching the entire Heap.

---

# 25. Advantages of Heap Operations

1. Insertion is efficient.
2. Root access is very fast.
3. Extract-Max is efficient.
4. Extract-Min is efficient.
5. Heapify is efficient.
6. Heaps are useful for Priority Queues.
7. Heaps are useful for scheduling systems.
8. Heaps are useful in Heap Sort.

---

# 26. Limitations

1. Searching for an arbitrary value is O(n).
2. Heap does not maintain complete sorted order.
3. Deleting an arbitrary value requires searching first.
4. Heap property must be maintained after modifications.

---

# 27. Important Exam/Viva Questions

### Q1. What is Heapify Up?

It is the process of moving a newly inserted element upward until the Heap property is restored.

### Q2. What is Heapify Down?

It is the process of moving an element downward until the Heap property is restored.

### Q3. Where is the maximum element in a Max Heap?

At the root.

### Q4. Where is the minimum element in a Min Heap?

At the root.

### Q5. What is the complexity of insertion?

    O(log n)

### Q6. What is the complexity of Extract-Max?

    O(log n)

### Q7. What is the complexity of Extract-Min?

    O(log n)

### Q8. What is the complexity of deleting an arbitrary element?

    O(n)

because the element may first need to be searched.

### Q9. What happens after removing the root?

The last element is moved to the root and Heapify Down is performed.

### Q10. Which operation is used after insertion?

Heapify Up.

---

# 28. Quick Revision

```text
                  HEAP OPERATIONS
                        |
          +-------------+-------------+
          |             |             |
       INSERT        DELETE       EXTRACT
          |             |             |
     Heapify Up     Restore       Root Removed
                        |             |
                 Up or Down       Last Element
                                   to Root
                                      |
                                Heapify Down

29. Overall Concept

Heap operations are based on maintaining the Heap property.

For insertion:

Add at the end
      ↓
Heapify Up
      ↓
Heap restored

For deletion:

Replace with last element
      ↓
Check position
      ↓
Heapify Up or Down
      ↓
Heap restored

For Extract-Max:

Remove root
      ↓
Move last element to root
      ↓
Max Heapify Down

For Extract-Min:

Remove root
      ↓
Move last element to root
      ↓
Min Heapify Down

The most important concept is:

Insertion → Heapify Up

Root deletion/extraction → Heapify Down
30. Conclusion

Heap operations allow us to efficiently maintain and modify a Heap.

The major operations are:

Insert
Delete
Extract-Max
Extract-Min
Heapify Up
Heapify Down

Important complexities:

Insert = O(log n)

Extract-Max = O(log n)

Extract-Min = O(log n)

Heapify = O(log n)

General Delete = O(n)