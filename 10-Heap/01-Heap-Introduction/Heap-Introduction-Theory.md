# Heap - Introduction

## 1. Introduction

A Heap is a special type of binary tree that satisfies a specific ordering property.

A Heap is always a:

- Complete Binary Tree
- Tree with a special parent-child relationship

There are two main types of heaps:

1. Max Heap
2. Min Heap

Heaps are commonly implemented using arrays instead of pointers.

---

# 2. What is a Heap?

A Heap is a complete binary tree in which the nodes follow a specific heap property.

There are two main heap properties.

### Max Heap

In a Max Heap:

    Parent >= Children

Therefore, the largest element is always at the root.

Example:

                90
              /    \
            70      80
           /  \    /  \
         40   50  60   30

Here:

    90 >= 70 and 80
    70 >= 40 and 50
    80 >= 60 and 30

Therefore, it is a valid Max Heap.

---

### Min Heap

In a Min Heap:

    Parent <= Children

Therefore, the smallest element is always at the root.

Example:

                20
              /    \
            40      30
           /  \    /  \
         70   50  60   80

Here:

    20 <= 40 and 30
    40 <= 70 and 50
    30 <= 60 and 80

Therefore, it is a valid Min Heap.

---

# 3. Complete Binary Tree

A Heap must always be a Complete Binary Tree.

A Complete Binary Tree is a binary tree in which:

- All levels are completely filled except possibly the last level.
- The last level is filled from left to right.

Example:

                10
              /    \
            20      30
           /  \    /
         40   50  60

This is a Complete Binary Tree.

---

# 4. Heap Representation Using Array

A Heap is commonly stored using an array.

Example:

                50
              /    \
            30      40
           /  \    /
         10   20  35

Array representation:

    50 30 40 10 20 35

No extra pointers are required.

This makes array-based heap implementation memory efficient.

---

# 5. Array Index Formulas

For a heap stored using a zero-based array:

For a node at index `i`:

### Parent

    Parent = (i - 1) / 2

### Left Child

    Left Child = 2 * i + 1

### Right Child

    Right Child = 2 * i + 2

Example:

Array:

    50 30 40 10 20 35

Index:

    0  1  2  3  4  5

For node 30 at index 1:

    Left Child  = 2(1) + 1 = 3
    Right Child = 2(1) + 2 = 4

Therefore:

    Left Child = 10
    Right Child = 20

---

# 6. Parent and Child Relationships

Consider:

                50
              /    \
            30      40
           /  \    /
         10   20  35

Array:

    Index:  0   1   2   3   4   5
    Value: 50  30  40  10  20  35

For index 0:

    Left Child = 1
    Right Child = 2

For index 1:

    Left Child = 3
    Right Child = 4

For index 2:

    Left Child = 5
    Right Child = 6

Since index 6 does not exist, node 40 has only one child.

---

# 7. Max Heap

A Max Heap is a Complete Binary Tree where:

    Parent >= Children

The maximum element is always present at the root.

Example:

                90
              /    \
            70      80
           /  \    /  \
         40   50  60   30

Array:

    90 70 80 40 50 60 30

Important property:

    Maximum Element = Root

---

# 8. Min Heap

A Min Heap is a Complete Binary Tree where:

    Parent <= Children

The minimum element is always present at the root.

Example:

                10
              /    \
            30      20
           /  \    /  \
         50   40  60   70

Array:

    10 30 20 50 40 60 70

Important property:

    Minimum Element = Root

---

# 9. Heapify

Heapify is the process of adjusting a node and its subtree so that the heap property is maintained.

There are two main forms:

1. Max Heapify
2. Min Heapify

---

## Max Heapify

Max Heapify ensures that the largest value among:

- Current node
- Left child
- Right child

moves to the current position.

Example:

                40
              /    \
            70      50

The largest value is 70.

After Max Heapify:

                70
              /    \
            40      50

---

## Min Heapify

Min Heapify ensures that the smallest value among:

- Current node
- Left child
- Right child

moves to the current position.

Example:

                60
              /    \
            30      40

The smallest value is 30.

After Min Heapify:

                30
              /    \
            60      40

---

# 10. Building a Max Heap

To build a Max Heap from an arbitrary array:

1. Find the last non-leaf node.
2. Apply Max Heapify.
3. Move to the previous node.
4. Continue until the root is reached.

The last non-leaf node is:

    n / 2 - 1

where `n` is the number of elements.

Example:

Array:

    10 20 30 40 50

