# Binary Tree Theory

## 1. What is a Binary Tree?

A **Binary Tree** is a non-linear data structure in which each node can have at most two children.

The two children are called:

- Left Child
- Right Child

A node can have:

- No child
- One child
- Two children

### Example

          10
        /    \
      20      30
     /  \
   40   50

Here:

- `10` is the root.
- `20` is the left child of `10`.
- `30` is the right child of `10`.
- `40` and `50` are children of `20`.
- `40`, `50`, and `30` are leaf nodes.

---

## 2. Structure of a Binary Tree Node

A binary tree node contains three main parts:

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
- `left` stores the address of the left child.
- `right` stores the address of the right child.

---

## 3. Important Terms in Binary Tree

### Root

The first or topmost node of a tree is called the **root**.

Example:

          10

Here, `10` is the root.

---

### Parent Node

A node that has one or more children is called a **parent node**.

Example:

          10
        /    \
      20      30

Here, `10` is the parent of `20` and `30`.

---

### Child Node

A node directly connected below another node is called its **child**.

In the above example:

- `20` is the left child of `10`.
- `30` is the right child of `10`.

---

### Leaf Node

A node that does not have any child is called a **leaf node**.

Example:

          10
        /    \
      20      30

Here:

- `20` is a leaf node.
- `30` is a leaf node.

---

### Internal Node

A node having at least one child is called an **internal node**.

Example:

          10
        /
      20

Here, `10` is an internal node.

---

### Sibling Nodes

Nodes having the same parent are called **siblings**.

Example:

          10
        /    \
      20      30

Here, `20` and `30` are siblings.

---

### Subtree

A tree formed by a node and all of its descendants is called a **subtree**.

Example:

          10
        /    \
      20      30
     /  \
   40   50

The subtree rooted at `20` is:

        20
       /  \
     40    50

---

## 4. Creation of a Binary Tree

A binary tree can be created using dynamically allocated nodes.

Memory can be allocated using:

    malloc()

A new node contains:

- Data
- Left pointer
- Right pointer

Initially, the child pointers are generally set to:

    NULL

### Basic Steps

1. Create a new node.
2. Allocate memory using `malloc()`.
3. Store data in the node.
4. Set `left` to `NULL`.
5. Set `right` to `NULL`.
6. Connect the node to the required parent.

---

## 5. Example of Binary Tree Creation

Consider:

          10
        /    \
      20      30

Here:

- Create node `10`.
- Create node `20`.
- Create node `30`.
- Connect `20` to the left of `10`.
- Connect `30` to the right of `10`.

The final binary tree is:

          10
        /    \
      20      30

---

## 6. Traversal of Binary Tree

Traversal means visiting every node of the tree exactly once.

The main binary tree traversals are:

1. Preorder Traversal
2. Inorder Traversal
3. Postorder Traversal
4. Level Order Traversal

---

# 7. Preorder Traversal

Preorder traversal follows:

    Root → Left → Right

### Example

          10
        /    \
      20      30
     /  \
   40   50

Preorder traversal:

    10 20 40 50 30

### Steps

1. Visit the root.
2. Traverse the left subtree.
3. Traverse the right subtree.

### Algorithm

    Preorder(root)

    1. If root is NULL, return.
    2. Visit root.
    3. Preorder(root->left).
    4. Preorder(root->right).

---

# 8. Inorder Traversal

Inorder traversal follows:

    Left → Root → Right

### Example

          10
        /    \
      20      30
     /  \
   40   50

Inorder traversal:

    40 20 50 10 30

### Steps

1. Traverse the left subtree.
2. Visit the root.
3. Traverse the right subtree.

### Algorithm

    Inorder(root)

    1. If root is NULL, return.
    2. Inorder(root->left).
    3. Visit root.
    4. Inorder(root->right).

---

# 9. Postorder Traversal

Postorder traversal follows:

    Left → Right → Root

### Example

          10
        /    \
      20      30
     /  \
   40   50

Postorder traversal:

    40 50 20 30 10

### Steps

1. Traverse the left subtree.
2. Traverse the right subtree.
3. Visit the root.

### Algorithm

    Postorder(root)

    1. If root is NULL, return.
    2. Postorder(root->left).
    3. Postorder(root->right).
    4. Visit root.

---

# 10. Level Order Traversal

Level Order Traversal visits nodes level by level.

It generally uses a **Queue**.

### Example

          10
        /    \
      20      30
     /  \    /  \
   40   50  60   70

Level Order:

    10 20 30 40 50 60 70

### Steps

1. Insert the root into the queue.
2. Remove one node from the queue.
3. Visit that node.
4. Insert its left child into the queue.
5. Insert its right child into the queue.
6. Continue until the queue becomes empty.

---

## 11. Difference Between DFS and BFS

Tree traversals can be broadly divided into:

### Depth First Search (DFS)

DFS explores deeper nodes first.

The following are DFS traversals:

- Preorder
- Inorder
- Postorder

