# Binary Tree - Complete Theory

## 1. What is a Binary Tree?

A Binary Tree is a non-linear data structure in which each node can have at most two children.

The two children are called:

1. Left Child
2. Right Child

Example:

        10
       /  \
      20   30

Here:

- 10 is the Root.
- 20 is the Left Child of 10.
- 30 is the Right Child of 10.

---

## 2. Structure of a Binary Tree Node

In C, a binary tree node can be represented as:

```c
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};

Each node contains:

Data
Pointer to the Left Child
Pointer to the Right Child

Basic representation:

+-------+-------+--------+
|  Left | Data  | Right  |
+-------+-------+--------+
3. Important Terms
Root

The topmost node of a tree is called the root.

Example:

    10
   /  \
  20   30

Here, 10 is the root.

Parent

A node that has one or more children is called a parent node.

Here:

10 is the parent of 20.
10 is the parent of 30.
Child

A node directly connected below another node is called its child.

20 and 30 are children of 10.

Leaf Node

A node that has no children is called a leaf node.

Example:

    10
   /  \
  20   30

20 and 30 are leaf nodes.

Internal Node

A node that has at least one child is called an internal node.

In the above tree:

10 is an internal node.

Sibling

Nodes having the same parent are called siblings.

20 and 30 are siblings.

4. Basic Binary Tree Structure

Example:

    10
   /  \
  20   30
 /  \
40   50

Here:

10 → Root
20 and 30 → Children of 10
40 and 50 → Children of 20
40 and 50 → Leaf Nodes
20 and 30 → Siblings
5. Properties of Binary Tree
Maximum Number of Children

Each node can have at most:

2 children

These are:

Left Child
Right Child
Maximum Nodes at a Level

If the root is considered at level 0:

Maximum Nodes at Level L = 2^L

Examples:

Level 0:
2^0 = 1

Level 1:
2^1 = 2

Level 2:
2^2 = 4

Level 3:
2^3 = 8
Maximum Nodes in a Binary Tree

For height h, when the root is at height 0:

Maximum Nodes = 2^(h + 1) - 1

Example:

For height 2:

2^(2 + 1) - 1
= 8 - 1
= 7

Maximum tree:

       1
     /   \
    2     3
   / \   / \
  4   5 6   7
6. Height of Binary Tree

The height of a binary tree is the number of edges on the longest path from the root to a leaf.

Example:

    10
   /  \
  20   30
 /
40

The longest path is:

10 → 20 → 40

Therefore:

Height = 2
7. Depth of a Node

The depth of a node is the number of edges from the root to that node.

Example:

    10
   /  \
  20   30
 /
40

Depth:

10 → 0
20 → 1
30 → 1
40 → 2
8. Binary Tree Traversals

Traversal means visiting every node of a tree exactly once.

The four major binary tree traversals are:

Preorder Traversal
Inorder Traversal
Postorder Traversal
Level Order Traversal
9. Preorder Traversal

Preorder follows:

Root → Left → Right

Shortcut:

NLR

where:

N = Node
L = Left
R = Right

Example:

    10
   /  \
  20   30

Preorder:

10 20 30
Algorithm
Start from the root.
Visit and print the root node.
Recursively traverse the left subtree.
Recursively traverse the right subtree.
Stop when the current node becomes NULL.
Time Complexity
O(n)
Space Complexity
O(h)

Where h is the height of the tree.

10. Inorder Traversal

Inorder follows:

Left → Root → Right

Shortcut:

LNR

Example:

    10
   /  \
  20   30

Inorder:

20 10 30
Algorithm
Start from the root.
Recursively traverse the left subtree.
Visit and print the root node.
Recursively traverse the right subtree.
Stop when the current node becomes NULL.
Time Complexity
O(n)
Space Complexity
O(h)

Where h is the height of the tree.

11. Postorder Traversal

Postorder follows:

Left → Right → Root

Shortcut:

LRN

Example:

    10
   /  \
  20   30

Postorder:

20 30 10
Algorithm
Start from the root.
Recursively traverse the left subtree.
Recursively traverse the right subtree.
Visit and print the root node.
Stop when the current node becomes NULL.
Time Complexity
O(n)
Space Complexity
O(h)

Where h is the height of the tree.

12. Level Order Traversal

Level Order Traversal visits nodes level by level.

It uses a queue.

Example:

    10
   /  \
  20   30
 / \
40  50

Level Order:

10 20 30 40 50
Algorithm
Create an empty queue.
Insert the root into the queue.
Remove a node from the front of the queue.
Visit and print the node.
Insert its left child into the queue if it exists.
Insert its right child into the queue if it exists.
Repeat until the queue becomes empty.
Time Complexity
O(n)
Space Complexity
O(n)
13. Comparison of Tree Traversals
Traversal	Order	Commonly Used Structure
Preorder	Root → Left → Right	Recursion / Stack
Inorder	Left → Root → Right	Recursion / Stack
Postorder	Left → Right → Root	Recursion / Stack
Level Order	Level by Level	Queue
14. Counting Nodes

Counting nodes means finding the total number of nodes present in a binary tree.

For every non-NULL node:

Total Nodes =
1 + Left Subtree Nodes + Right Subtree Nodes

Example:

    10
   /  \
  20   30

Total Nodes:

3
Algorithm
Start from the root.
If the root is NULL, return 0.
Count the current node as 1.
Recursively count nodes in the left subtree.
Recursively count nodes in the right subtree.
Add all results.
Return the total count.
Time Complexity
O(n)
Space Complexity
O(h)

Where h is the height of the tree.

15. Counting Leaf Nodes

A leaf node is a node that has no children.

Condition:

left == NULL
AND
right == NULL

Example:

    10
   /  \
  20   30

Leaf Nodes:

20
30

Number of Leaf Nodes:

2
Algorithm
Start from the root.
If the root is NULL, return 0.
Check whether the current node has no left and right child.
If it is a leaf node, return 1.
Otherwise, recursively count leaf nodes in the left subtree.
Recursively count leaf nodes in the right subtree.
Add both results.
Return the total count.
Time Complexity
O(n)
Space Complexity
O(h)

Where h is the height of the tree.

16. Creating a Binary Tree

Binary tree nodes can be dynamically created using malloc() in C.

Example:

struct Node *newNode;

newNode = (struct Node *)malloc(sizeof(struct Node));

newNode->data = 10;
newNode->left = NULL;
newNode->right = NULL;

The left and right pointers are initially set to NULL.

17. Types of Binary Trees

Important types of binary trees include:

Full Binary Tree
Complete Binary Tree
Perfect Binary Tree
Balanced Binary Tree
Skewed Binary Tree
18. Full Binary Tree

A Full Binary Tree is a binary tree in which every node has either:

0 children
2 children

Example:

    1
   / \
  2   3
 / \
4   5

Every node has either 0 or 2 children.

19. Complete Binary Tree

A Complete Binary Tree is a binary tree in which:

All levels except possibly the last are completely filled.
The last level is filled from left to right.

Example:

    1
   / \
  2   3
 / \  /
4  5 6

This is a complete binary tree.

20. Perfect Binary Tree

A Perfect Binary Tree is a binary tree in which:

Every internal node has exactly two children.
All leaf nodes are at the same level.

Example:

    1
   / \
  2   3
 / \ / \
4  5 6  7
21. Balanced Binary Tree

A balanced binary tree is a tree where the heights of the left and right subtrees are kept relatively balanced.

Balanced trees generally provide better performance for searching and other operations.

An AVL Tree is an important example of a self-balancing Binary Search Tree.

22. Skewed Binary Tree

A skewed binary tree is a tree where nodes mostly exist on one side.

Left-Skewed Tree
    10
    /
   20
   /
  30
  /
 40
Right-Skewed Tree
10
  \
   20
     \
      30
        \
         40

A skewed binary tree can behave similarly to a linked list.

23. Binary Tree vs Binary Search Tree

A Binary Tree does not have any specific ordering rule for its values.

A Binary Search Tree follows:

Left Subtree < Root < Right Subtree

Example of a BST:

    50
   /  \
  30   70
 / \   / \
20 40 60 80

Every Binary Search Tree is a Binary Tree, but every Binary Tree is not a Binary Search Tree.

24. Advantages of Binary Trees
Represents hierarchical data naturally.
Dynamic memory allocation is possible.
Provides different traversal techniques.
Forms the foundation of BSTs, AVL Trees, Heaps, and other tree structures.
Useful for representing hierarchical relationships.
Can be used for efficient searching when properly structured.
25. Disadvantages of Binary Trees
Requires additional memory for pointers.
Traversal is more complicated than simple arrays.
An unbalanced tree can become inefficient.
Dynamic memory management is required in C.
Maintaining balanced structures may require additional operations.
26. Applications of Binary Trees

Binary Trees are used in:

Searching
Sorting
Expression Evaluation
Expression Trees
Compiler Design
File Systems
Hierarchical Data
Binary Search Trees
AVL Trees
Heaps
Decision Trees
Database indexing concepts
27. Time Complexity

For a binary tree containing n nodes:

Operation	Time Complexity
Preorder Traversal	O(n)
Inorder Traversal	O(n)
Postorder Traversal	O(n)
Level Order Traversal	O(n)
Count Nodes	O(n)
Count Leaf Nodes	O(n)

Every node may need to be visited, so these operations take O(n) time.

28. Space Complexity

For recursive tree operations:

O(h)

Where:

h = height of the tree

For a balanced tree:

h = O(log n)

For a completely skewed tree:

h = O(n)

Level Order Traversal can require:

O(n)

space for the queue in the worst case.

29. Important Formulas
Maximum Nodes at Level L
Maximum Nodes = 2^L
Maximum Nodes for Height h
Maximum Nodes = 2^(h + 1) - 1
Minimum Height for n Nodes

Approximately:

log2(n)

For a complete/perfect tree, height is approximately:

floor(log2(n))
30. Important Exam Points
A Binary Tree is a non-linear data structure.
A node can have at most two children.
The two children are called left and right children.
The topmost node is called the root.
A node with no children is called a leaf node.
Nodes having the same parent are called siblings.
Preorder = Root → Left → Right.
Inorder = Left → Root → Right.
Postorder = Left → Right → Root.
Level Order visits nodes level by level.
Level Order uses a queue.
Recursive traversals use the call stack.
Maximum nodes at level L = 2^L.
Maximum nodes for height h = 2^(h+1) - 1.
A Full Binary Tree has either 0 or 2 children for every node.
A Complete Binary Tree fills the last level from left to right.
A Perfect Binary Tree has all internal nodes with two children and all leaves at the same level.
A skewed tree can behave like a linked list.
Inorder traversal of a Binary Search Tree produces sorted order.
Binary Trees form the foundation for BSTs, AVL Trees, and Heaps.
31. Overall Binary Tree Concept

The basic structure is:

    Root
   /    \
Left    Right
/  \    /  \

... ... ... ...

The major operations are:

Creation
   ↓
Traversal
   ↓
Counting
   ↓
Processing
   ↓
Advanced Tree Structures

The four important traversal orders are:

Preorder
Root → Left → Right

Inorder
Left → Root → Right

Postorder
Left → Right → Root

Level Order
Level by Level
Conclusion

A Binary Tree is one of the most important non-linear data structures.

It allows data to be represented hierarchically and provides the foundation for many advanced tree-based data structures.

The four major traversal techniques are:

Preorder
Inorder
Postorder
Level Order

Understanding Binary Tree creation, traversal, node counting, leaf-node counting, and tree properties is essential before moving to:

Binary Search Trees
Threaded Binary Trees
AVL Trees
Heaps

Therefore, the Binary Tree is a fundamental building block for understanding advanced tree data structures.


**This is the format I'll use for every future `.md` file: one complete block, rea