Start from:

    n / 2 - 1

    = 5 / 2 - 1
    = 1

Therefore, heapify starts from index 1 and moves toward index 0.

---

# 11. Building a Min Heap

To build a Min Heap from an arbitrary array:

1. Find the last non-leaf node.
2. Apply Min Heapify.
3. Move to the previous node.
4. Continue until the root is reached.

The last non-leaf node is:

    n / 2 - 1

---

# 12. Leaf Nodes in a Heap

In a zero-based array representation, all nodes from:

    n / 2

to:

    n - 1

are leaf nodes.

Example:

If:

    n = 7

Then:

    n / 2 = 3

Therefore, indices:

    3, 4, 5, 6

are leaf nodes.

Leaf nodes do not have children, so heapify is not required for them.

---

# 13. Heap Height

A Heap is a Complete Binary Tree.

Therefore, its height is approximately:

    O(log n)

where `n` is the number of elements.

This is why operations such as heapify, insertion and deletion can be efficient.

---

# 14. Heap Creation

Heap creation means creating a heap structure from a collection of elements.

The basic steps are:

1. Read the elements.
2. Store them in an array.
3. Determine whether a Max Heap or Min Heap is required.
4. Apply the appropriate heapify operation.
5. Continue from the last non-leaf node toward the root.

---

# 15. Max Heap Creation Example

Suppose the input is:

    10 30 20 50 40

After building a Max Heap, one possible result is:

    50 40 20 10 30

Tree representation:

                50
              /    \
            40      20
           /  \
         10   30

Check:

    50 >= 40 and 20
    40 >= 10 and 30

Therefore, the Max Heap property is satisfied.

---

# 16. Min Heap Creation Example

Suppose the input is:

    50 30 20 10 40

After building a Min Heap, one possible result is:

    10 30 20 50 40

Tree representation:

                10
              /    \
            30      20
           /  \
         50   40

Check:

    10 <= 30 and 20
    30 <= 50 and 40

Therefore, the Min Heap property is satisfied.

---

# 17. Heap vs Binary Search Tree

| Feature | Heap | Binary Search Tree |
|---------|------|--------------------|
| Main property | Parent-child ordering | Left < Root < Right |
| Tree type | Complete Binary Tree | Binary Tree |
| Root | Maximum or minimum | Depends on inserted values |
| Searching | Not efficient for arbitrary value | Efficient when balanced |
| Minimum/Maximum | Easily available at root | Minimum/maximum at extreme node |
| Array implementation | Common | Usually pointer based |
| Main use | Priority Queue, Heap Sort | Searching and ordered data |

---

# 18. Heap vs Normal Binary Tree

| Feature | Binary Tree | Heap |
|---------|-------------|------|
| Complete tree required | No | Yes |
| Ordering property | No fixed rule | Required |
| Max/Min at root | Not guaranteed | Guaranteed |
| Array representation | Possible | Very common |
| Main use | Hierarchical data | Priority-based processing |

---

# 19. Time Complexity

### Heapify

For a single node:

    O(log n)

because the element can move down through the height of the heap.

### Build Heap

Building a complete heap:

    O(n)

### Finding Maximum in Max Heap

    O(1)

The maximum is at the root.

### Finding Minimum in Min Heap

    O(1)

The minimum is at the root.

---

# 20. Space Complexity

For storing `n` heap elements:

    O(n)

An array of size `n` is used to store the heap.

For recursive heapify:

    O(log n)

additional stack space may be used.

---

# 21. Advantages of Heap

1. Efficient access to the maximum element in a Max Heap.
2. Efficient access to the minimum element in a Min Heap.
3. Efficient insertion and deletion.
4. Complete tree structure avoids unnecessary empty spaces.
5. Array implementation is simple.
6. No extra child pointers are required.
7. Useful for implementing Priority Queues.
8. Useful for Heap Sort.

---

# 22. Disadvantages of Heap

1. Searching for an arbitrary element is not efficient.
2. Heap does not maintain complete sorted order.
3. Implementation is more complex than a simple array.
4. Maintaining the heap property is required after modifications.
5. A heap is mainly useful when priority-based access is required.

---

# 23. Applications of Heap

Heaps are used in:

- Priority Queues
- Heap Sort
- CPU scheduling
- Job scheduling
- Operating systems
- Graph algorithms
- Dijkstra's algorithm
- Prim's algorithm
- Event scheduling
- Memory management concepts
- Top-K problems
- Finding minimum or maximum values efficiently

