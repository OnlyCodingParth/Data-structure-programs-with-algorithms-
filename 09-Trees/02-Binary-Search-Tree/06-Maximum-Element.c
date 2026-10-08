# Binary Search Tree (BST)

## 1. What is a Binary Search Tree?

A **Binary Search Tree (BST)** is a special type of binary tree in which every node follows a specific ordering rule.

### BST Property

For every node:

- All values in the left subtree are smaller than the node value.
- All values in the right subtree are greater than the node value.

Example:

          50
        /    \
      30      70
     /  \    /  \
   20   40  60   80

Here:

- Left subtree of 50 contains smaller values.
- Right subtree of 50 contains greater values.

Therefore, this is a valid Binary Search Tree.

---

## 2. Structure of a BST Node

A BST node contains:

1. Data
2. Pointer to the left child
3. Pointer to the right child

### C Structure

    struct Node
    {
        int data;
        struct Node *left;
        struct Node *right;
    };

Here:

- `data` stores the value.
- `left` points to the left child.
- `right` points to the right child.

---

## 3. Important Terms

### Root

The first node of the tree is called the **root**.

### Parent

A node that has one or more children is called a **parent**.

### Child

A node connected below another node is called a **child**.

### Leaf Node

A node having no children is called a **leaf node**.

### Internal Node

A node having at least one child is called an **internal node**.

### Subtree

A smaller tree formed from any node and its descendants is called a **subtree**.

---

## 4. Creation of a BST

A BST can be created by creating nodes dynamically using `malloc()`.

Basic steps:

1. Create a new node.
2. Allocate memory using `malloc()`.
3. Store the value.
4. Set `left` and `right` to `NULL`.
5. Make the node the root if the tree is empty.

---

## 5. Insertion in BST

Insertion means adding a new node into the correct position while maintaining the BST property.

### Rules

If the new value is:

- Smaller than the current node → move to the left subtree.
- Greater than the current node → move to the right subtree.
- Equal to the current node → handling depends on the implementation.

Example:

Insert:

    50, 30, 70, 20, 40

Result:

          50
        /    \
      30      70
     /  \
   20   40

To insert `20`:

    20 < 50

Move left.

    20 < 30

Move left again.

The left position of `30` is empty, so `20` is inserted there.

---

## 6. Searching in BST

Searching means finding whether a particular value exists in the BST.

BST makes searching efficient because one subtree can be ignored after every comparison.

### Searching Rules

If the required value is:

- Equal to current node → value found.
- Smaller than current node → search left subtree.
- Greater than current node → search right subtree.

Example:

Search for `60`:

          50
        /    \
      30      70
             /
            60

Steps:

    60 > 50

Move right.

    60 < 70

Move left.

    60 == 60

Value found.

---

## 7. Minimum Element in BST

The minimum value in a BST is found by continuously moving to the left child.

Example:

          50
        /    \
      30      70
     /
   20

Path:

    50 → 30 → 20

Therefore:

    Minimum = 20

### Important Point

The **leftmost node** contains the minimum value.

---

## 8. Maximum Element in BST

The maximum value in a BST is found by continuously moving to the right child.

Example:

          50
        /    \
      30      70
                \
                 80

Path:

    50 → 70 → 80

Therefore:

    Maximum = 80

### Important Point

The **rightmost node** contains the maximum value.

---

## 9. Deletion in BST

Deletion is one of the most important operations in a Binary Search Tree.

There are three main cases.

### Case 1: Deleting a Leaf Node

A leaf node has no children.

Example:

          50
        /    \
      30      70

If `30` is deleted:

          50
            \
             70

The node can simply be removed.

---

### Case 2: Deleting a Node with One Child

Example:

          50
        /
      30
     /
   20

If `30` is deleted, its child `20` takes its position.

Result:

          50
        /
      20

The parent is connected directly to the child.

---

### Case 3: Deleting a Node with Two Children

This is the most important deletion case.

Example:

          50
        /    \
      30      70
             /  \
           60    80

Suppose we delete `70`.

Node `70` has two children:

    60 and 80

We can replace `70` with its **inorder successor**.

The inorder successor is the smallest value in the right subtree.

For node `70`, the right subtree contains:

    80

Therefore, `80` becomes the replacement.

Result:

          50
        /    \
      30      80
             /
            60

### Inorder Successor

The inorder successor is:

> The smallest element in the right subtree.

It can be found by continuously moving to the left.

---

## 10. BST Traversals

A BST can be traversed using:

1. Preorder
2. Inorder
3. Postorder
4. Level Order

---

## 10.1 Preorder Traversal

Order:

    Root → Left → Right

Example:

          50
        /    \
      30      70

Preorder:

    50 30 70

---

## 10.2 Inorder Traversal

Order:

    Left → Root → Right

Example:

          50
        /    \
      30      70

Inorder:

    30 50 70

### Important BST Property

**Inorder traversal of a BST produces values in sorted ascending order.**

This is one of the most important BST properties.

---

## 10.3 Postorder Traversal

Order:

    Left → Right → Root

Example:

          50
        /    \
      30      70

Postorder:

    30 70 50

---

## 10.4 Level Order Traversal

Level Order visits nodes level by level.

Example:

          50
        /    \
      30      70
     /  \    /  \
   20   40  60   80

Level Order:

    50 30 70 20 40 60 80

A **queue** is commonly used for level-order traversal.

---

## 11. Difference Between Binary Tree and BST

