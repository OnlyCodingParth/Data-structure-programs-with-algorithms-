# Trees - Data Structure

## 1. Introduction

A **Tree** is a non-linear data structure used to represent hierarchical relationships between elements.

Unlike arrays, linked lists, stacks and queues, which are generally linear data structures, a tree organizes data in a hierarchical structure.

A tree consists of:

- Nodes
- Edges
- Root
- Parent nodes
- Child nodes
- Leaf nodes
- Subtrees

Example:

        A
       / \
      B   C
     / \
    D   E

Here:

- A is the root.
- B and C are children of A.
- D and E are children of B.
- D, E and C are leaf nodes.

---

# 2. Basic Tree Terminology

## Node

A node is an individual element of a tree.

Example:

        A
       / \
      B   C

A, B and C are nodes.

---

## Root

The topmost node of a tree is called the root.

Example:

        A
       / \
      B   C

A is the root.

A tree has only one root.

---

## Parent

A node that has one or more children is called a parent node.

Example:

        A
       / \
      B   C

A is the parent of B and C.

---

## Child

A node directly connected below another node is called its child.

In the above example:

- B is a child of A.
- C is a child of A.

---

## Sibling

Nodes having the same parent are called siblings.

Example:

        A
       / \
      B   C

B and C are siblings.

---

## Leaf Node

A node that has no children is called a leaf node.

Example:

        A
       / \
      B   C

B and C are leaf nodes.

---

## Internal Node

A node having at least one child is called an internal node.

In:

        A
       / \
      B   C

A is an internal node.

---

## Edge

The connection between two nodes is called an edge.

Example:

        A
       /
      B

The connection between A and B is an edge.

---

## Subtree

A smaller tree formed from a node and its descendants is called a subtree.

Example:

        A
       / \
      B   C
     / \
    D   E

The subtree rooted at B is:

        B
       / \
      D   E

---

# 3. Height of a Tree

The height of a tree is the length of the longest path from the root to a leaf.

In our C programs, the convention is:

    Height of NULL = 0
    Height of leaf node = 1

For example:

        A
       /
      B
     /
    C

The height is 3 using the node-count convention.

---

# 4. Depth

The depth of a node represents its distance from the root.

The root normally has depth:

    0

Its children have depth:

    1

Their children have depth:

    2

and so on.

---

# 5. Level

The level of a node represents its position in the tree.

Depending on the convention used:

    Root = Level 0

or

    Root = Level 1

Always follow the convention specified in the question or program.

---

# 6. Degree of a Node

The degree of a node is the number of children it has.

For example:

        A
       /|\
      B C D

A has degree 3.

---

# 7. Degree of a Tree

The degree of a tree is the maximum degree of any node in the tree.

For example:

        A
       /|\
      B C D

The degree of the tree is 3.

---

# 8. Binary Tree

A **Binary Tree** is a tree in which every node has at most two children.

The two children are called:

- Left child
- Right child

Example:

        10
       /  \
      20   30

Each node can have:

    0, 1 or 2 children

---

# 9. Binary Tree Node Structure

A typical binary tree node in C is:

    struct Node
    {
        int data;
        struct Node *left;
        struct Node *right;
    };

The `left` pointer stores the address of the left child.

The `right` pointer stores the address of the right child.

---

# 10. Types of Binary Trees

Important types of binary trees include:

1. Full Binary Tree
2. Complete Binary Tree
3. Perfect Binary Tree
4. Balanced Binary Tree
5. Skewed Binary Tree

---

## Full Binary Tree

A full binary tree is a binary tree in which every node has either:

- 0 children
- 2 children

Example:

        A
       / \
      B   C
     / \
    D   E

---

## Complete Binary Tree

A complete binary tree has all levels completely filled except possibly the last level.

The last level is filled from left to right.

Example:

        A
       / \
      B   C
     / \  /
    D  E F

---

## Perfect Binary Tree

A perfect binary tree has:

- Every internal node with exactly two children.
- All leaf nodes at the same level.