DFS generally uses recursion or a stack.

### Breadth First Search (BFS)

BFS visits nodes level by level.

In a binary tree:

- Level Order Traversal is BFS.

BFS generally uses a queue.

---

# 12. Counting Total Nodes

The total number of nodes can be counted recursively.

For every node:

    Total Nodes =
    1 + Nodes in Left Subtree + Nodes in Right Subtree

### Example

          10
        /    \
      20      30

Total nodes:

    3

### Recursive Idea

    count(root)

    If root is NULL:
        return 0

    return 1 + count(root->left) + count(root->right)

---

# 13. Counting Leaf Nodes

A leaf node is a node with:

    left == NULL
    right == NULL

### Example

          10
        /    \
      20      30
     /  \
   40   50

Leaf nodes:

    40, 50, 30

Total leaf nodes:

    3

### Recursive Idea

    countLeaf(root)

    If root is NULL:
        return 0

    If root has no children:
        return 1

    return countLeaf(root->left)
           + countLeaf(root->right)

---

# 14. Height of Binary Tree

The height of a binary tree represents the longest path from the root to a leaf.

For example:

          10
        /    \
      20      30
     /
   40

The longest path is:

    10 → 20 → 40

If height is counted using edges:

    Height = 2

If height is counted using nodes:

    Height = 3

### Important Point

Different textbooks may define height differently, so always check the convention being used.

---

# 15. Depth of a Node

The depth of a node is the number of edges from the root to that node.

Example:

          10
        /    \
      20      30
     /
   40

Depth of:

- `10` = 0
- `20` = 1
- `30` = 1
- `40` = 2

---

# 16. Level of a Node

The level of a node represents its position from the root.

Depending on the convention:

- Root may be considered Level 0.
- Or root may be considered Level 1.

Therefore, the convention should be specified in exams or implementations.

---

# 17. Properties of Binary Tree

Some important properties of a binary tree are:

### Property 1

Every node can have at most:

    2 children

### Property 2

The maximum number of nodes at level `l`, when root is at level 0, is:

    2^l

### Property 3

The maximum number of nodes in a binary tree of height `h`, when height is counted in edges, is:

    2^(h + 1) - 1

### Property 4

A binary tree with `n` nodes has:

    n - 1

edges, provided the tree is non-empty.

### Property 5

Every node except the root has exactly one parent.

---

# 18. Types of Binary Trees

Important types of binary trees include:

1. Full Binary Tree
2. Complete Binary Tree
3. Perfect Binary Tree
4. Balanced Binary Tree
5. Skewed Binary Tree

---

# 19. Full Binary Tree

A **Full Binary Tree** is a binary tree in which every node has either:

- 0 children
- 2 children

A node cannot have exactly one child.

Example:

          10
        /    \
      20      30
     /  \
   40   50

Every internal node has exactly two children.

Therefore, it is a full binary tree.

---

# 20. Complete Binary Tree

A **Complete Binary Tree** is a binary tree in which:

- All levels except possibly the last are completely filled.
- The last level is filled from left to right.

Example:

          10
        /    \
      20      30
     /  \    /
   40   50  60

The last level is filled from left to right.

Therefore, this is a complete binary tree.

Complete binary trees are important in:

- Heap
- Priority Queue

---

# 21. Perfect Binary Tree

A **Perfect Binary Tree** is a binary tree in which:

- Every internal node has exactly two children.
- All leaf nodes are at the same level.

Example:

          10
        /    \
      20      30
     /  \    /  \
   40   50  60   70

All levels are completely filled.

---

# 22. Balanced Binary Tree

A balanced binary tree is a tree where the heights of the left and right subtrees are kept relatively balanced.

Balanced trees help maintain efficient operations.

Examples of balanced tree structures include:

- AVL Tree
- Red-Black Tree

---

# 23. Skewed Binary Tree

A skewed binary tree is a tree in which most nodes have only one child.

### Left-Skewed Tree

        10
       /
     20
    /
  30
 /
40

### Right-Skewed Tree

    10
      \
       20
         \
          30
            \
             40

A skewed tree behaves similarly to a linked list.

---

# 24. Binary Tree vs Binary Search Tree

A Binary Search Tree is a special type of binary tree.

| Binary Tree | Binary Search Tree |
|---|---|
| Each node has at most two children | Each node has at most two children |
| No ordering rule is required | Follows an ordering rule |
| Left child can contain any value | Left values are smaller |
| Right child can contain any value | Right values are greater |
| Searching may be slower | Searching can be faster |
| Inorder is not necessarily sorted | Inorder gives sorted order |

### BST Rule

    Left Subtree < Root < Right Subtree

---

# 25. Binary Tree Traversal Example

Consider:

          10
        /    \
      20      30
     /  \    /  \
   40   50  60   70

### Preorder

    10 20 40 50 30 60 70

### Inorder

    40 20 50 10 60 30 70