| Binary Tree | Binary Search Tree |
|---|---|
| Each node can have at most two children | Each node can have at most two children |
| No ordering rule is required | Follows an ordering rule |
| Left and right values can be in any order | Left values are smaller and right values are greater |
| Searching may require checking many nodes | Searching can be faster |
| Inorder traversal is not necessarily sorted | Inorder traversal gives sorted order |

---

## 12. Balanced BST

A balanced BST has approximately equal height on both sides.

Example:

          50
        /    \
      30      70
     /  \    /  \
   20   40  60   80

A balanced BST can provide approximately:

    O(log n)

time for searching, insertion, and deletion.

---

## 13. Skewed BST

A skewed BST occurs when nodes are inserted in sorted or nearly sorted order.

Example:

    10
      \
       20
         \
          30
            \
             40

This behaves similarly to a linked list.

Searching can become:

    O(n)

---

## 14. Time Complexity

The time complexity of BST operations depends on the height of the tree.

| Operation | Average Case | Worst Case |
|---|---:|---:|
| Creation | O(1) | O(1) |
| Insertion | O(log n) | O(n) |
| Searching | O(log n) | O(n) |
| Deletion | O(log n) | O(n) |
| Minimum | O(log n) | O(n) |
| Maximum | O(log n) | O(n) |
| Inorder Traversal | O(n) | O(n) |
| Preorder Traversal | O(n) | O(n) |
| Postorder Traversal | O(n) | O(n) |
| Level Order Traversal | O(n) | O(n) |

### Why is the worst case O(n)?

If the BST becomes skewed, we may have to visit every node.

Therefore:

    Time = O(n)

---

## 15. Space Complexity

Space complexity depends on the number of nodes and recursion depth.

### Recursive Operations

For recursive insertion, searching, and deletion:

Average:

    O(log n)

Worst case:

    O(n)

This is because of the recursion stack.

### Iterative Minimum and Maximum

If minimum or maximum is found using an iterative approach:

    O(1)

extra space is required.

---

## 16. Advantages of BST

1. Searching can be faster than a normal binary tree.
2. Insertion is efficient in a balanced BST.
3. Deletion is possible while maintaining the BST property.
4. Minimum and maximum values can be found easily.
5. Inorder traversal gives sorted data.
6. Dynamic memory allocation allows the tree to grow as required.
7. BST is useful for maintaining ordered data.

---

## 17. Disadvantages of BST

1. A normal BST can become skewed.
2. A skewed BST can have O(n) searching time.
3. Implementation is more complex than arrays.
4. Pointers require additional memory.
5. Recursive operations use stack memory.
6. Maintaining balance may require additional techniques.

---

## 18. Applications of BST

Binary Search Trees can be used in:

- Searching systems
- Maintaining sorted data
- Symbol tables
- Dictionaries
- Database indexing concepts
- File systems
- Searching applications
- Dynamic ordered data
- Implementing sets and maps
- Computer science algorithms

Balanced variants of BSTs are used when guaranteed efficient operations are required.

Examples:

- AVL Tree
- Red-Black Tree

---

## 19. Important BST Facts

### Fact 1

The main BST property is:

    Left Subtree < Root < Right Subtree

### Fact 2

Inorder traversal of a BST produces:

    Sorted order

### Fact 3

The minimum element is the:

    Leftmost node

### Fact 4

The maximum element is the:

    Rightmost node

### Fact 5

BST deletion has three cases:

    1. Leaf node
    2. Node with one child
    3. Node with two children

### Fact 6

For a node with two children, deletion commonly uses:

    Inorder Successor

or:

    Inorder Predecessor

### Fact 7

Average searching time in a reasonably balanced BST:

    O(log n)

### Fact 8

Worst-case searching time in a skewed BST:

    O(n)

### Fact 9

A BST is a special type of:

    Binary Tree

---

## 20. BST Operation Summary

| Operation | Main Idea |
|---|---|
| Creation | Create the root/node |
| Insertion | Smaller → Left, Greater → Right |
| Searching | Compare and move left/right |
| Deletion | Handle 0, 1, or 2 children |
| Minimum | Move continuously left |
| Maximum | Move continuously right |
| Inorder | Left → Root → Right |
| Preorder | Root → Left → Right |
| Postorder | Left → Right → Root |
| Level Order | Visit level by level |

---

## 21. Overall Concept

A Binary Search Tree is a binary tree that maintains data in an ordered structure.

The main rule is:

          Root
         /    \
    Smaller    Greater

For every node:

    Left Subtree < Node < Right Subtree

Because of this ordering, searching, insertion, and deletion can be efficient when the tree is balanced.

The most important BST concepts are:

1. BST Property
2. Creation
3. Insertion
4. Searching
5. Deletion
6. Minimum
7. Maximum
8. Tree Traversals
9. Inorder gives sorted order
10. Average O(log n)
11. Worst O(n)

---

## 22. Conclusion

A **Binary Search Tree (BST)** is an important data structure used for storing and managing ordered data.

Its main advantage is that the BST property allows the program to decide whether to move left or right during searching, insertion, and deletion.

A balanced BST provides approximately:

    O(log n)

time for searching, insertion, and deletion.

However, if the tree becomes skewed, these operations can become:

    O(n)

Therefore, understanding BST is important before learning advanced tree structures such as:

- AVL Tree
- Red-Black Tree
- Heap
- B-Tree
- B+ Tree