---

# 24. Important Heap Terms

### Heap Property

The rule that determines the relationship between parent and child nodes.

### Max Heap

Parent is greater than or equal to its children.

    Parent >= Children

### Min Heap

Parent is smaller than or equal to its children.

    Parent <= Children

### Heapify

Process of restoring the heap property.

### Complete Binary Tree

A binary tree filled level by level from left to right.

### Root

The first element of the heap.

### Leaf

A node without children.

---

# 25. Important Exam/Viva Points

### Q1. What is a Heap?

A Heap is a complete binary tree that satisfies a heap property.

### Q2. What are the two types of Heap?

1. Max Heap
2. Min Heap

### Q3. What is the property of Max Heap?

    Parent >= Children

### Q4. What is the property of Min Heap?

    Parent <= Children

### Q5. Where is the maximum element in a Max Heap?

At the root.

### Q6. Where is the minimum element in a Min Heap?

At the root.

### Q7. What type of binary tree is a Heap?

A Complete Binary Tree.

### Q8. What is the left child formula?

    2 * i + 1

### Q9. What is the right child formula?

    2 * i + 2

### Q10. What is the parent formula?

    (i - 1) / 2

### Q11. What is the time complexity of heapify?

    O(log n)

### Q12. What is the time complexity of building a heap?

    O(n)

### Q13. What data structure is commonly implemented using a Heap?

Priority Queue.

### Q14. Does a Heap contain completely sorted elements?

No.

A Heap only maintains the required parent-child relationship.

---

# 26. Quick Revision

```text
                    HEAP
                      |
          +-----------+-----------+
          |                       |
       MAX HEAP                MIN HEAP
          |                       |
    Parent >= Child         Parent <= Child
          |                       |
     Maximum at Root          Minimum at Root
          |                       |
          +-----------+-----------+
                      |
              Complete Binary Tree
                      |
                 Array Based
                      |
        +-------------+-------------+
        |             |             |
      Parent       Left Child    Right Child
        |             |             |
    (i-1)/2         2i+1          2i+2


27. Heap Operations Overview

The major heap operations are:

Creation

Create a heap from a collection of elements.

Heapify

Restore the heap property.

Insertion

Add a new element and restore the heap property.

Deletion

Remove an element and restore the heap property.

Extract Maximum

Remove and return the maximum element from a Max Heap.

Extract Minimum

Remove and return the minimum element from a Min Heap.

Heap Sort

Use a heap to sort elements.

28. Why Heapify is Important

Heapify is one of the most important concepts in Heap data structures.

Whenever an operation breaks the heap property, heapify can be used to restore it.

For Max Heap:

Move the larger value upward/downward as required.

For Min Heap:

Move the smaller value upward/downward as required.

Heapify works along the height of the tree.

Therefore:

Time Complexity = O(log n)

29. Important Difference Between Heap and Sorted Array

A sorted array maintains complete ordering.

Example:

10 20 30 40 50 60

A Heap does not need to be completely sorted.

For example, a valid Max Heap can be:

60 40 50 10 20 30

The important rule is only:

Parent >= Children

Therefore, a Heap provides priority information without requiring the entire data to be sorted.

30. Overall Concept

The main idea of a Heap is to efficiently maintain the highest-priority or lowest-priority element.

In a Max Heap:

Largest element -> Root

In a Min Heap:

Smallest element -> Root

A Heap is always a Complete Binary Tree and is commonly represented using an array.

The most important formulas are:

Parent = (i - 1) / 2

Left Child = 2 * i + 1

Right Child = 2 * i + 2

Heapify maintains the heap property.

Building a complete heap from an array takes:

O(n)

while heapifying a single node takes:

O(log n)
31. Conclusion

A Heap is an important non-linear data structure based on a Complete Binary Tree.

There are two major types:

Max Heap
Min Heap

The key concepts to remember are:

Complete Binary Tree
Heap Property
Max Heap
Min Heap
Array Representation
Parent and Child formulas
Heapify
Building a Heap
Heap Height
Time Complexity
Applications

Understanding these concepts provides the foundation for learning:

Heap Insertion
Heap Deletion
Extract Max
Extract Min
Priority Queue
Heap Sort

The most important points are:

Max Heap:
Parent >= Children

Min Heap:
Parent <= Children

Parent:
(i - 1) / 2

Left Child:
2 * i + 1

Right Child:
2 * i + 2

Heapify:
O(log n)

Build Heap:
O(n)