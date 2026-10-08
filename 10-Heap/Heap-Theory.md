# Heap - Complete Theory

## 1. Introduction to Heap

A **Heap** is a special type of **complete binary tree** that satisfies a specific ordering property between a parent node and its children.

A heap is commonly used when we need to repeatedly find the **maximum** or **minimum** element efficiently.

There are two main types of heaps:

1. **Max Heap**
2. **Min Heap**

Heap is mainly implemented using an **array**, so we do not usually need separate pointers for every node.

---

# 2. Important Properties of Heap

A heap has two important properties:

## 2.1 Complete Binary Tree Property

A heap must always be a **complete binary tree**.

A complete binary tree means:

- All levels are completely filled except possibly the last level.
- The last level is filled from **left to right**.

Example:

```text
          50
        /    \
      30      40
     /  \    /
   10   20  35

2.2 Heap Order Property

The second property depends on the type of heap.

Max Heap

In a Max Heap:

Parent >= Children

Example:

          50
        /    \
      30      40
     /  \
   10   20

50 is greater than 30 and 40.

30 is greater than 10 and 20.

Therefore, this satisfies the Max Heap property.

Min Heap

In a Min Heap:

Parent <= Children

Example:

          10
        /    \
      20      15
     /  \
   30   40

10 is smaller than 20 and 15.

20 is smaller than 30 and 40.

Therefore, this satisfies the Min Heap property.

3. Max Heap

A Max Heap is a complete binary tree in which every parent is greater than or equal to its children.

          90
        /    \
      70      80
     /  \    /  \
   40   50  60   30

Here:

90 >= 70
90 >= 80

70 >= 40
70 >= 50

80 >= 60
80 >= 30

Therefore, it is a valid Max Heap.

Important Point

The maximum element is always at the root.

So:

Maximum = Root
4. Min Heap

A Min Heap is a complete binary tree in which every parent is smaller than or equal to its children.

          10
        /    \
      20      15
     /  \    /  \
   40   30  25   50

Here:

10 <= 20
10 <= 15

20 <= 40
20 <= 30

15 <= 25
15 <= 50

Therefore, it is a valid Min Heap.

Important Point

The minimum element is always at the root.

So:

Minimum = Root
5. Heap Representation Using Array

A heap is usually stored in an array.

Consider this Max Heap:

          50
        /    \
      30      40
     /  \    /
   10   20  35

Its array representation is:

Index:  0   1   2   3   4   5
Value: 50  30  40  10  20  35

The tree does not require explicit left and right pointers.

The position of every child can be calculated using its index.

6. Array Index Formulas

For a node at index i:

Parent
parent = (i - 1) / 2
Left Child
left = 2 * i + 1
Right Child
right = 2 * i + 2

These formulas assume 0-based indexing.

7. Example of Array Representation

Consider:

          50
        /    \
      30      40
     /  \    /
   10   20  35

Array:

[50, 30, 40, 10, 20, 35]

For index 1:

value = 30

Left child:

2(1) + 1 = 3

Index 3 contains:

10

Right child:

2(1) + 2 = 4

Index 4 contains:

20

Therefore:

30
├── 10
└── 20
8. Heap Creation

Heap creation means constructing a heap from a set of elements.

There are two common approaches:

Insert elements one by one.
Build Heap using Heapify.

Example elements:

40 20 50 10 30

These elements can be arranged into a heap by applying the appropriate heap operations.

9. Heapify

Heapify is the process of adjusting a tree or subtree so that it satisfies the heap property.

There are two major forms:

Heapify Up
Heapify Down
10. Heapify Up

Heapify Up is mainly used after inserting a new element.

The new element is initially inserted at the end of the heap.

Then it is compared with its parent.

If the heap property is violated, the element is swapped with its parent.

This process continues until the heap property is restored.

Example of Heapify Up in Max Heap

Suppose:

          50
        /    \
      30      40

Insert:

60

Initially:

          50
        /    \
      30      40
     /
   60

60 is greater than its parent 30.

Swap:

          50
        /    \
      60      40
     /
   30

Now 60 is greater than 50.

Swap again:

          60
        /    \
      50      40
     /
   30

The Max Heap property is restored.

11. Heapify Down

Heapify Down is mainly used after:

Deleting an element
Extracting the root
Building a heap

The node is compared with its children.

The appropriate child is selected and swapped when necessary.

This continues until the heap property is restored.

Example of Heapify Down in Max Heap

Suppose:

          20
        /    \
      50      40
     /  \
   30   10

The root 20 violates the Max Heap property.

The larger child is 50.

Swap:

          50
        /    \
      20      40
     /  \
   30   10

Now 20 is compared with its children.

30 is greater than 20.

Swap:

          50
        /    \
      30      40
     /  \
   20   10

Now the Max Heap property is restored.

12. Build Heap

Build Heap means converting an ordinary array into a valid heap.

Suppose:

[10, 30, 20, 5, 40]

We can use Heapify Down starting from the last non-leaf node.

The last non-leaf node is:

n / 2 - 1

where n is the number of elements.

For example, if:

n = 5

then:

5 / 2 - 1 = 1

So we start heapifying from index 1.

13. Last Non-Leaf Node

For an array of n elements:

Last non-leaf index = n / 2 - 1

All elements after this index are leaf nodes.

Leaf nodes do not have children, so they already satisfy the heap property by themselves.

14. Insertion in Heap

Insertion adds a new element to the heap.

The basic steps are:

Insert the new element at the end of the array.
Compare it with its parent.
If the heap property is violated, swap them.
Continue moving upward.
Stop when the heap property is restored.

This is called:

Heapify Up
15. Insertion in Max Heap

Suppose:

[50, 30, 40, 10, 20]

Insert:

60

Initially:

[50, 30, 40, 10, 20, 60]

60 is compared with its parent 40.

Swap:

[50, 30, 60, 10, 20, 40]

60 is then compared with 50.

Swap:

[60, 30, 50, 10, 20, 40]

Now the Max Heap property is satisfied.

16. Insertion in Min Heap

For a Min Heap, the process is similar.

The new element is inserted at the end.

Then it is compared with its parent.

If the new element is smaller than its parent, they are swapped.

This continues until the Min Heap property is restored.

17. Delete Element from Heap

Deletion means removing an element from the heap.

If we delete an element from an arbitrary position:

Find the element.
Replace it with the last element.
Reduce the heap size.
Restore the heap property.

The replacement element may need:

Heapify Up

or

Heapify Down

depending on its position.

18. Extract-Max

In a Max Heap, the maximum element is at the root.

Therefore, extracting the maximum means:

Remove root

Steps:

Store the root.
Replace root with the last element.
Reduce heap size.
Apply Heapify Down.
Return the removed maximum value.

Example:

          90
        /    \
      70      80
     /  \
   40   50

Extract-Max:

90

Move last element to root:

          50
        /    \
      70      80
     /
   40

Heapify Down:

          80
        /    \
      70      50
     /
   40
19. Extract-Min

In a Min Heap, the minimum element is at the root.

Therefore:

Extract-Min = Remove Root

Steps:

Store root.
Replace root with last element.
Reduce heap size.
Apply Heapify Down.
Return removed minimum value.
20. Maximum and Minimum Element
In Max Heap

The maximum element can be found in:

O(1)

because it is always at the root.

In Min Heap

The minimum element can be found in:

O(1)

because it is always at the root.

However, finding the minimum element in a Max Heap is not necessarily O(1).

Similarly, finding the maximum element in a Min Heap is not necessarily O(1).

21. Heap Sort

Heap Sort is a comparison-based sorting algorithm based on the Heap data structure.

It can be performed using:

Max Heap
Min Heap
22. Heap Sort Using Max Heap

Max Heap is generally used to produce ascending order.

Basic process:

Build a Max Heap.
The maximum element is at the root.
Swap the root with the last element.
Reduce heap size.
Apply Heapify Down.
Repeat until the array is sorted.

Example:

[40, 10, 30, 20, 50]

After building Max Heap:

[50, 20, 30, 10, 40]

Move maximum to the end.

Continue the process.

Final result:

[10, 20, 30, 40, 50]

Therefore:

Max Heap -> Ascending Order
23. Heap Sort Using Min Heap

Min Heap can be used to produce descending order.

Basic process:

Build a Min Heap.
The minimum element is at the root.
Swap root with the last element.
Reduce heap size.
Apply Heapify Down.
Repeat.

The final result is in descending order.

Therefore:

Min Heap -> Descending Order
24. Heap Sort Complexity

Building a heap using the efficient Build Heap method takes:

O(n)

Each extraction takes:

O(log n)

There are n extractions.

Therefore:

Heap Sort = O(n log n)
Best Case
O(n log n)
Average Case
O(n log n)
Worst Case
O(n log n)

Heap Sort has the same asymptotic time complexity in all three cases.

25. Heap Height

A heap is a complete binary tree.

The height of a heap containing n nodes is:

O(log n)

More precisely:

Height = floor(log2(n))

This is why operations such as:

insertion
deletion
heapify
extract

generally take:

O(log n)
26. Time Complexity of Heap Operations
Operation	Time Complexity
Access Root	O(1)
Find Max in Max Heap	O(1)
Find Min in Min Heap	O(1)
Insert	O(log n)
Heapify Up	O(log n)
Heapify Down	O(log n)
Extract-Max	O(log n)
Extract-Min	O(log n)
Delete	O(log n) after locating element
Build Heap	O(n)
Heap Sort	O(n log n)
Important Note

If an arbitrary element must first be searched for before deletion, searching may take:

O(n)

because a heap is not a binary search tree.

27. Space Complexity of Heap

When a heap is stored using an array:

Space = O(n)

The heap itself requires O(n) storage.

Heap Sort can be performed in-place, so its additional auxiliary space can be:

O(1)

when implemented iteratively.

If recursive heapify is used, the recursion stack can require:

O(log n)

space.

28. Heap vs Binary Tree
Feature	Binary Tree	Heap
Maximum children	2	2
Complete tree required	No	Yes
Ordering property	Not required	Required
Common representation	Pointers	Array
Root has special meaning	Not necessarily	Yes
Used for priority queue	No	Yes
29. Heap vs Binary Search Tree
Feature	Heap	BST
Main property	Parent-child order	Left < Root < Right
Complete tree	Yes	Not necessarily
Root	Max/Min	Depends on insertion
Find maximum	O(1) in Max Heap	O(h)
Find minimum	O(1) in Min Heap	O(h)
Search arbitrary value	O(n)	O(h)
Sorting	Heap Sort	Inorder traversal
Common implementation	Array	Pointers
Main application	Priority Queue	Searching
30. Heap vs Priority Queue

A Priority Queue is an abstract data structure in which each element has a priority.

The highest-priority or lowest-priority element is removed first.

A heap is one of the most common ways to implement a priority queue.

Max Heap

Can implement:

Maximum Priority Queue
Min Heap

Can implement:

Minimum Priority Queue
31. Applications of Heap

Heaps are widely used in computer science.

Important applications include:

1. Priority Queue

Used to process elements according to priority.

2. Heap Sort

Used for sorting elements in:

O(n log n)

time.

3. Operating Systems

Priority-based scheduling can use heap-based priority queues.

4. Graph Algorithms

Heaps are used in algorithms such as:

Dijkstra's Algorithm
Prim's Algorithm
5. Event Scheduling

Events can be processed according to their priority or scheduled time.

6. Job Scheduling

Jobs can be processed according to priority.

7. Top-K Problems

Heaps are commonly used to find:

Top K largest elements
Top K smallest elements
32. Important Heap Algorithms

The important algorithms related to Heap are:

1. Heap Creation
2. Heapify Up
3. Heapify Down
4. Build Heap
5. Insert
6. Delete
7. Extract-Max
8. Extract-Min
9. Heap Sort
33. Max Heap Important Rule

Remember:

Parent >= Children

Therefore:

Maximum element = Root

Insertion uses:

Heapify Up

Deletion/Extraction generally uses:

Heapify Down
34. Min Heap Important Rule

Remember:

Parent <= Children

Therefore:

Minimum element = Root

Insertion uses:

Heapify Up

Deletion/Extraction generally uses:

Heapify Down
35. Heapify Up vs Heapify Down
Feature	Heapify Up	Heapify Down
Direction	Bottom to Top	Top to Bottom
Common use	Insertion	Deletion/Extraction
Starts from	Newly inserted element	Replaced root/node
Movement	Toward root	Toward leaves
Complexity	O(log n)	O(log n)
36. Important Heap Formulas

For 0-based array indexing:

Parent
(i - 1) / 2
Left Child
2 * i + 1
Right Child
2 * i + 2
Last Non-Leaf Node
n / 2 - 1
Heap Height
floor(log2(n))

These formulas are very important for coding and exams.

37. Complete Binary Tree vs Heap

Every heap is a complete binary tree.

But every complete binary tree is not necessarily a heap.

Example:

          10
        /    \
      50      20

This is a complete binary tree.

But it is not a valid Max Heap because:

10 < 50

and it is not a valid Min Heap because:

10 <= 50
10 <= 20

Actually, this particular example satisfies the Min Heap property, so it is a Min Heap.

Consider instead:

          30
        /    \
      10      20

This is a complete binary tree and a Max Heap.

To be a heap, both conditions must be satisfied:

Complete Binary Tree
+
Heap Order Property
38. Important Characteristics of Heap

A heap:

Is a complete binary tree.
Is usually stored in an array.
Has a special root.
Supports efficient insertion.
Supports efficient deletion of the root.
Supports efficient extraction of maximum/minimum.
Is commonly used for priority queues.
Is used in Heap Sort.
Has height O(log n).
39. Advantages of Heap
1. Fast Root Access

Maximum or minimum element can be accessed in:

O(1)
2. Efficient Insertion

Insertion takes:

O(log n)
3. Efficient Extraction

Extract-Max or Extract-Min takes:

O(log n)
4. Efficient Priority Queue

Heap provides an efficient implementation of priority queues.

5. Heap Sort

Heap Sort provides:

O(n log n)

worst-case time complexity.

6. Array Implementation

Heap can be stored efficiently using an array without explicit tree pointers.

40. Disadvantages of Heap
1. Searching is Slow

Searching for an arbitrary value may take:

O(n)
2. No Sorted Order

Elements are not completely sorted inside the heap.

3. More Complex Than Simple Arrays

Heap operations require understanding of:

Parent
Children
Heapify
Swapping
Heap property
4. Not Suitable for General Searching

A BST is usually more suitable when efficient arbitrary-value searching is required.

41. Important Exam Questions
Q1. What is a Heap?

A heap is a complete binary tree that satisfies a heap ordering property.

Q2. What are the types of Heap?

There are two main types:

1. Max Heap
2. Min Heap
Q3. What is a Max Heap?

A Max Heap is a complete binary tree where every parent is greater than or equal to its children.

Q4. What is a Min Heap?

A Min Heap is a complete binary tree where every parent is smaller than or equal to its children.

Q5. Where is the maximum element in a Max Heap?

At the root.

Q6. Where is the minimum element in a Min Heap?

At the root.

Q7. What is Heapify?

Heapify is the process of restoring the heap property.

Q8. What is Heapify Up?

Heapify Up moves an element toward the root until the heap property is restored.

Q9. What is Heapify Down?

Heapify Down moves an element toward the leaves until the heap property is restored.

Q10. What is the complexity of insertion?
O(log n)
Q11. What is the complexity of Build Heap?
O(n)
Q12. What is the complexity of Heap Sort?
O(n log n)
Q13. Is Heap Sort stable?

No.

Heap Sort is generally not stable.

Q14. Is Heap Sort in-place?

Yes.

Heap Sort can be performed in-place with:

O(1)

additional space, excluding recursion stack.

Q15. Which heap is used for ascending Heap Sort?

Usually:

Max Heap
Q16. Which heap is used for descending Heap Sort?

Usually:

Min Heap
42. Quick Revision

Remember the following:

Heap
│
├── Complete Binary Tree
│
├── Max Heap
│   └── Parent >= Children
│
└── Min Heap
    └── Parent <= Children

Array formulas:

Parent = (i - 1) / 2

Left Child = 2 * i + 1

Right Child = 2 * i + 2

Operations:

Insertion
    ↓
Heapify Up

Deletion / Extraction
    ↓
Heapify Down

Important complexities:

Root Access       = O(1)
Insert            = O(log n)
Extract           = O(log n)
Delete            = O(log n) after locating element
Build Heap        = O(n)
Heap Sort         = O(n log n)
43. Overall Heap Concept

The complete concept of Heap can be understood like this:

                 HEAP
                   |
          Complete Binary Tree
                   |
          +--------+--------+
          |                 |
       Max Heap          Min Heap
          |                 |
 Parent >= Child       Parent <= Child
          |                 |
 Maximum at Root       Minimum at Root
          |                 |
          +--------+--------+
                   |
              Heapify
             /       \
        Heapify Up  Heapify Down
             |          |
         Insertion   Deletion
             |
             |
          Heap Sort
             |
      +------+------+
      |             |
   Max Heap      Min Heap
      |             |
 Ascending      Descending
44. Final Summary

A Heap is a complete binary tree with a special ordering property.

There are two major types:

Max Heap
Min Heap

In a Max Heap:

Parent >= Children

and the maximum element is at the root.

In a Min Heap:

Parent <= Children

and the minimum element is at the root.

Heaps are usually implemented using arrays.

For a node at index i:

Parent = (i - 1) / 2
Left   = 2 * i + 1
Right  = 2 * i + 2

The two important adjustment operations are:

Heapify Up
Heapify Down

Heapify Up is mainly used after insertion.

Heapify Down is mainly used after deletion or extraction.

Build Heap takes:

O(n)

Insertion, deletion, and extraction generally take:

O(log n)

Heap Sort takes:

O(n log n)

Heap is especially useful for:

Priority Queues
Heap Sort
Scheduling
Dijkstra's Algorithm
Prim's Algorithm
Top-K problems
Priority-based processing

Therefore, the main idea to remember is:

HEAP = Complete Binary Tree + Heap Order Property

For Max Heap:

Maximum = Root

For Min Heap:

Minimum = Root

This completes the complete theory of Heap, Heap Operations, and Heap Sort.