Example:

        A
       / \
      B   C
     / \ / \
    D  E F  G

---

## Balanced Binary Tree

A balanced tree maintains approximately equal heights between its subtrees.

Balanced trees provide efficient operations.

---

## Skewed Binary Tree

A skewed tree has nodes mainly on one side.

Left-skewed:

        A
       /
      B
     /
    C

Right-skewed:

    A
     \
      B
       \
        C

A skewed tree can behave like a linked list.

---

# 11. Binary Tree Traversals

Tree traversal means visiting all nodes of a tree.

Important traversals are:

1. Preorder
2. Inorder
3. Postorder
4. Level Order

---

## Preorder Traversal

Order:

    Root -> Left -> Right

Example:

        A
       / \
      B   C

Preorder:

    A B C

Preorder is a type of Depth First Search.

---

## Inorder Traversal

Order:

    Left -> Root -> Right

Example:

        A
       / \
      B   C

Inorder:

    B A C

Inorder traversal of a Binary Search Tree gives sorted output.

---

## Postorder Traversal

Order:

    Left -> Right -> Root

Example:

        A
       / \
      B   C

Postorder:

    B C A

---

## Level Order Traversal

Level order visits nodes level by level.

Example:

        A
       / \
      B   C
     / \
    D   E

Level order:

    A B C D E

Level order traversal normally uses a queue.

---

# 12. DFS and BFS

Tree traversals can be divided into:

### DFS

Depth First Search includes:

- Preorder
- Inorder
- Postorder

DFS generally uses recursion or a stack.

### BFS

Breadth First Search includes:

- Level Order Traversal

BFS normally uses a queue.

---

# 13. Binary Tree Operations

Common binary tree operations include:

1. Creation
2. Preorder traversal
3. Inorder traversal
4. Postorder traversal
5. Level order traversal
6. Count total nodes
7. Count leaf nodes
8. Find height
9. Search for an element

---

# 14. Binary Tree Complexity

For a binary tree with n nodes:

| Operation | Time Complexity |
|-----------|-----------------|
| Traversal | O(n) |
| Count Nodes | O(n) |
| Count Leaf Nodes | O(n) |
| Search | O(n) |
| Find Height | O(n) |

The tree requires:

    O(n)

space to store n nodes.

---

# 15. Binary Search Tree

A **Binary Search Tree (BST)** is a Binary Tree that follows a specific ordering property.

For every node:

    Left Subtree < Root < Right Subtree

Example:

        50
       /  \
      30   70
     / \   / \
    20 40 60 80

All values on the left are smaller than 50.

All values on the right are greater than 50.

---

# 16. BST Operations

Important BST operations include:

1. Creation
2. Insertion
3. Searching
4. Deletion
5. Finding minimum
6. Finding maximum
7. Traversal

---

# 17. BST Insertion

To insert a value:

1. Start at the root.
2. Compare the value with the current node.
3. If smaller, move left.
4. If larger, move right.
5. Continue until an empty position is found.
6. Insert the new node.

---

# 18. BST Searching

Searching follows the BST property.

If:

    value < current node

move left.

If:

    value > current node

move right.

If:

    value == current node

the element is found.

---

# 19. BST Minimum

The minimum value is found by repeatedly moving to the left child.

Example:

        50
       /
      30
     /
    20

Minimum:

    20

---

# 20. BST Maximum

The maximum value is found by repeatedly moving to the right child.

Example:

        50
          \
           70
             \
              80

Maximum:

    80

---

# 21. BST Deletion

BST deletion has three cases.

### Case 1 - Leaf Node

Simply remove the node.

### Case 2 - One Child

Replace the node with its child.

### Case 3 - Two Children

Replace the node with its inorder successor or inorder predecessor.

The inorder successor is the smallest value in the right subtree.

---

# 22. BST Traversal

Inorder traversal of a BST produces values in sorted order.

Example:

        50
       /  \
      30   70
     / \   / \
    20 40 60 80

Inorder:

    20 30 40 50 60 70 80