### Postorder

    40 50 20 60 70 30 10

### Level Order

    10 20 30 40 50 60 70

---

# 26. Time Complexity of Binary Tree Operations

| Operation | Time Complexity |
|---|---:|
| Creation of one node | O(1) |
| Traversal | O(n) |
| Searching | O(n) |
| Counting nodes | O(n) |
| Counting leaf nodes | O(n) |
| Finding height | O(n) |

### Why is traversal O(n)?

Because every node must be visited.

If there are `n` nodes:

    Time = O(n)

---

# 27. Space Complexity

The space complexity depends on the implementation.

### Recursive Traversal

Recursive traversal uses the call stack.

For a balanced tree:

    O(log n)

For a skewed tree:

    O(n)

### Level Order Traversal

Level Order uses a queue.

Its auxiliary space can be:

    O(n)

in the worst case.

---

# 28. Advantages of Binary Tree

1. Represents hierarchical data naturally.
2. Dynamic size is possible.
3. Insertion and deletion can be efficient depending on the tree structure.
4. Useful for implementing other data structures.
5. Recursive traversal is simple.
6. Useful for representing hierarchical relationships.
7. Forms the foundation for BST, Heap, AVL Tree, and other tree structures.

---

# 29. Disadvantages of Binary Tree

1. Requires additional memory for pointers.
2. Implementation is more complex than arrays.
3. Searching in a general binary tree can require O(n) time.
4. Recursive operations use stack memory.
5. An unbalanced tree can become inefficient for some operations.

---

# 30. Applications of Binary Tree

Binary trees are used in:

- Expression trees
- Searching structures
- File systems
- Hierarchical data
- Compiler design
- Decision trees
- Game development
- Artificial intelligence
- Database systems
- Heaps
- Binary Search Trees
- AVL Trees
- Red-Black Trees

---

# 31. Binary Tree and Recursion

Binary trees are commonly processed using recursion because every node can have two subtrees.

For example:

    root
    ├── left subtree
    └── right subtree

A recursive function can process:

1. Current node
2. Left subtree
3. Right subtree

This is why preorder, inorder, postorder, counting nodes, and calculating height are commonly implemented recursively.

---

# 32. Important Exam Points

### Point 1

A binary tree allows at most:

    2 children per node

### Point 2

The three main DFS traversals are:

    Preorder
    Inorder
    Postorder

### Point 3

Preorder:

    Root → Left → Right

### Point 4

Inorder:

    Left → Root → Right

### Point 5

Postorder:

    Left → Right → Root

### Point 6

Level Order:

    Level by Level

### Point 7

Level Order traversal generally uses:

    Queue

### Point 8

DFS can use:

    Recursion or Stack

### Point 9

A leaf node has:

    No children

### Point 10

A full binary tree allows each node to have:

    0 or 2 children

### Point 11

A complete binary tree fills the last level:

    From left to right

### Point 12

A perfect binary tree has:

    All internal nodes with 2 children
    All leaves at the same level

### Point 13

A skewed binary tree behaves similarly to:

    Linked List

### Point 14

Traversal of a binary tree takes:

    O(n)

time.

---

# 33. Binary Tree Operation Summary

| Operation | Main Idea |
|---|---|
| Creation | Create nodes and connect them |
| Traversal | Visit all nodes |
| Preorder | Root → Left → Right |
| Inorder | Left → Root → Right |
| Postorder | Left → Right → Root |
| Level Order | Level by level |
| Count Nodes | Count every node |
| Count Leaf Nodes | Count nodes having no children |
| Height | Find longest path from root |
| Searching | Check nodes until value is found |

---

# 34. Overall Concept

A Binary Tree is a hierarchical, non-linear data structure in which every node can have at most two children.

The two children are:

    Left Child
    Right Child

The most important operations are:

1. Creation
2. Traversal
3. Searching
4. Counting Nodes
5. Counting Leaf Nodes
6. Finding Height

The most important traversal orders are:

    Preorder  = Root → Left → Right

    Inorder   = Left → Root → Right

    Postorder = Left → Right → Root

    Level Order = Level by Level

Binary Trees are the foundation for many advanced data structures such as:

- Binary Search Trees
- Heaps
- AVL Trees
- Red-Black Trees
- Expression Trees

---

# 35. Conclusion

A **Binary Tree** is one of the fundamental non-linear data structures in computer science.

Each node can have at most two children, called the left child and right child.

Understanding binary trees is important because many advanced tree-based data structures are built on the same concepts.

The most important concepts to remember are:

    Binary Tree
    Root
    Parent
    Child
    Leaf
    Subtree
    Traversal
    Preorder
    Inorder
    Postorder
    Level Order
    Height
    Full Binary Tree
    Complete Binary Tree
    Perfect Binary Tree
    Balanced Binary Tree
    Skewed Binary Tree

Once these concepts are clear, learning **Binary Search Trees, Heaps, AVL Trees, and other advanced tree structures** becomes much easier.