This is one of the most important properties of a BST.

---

# 23. BST Complexity

For a balanced BST:

| Operation | Average Time |
|-----------|--------------|
| Search | O(log n) |
| Insertion | O(log n) |
| Deletion | O(log n) |

However, a normal BST can become skewed.

In the worst case:

    Search = O(n)
    Insertion = O(n)
    Deletion = O(n)

This problem leads to self-balancing trees such as AVL Trees.

---

# 24. Threaded Binary Tree

A **Threaded Binary Tree** uses otherwise NULL child pointers to store useful traversal information.

Normally, many pointers in a binary tree are NULL.

Threaded trees use some of these NULL pointers as:

- Inorder predecessor links
- Inorder successor links

This can reduce the need for recursion or an explicit stack during traversal.

---

# 25. Types of Threaded Binary Trees

There are three important types:

1. Left Threaded Binary Tree
2. Right Threaded Binary Tree
3. Double Threaded Binary Tree

---

# 26. Left Threaded Binary Tree

In a left-threaded binary tree, NULL left pointers are used to point to the inorder predecessor.

Example:

        50
       /  \
      30   70
     / \
    20 40

The inorder traversal is:

    20 30 40 50 70

A left thread can connect a node to its inorder predecessor.

For example:

    40 -> 30

when the left pointer of 40 would otherwise be NULL.

---

# 27. Right Threaded Binary Tree

In a right-threaded binary tree, NULL right pointers are used to point to the inorder successor.

For the same tree:

        50
       /  \
      30   70
     / \
    20 40

Inorder:

    20 30 40 50 70

A right thread can connect:

    20 -> 30
    40 -> 50

---

# 28. Double Threaded Binary Tree

A double-threaded binary tree can use both:

- Left NULL pointers for inorder predecessor.
- Right NULL pointers for inorder successor.

A node generally contains thread indicators.

Example:

    leftThread
    rightThread

A flag can tell whether a pointer represents:

- An actual child
- A thread

---

# 29. Threaded Tree Node Structure

A double-threaded node can be represented as:

    struct Node
    {
        int data;
        struct Node *left;
        struct Node *right;
        int leftThread;
        int rightThread;
    };

The thread flags help identify whether the pointers represent children or threads.

---

# 30. Threaded Binary Tree Operations

Important operations include:

1. Creation
2. Inorder traversal
3. Preorder traversal
4. Searching
5. Insertion

Threaded trees are particularly useful for efficient traversal.

---

# 31. Advantages of Threaded Binary Trees

1. Efficient traversal.
2. Can reduce the need for recursion.
3. Can reduce the need for an explicit stack.
4. NULL pointers are used more effectively.
5. Inorder successor and predecessor can be accessed efficiently.

---

# 32. Disadvantages of Threaded Binary Trees

1. Implementation is more complex.
2. Thread flags must be maintained.
3. Insertion and deletion require careful pointer handling.
4. The programmer must distinguish threads from actual child pointers.

---

# 33. AVL Tree

An **AVL Tree** is a self-balancing Binary Search Tree.

It maintains the BST property and automatically keeps its height balanced.

For every node:

    Balance Factor =
    Height(Left Subtree)
    -
    Height(Right Subtree)

The balance factor must be:

    -1, 0 or +1

---

# 34. Why AVL Tree Is Needed

A normal BST can become skewed.

Example:

    10
      \
       20
         \
          30
            \
             40

This can make searching O(n).

AVL Trees automatically perform rotations to maintain balance.

Therefore:

    Search = O(log n)
    Insertion = O(log n)
    Deletion = O(log n)

---

# 35. AVL Rotations

There are four AVL imbalance cases:

1. LL
2. RR
3. LR
4. RL

---

## LL Rotation

LL means:

    Left - Left

Solution:

    Right Rotation

Example:

        30
       /
      20
     /
    10

After rotation:

        20
       /  \
      10   30

---

## RR Rotation

RR means:

    Right - Right

Solution:

    Left Rotation

Example:

    10
      \
       20
         \
          30

After rotation:

        20
       /  \
      10   30

---

## LR Rotation

LR means:

    Left - Right

Solution:

    Left Rotation
    +
    Right Rotation

Example:

        30
       /
      10
        \
         20

Final:

        20
       /  \
      10   30

---

## RL Rotation

RL means:

    Right - Left

Solution:

    Right Rotation
    +
    Left Rotation

Example:

    10
      \
       30
      /
     20

Final:

        20
       /  \
      10   30

---

# 36. AVL Rotation Summary

| Case | Required Rotation |
|------|--------------------|
| LL | Right Rotation |
| RR | Left Rotation |
| LR | Left + Right Rotation |
| RL | Right + Left Rotation |

Important rule:

    LL -> Right
    RR -> Left
    LR -> Left + Right
    RL -> Right + Left

---

# 37. AVL Insertion

AVL insertion follows BST insertion.

After insertion:

1. Update height.
2. Calculate balance factor.
3. Check for imbalance.
4. Identify LL, RR, LR or RL.
5. Perform the required rotation.
6. Return the balanced tree.

---

# 38. AVL Deletion

AVL deletion first follows BST deletion.

After deletion:

1. Update height.
2. Calculate balance factor.
3. Check for imbalance.
4. Perform the required rotation.
5. Continue balancing toward the root.

Possible cases:

    LL -> Right Rotation
    RR -> Left Rotation
    LR -> Left + Right Rotation
    RL -> Right + Left Rotation

---

# 39. AVL Complexity

| Operation | Time Complexity |
|-----------|-----------------|
| Search | O(log n) |
| Insertion | O(log n) |
| Deletion | O(log n) |
| Rotation | O(1) |
| Traversal | O(n) |

Space required to store n nodes:

    O(n)

---

# 40. Comparison of Binary Tree, BST, Threaded Tree and AVL Tree

| Feature | Binary Tree | BST | Threaded Binary Tree | AVL Tree |
|---------|-------------|-----|----------------------|----------|
| Maximum children | 2 | 2 | 2 | 2 |
| Ordering property | No | Yes | Usually BST-based | Yes |
| Self-balancing | No | No | No | Yes |
| Threads | No | No | Yes | No |
| Fast searching | Not guaranteed | Yes | Depends on structure | Yes |
| Rotations | No | No | No | Yes |
| Balance factor | No | No | No | Yes |
| Inorder traversal | Normal | Sorted | Efficient | Sorted |

---

# 41. Tree Traversal Complexity

For a tree containing n nodes:

    Preorder = O(n)
    Inorder = O(n)
    Postorder = O(n)
    Level Order = O(n)

Every node needs to be visited once.

---

# 42. Tree Data Structure Hierarchy

The tree topics covered in this folder can be understood as:

    Tree
     |
     +-- Binary Tree
     |      |
     |      +-- Traversals
     |      +-- Node Counting
     |      +-- Leaf Counting
     |
     +-- Binary Search Tree
     |      |
     |      +-- Insertion
     |      +-- Searching
     |      +-- Deletion
     |      +-- Minimum
     |      +-- Maximum
     |
     +-- Threaded Binary Tree
     |      |
     |      +-- Left Threaded
     |      +-- Right Threaded
     |      +-- Double Threaded
     |
     +-- AVL Tree
            |
            +-- Insertion
            +-- LL Rotation
            +-- RR Rotation
            +-- LR Rotation
            +-- RL Rotation
            +-- Deletion

---

# 43. Important Differences

## Binary Tree vs BST

Binary Tree:

    At most two children.

BST:

    Left < Root < Right

Therefore, every BST is a Binary Tree, but every Binary Tree is not a BST.

---

## BST vs AVL Tree

BST:

    May become skewed.

AVL:

    Automatically balances itself.

BST worst-case operations:

    O(n)

AVL operations:

    O(log n)

---

## Normal Binary Tree vs Threaded Binary Tree

Normal Binary Tree:

    NULL pointers remain NULL.

Threaded Binary Tree:

    Some NULL pointers are used as threads.

---

# 44. Applications of Trees

Trees are widely used in computer science.

Applications include:

1. File systems
2. Database indexing
3. Searching
4. Sorting
5. Compiler design
6. Expression evaluation
7. Artificial Intelligence
8. Networking
9. Operating systems
10. File organization
11. Hierarchical data
12. Decision-making systems
13. Game development
14. XML and HTML document structures
15. Dictionary and symbol-table implementations

---

# 45. Important Exam Points

1. Tree is a non-linear data structure.
2. Root is the topmost node.
3. A leaf node has no children.
4. Binary Tree allows at most two children.
5. BST follows Left < Root < Right.
6. Inorder traversal of a BST gives sorted data.
7. Threaded trees use NULL pointers as threads.
8. AVL Tree is a self-balancing BST.
9. AVL balance factor is:
   
       Height(Left) - Height(Right)

10. Valid AVL balance factors are -1, 0 and +1.
11. LL requires Right Rotation.
12. RR requires Left Rotation.
13. LR requires Left + Right Rotation.
14. RL requires Right + Left Rotation.
15. AVL search, insertion and deletion take O(log n).
16. Tree traversal takes O(n).
17. Level order traversal uses a queue.
18. DFS includes preorder, inorder and postorder.
19. BFS corresponds to level order traversal.
20. A skewed BST can have O(n) height.
21. AVL Tree maintains O(log n) height.
22. Threaded Binary Trees make use of otherwise NULL pointers.

---

# 46. Quick Revision

### Binary Tree

    At most 2 children

### BST

    Left < Root < Right

### Threaded Binary Tree

    NULL pointers -> Threads

### AVL Tree

    Self-balancing BST

### AVL Balance Factor

    Height(Left) - Height(Right)

### AVL Valid Balance

    -1, 0, +1

### AVL Rotations

    LL -> Right
    RR -> Left
    LR -> Left + Right
    RL -> Right + Left

### Traversals

    Preorder:
    Root -> Left -> Right

    Inorder:
    Left -> Root -> Right

    Postorder:
    Left -> Right -> Root

    Level Order:
    Level by Level

---

# 47. Overall Concept

Trees provide a hierarchical way of storing and organizing data.

A Binary Tree limits each node to at most two children.

A Binary Search Tree adds an ordering rule that makes searching more efficient.

A Threaded Binary Tree uses unused NULL pointers as threads to improve traversal.

An AVL Tree extends the Binary Search Tree concept by automatically maintaining balance.

Therefore, the concepts can be understood in this progression:

    Binary Tree
         |
         v
    Binary Search Tree
         |
         +------> Threaded Binary Tree
         |
         v
       AVL Tree

The important idea is that each structure solves a particular problem:

    Binary Tree
    -> Represents hierarchical data

    BST
    -> Provides ordered searching

    Threaded Binary Tree
    -> Improves traversal using threads

    AVL Tree
    -> Maintains balanced and efficient searching

---

# 48. Conclusion

Trees are one of the most important non-linear data structures in Data Structures and Algorithms.

The main tree structures covered here are:

- Binary Tree
- Binary Search Tree
- Threaded Binary Tree
- AVL Tree

A strong understanding of these topics requires knowing:

- Tree terminology
- Node relationships
- Tree creation
- Traversals
- BST property
- BST insertion
- BST searching
- BST deletion
- Threading
- Balance factor
- AVL insertion
- AVL deletion
- AVL rotations
- Time complexity
- Space complexity

The most important rules to remember are:

    Binary Tree:
    At most two children.

    BST:
    Left < Root < Right.

    Threaded Tree:
    NULL pointers can store traversal threads.

    AVL:
    Balance Factor = Height(Left) - Height(Right)

    AVL rotations:
    LL -> Right
    RR -> Left
    LR -> Left + Right
    RL -> Right + Left

These concepts form the foundation for advanced tree structures and are frequently asked in programming, DSA examinations, technical interviews and competitive programming.