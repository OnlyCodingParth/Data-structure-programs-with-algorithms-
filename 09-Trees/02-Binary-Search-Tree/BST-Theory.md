# Binary Search Tree (BST)

## 1. Introduction

A Binary Search Tree (BST) is a special type of Binary Tree in which the nodes are arranged according to a specific ordering rule.

The main purpose of a BST is to make operations such as:

- Searching
- Insertion
- Deletion
- Finding minimum
- Finding maximum

more efficient than in an ordinary Binary Tree.

---

## 2. Definition of Binary Search Tree

A Binary Search Tree is a binary tree where, for every node:

- All values in the left subtree are smaller than the node value.
- All values in the right subtree are greater than the node value.

For example:

                    50
                  /    \
                30      70
               /  \    /  \
             20   40  60   80

For the root node 50:

Left subtree values = 20, 30, 40
Right subtree values = 60, 70, 80

Therefore, the BST property is satisfied.

---

## 3. BST Property

For every node:

                    Left Subtree < Node < Right Subtree

This rule must be maintained throughout the entire tree.

Example:

                    50
                  /    \
                30      70
               /  \    /  \
             20   40  60   80

20 < 30 < 40

60 < 70 < 80

30 < 50 < 70

Therefore, it is a valid BST.

---

## 4. Node Structure

A basic BST node contains:

- Data
- Pointer to left child
- Pointer to right child

A C structure can be represented as:

    struct Node
    {
        int data;
        struct Node *left;
        struct Node *right;
    };

---

## 5. Important BST Terminology

### Root

The topmost node of the tree.

Example:

                    50

Here, 50 is the root.

### Parent

A node that has one or more children.

Example:

                    50
                   /
                 30

50 is the parent of 30.

### Child

A node directly connected below another node.

30 is the child of 50.

### Leaf Node

A node having no children.

Example:

                    50
                  /    \
                30      70
               /  \    /  \
             20   40  60   80

20, 40, 60 and 80 are leaf nodes.

### Internal Node

A node having at least one child.

50, 30 and 70 are internal nodes in the above example.

### Subtree

A smaller tree formed from any node and its descendants.

---

# 6. Creation of a BST

A BST is normally created by inserting elements one by one.

Suppose we insert:

    50, 30, 70, 20, 40, 60, 80

The BST becomes:

                    50
                  /    \
                30      70
               /  \    /  \
             20   40  60   80

The first element generally becomes the root.

For every next element:

1. Compare it with the current node.
2. If the value is smaller, move to the left.
3. If the value is greater, move to the right.
4. Continue until an empty position is found.
5. Insert the new node there.

---

# 7. BST Insertion

Insertion means adding a new value into the BST while maintaining the BST property.

Example:

Existing tree:

                    50
                  /    \
                30      70

Insert 20.

20 < 50

Move left.

20 < 30

Move left again.

The position is empty, so insert 20.

Result:

                    50
                  /    \
                30      70
               /
             20

---

## Insertion Algorithm

1. Create a new node.
2. If the tree is empty, make the new node the root.
3. Compare the new value with the current node.
4. If the value is smaller, move to the left subtree.
5. If the value is greater, move to the right subtree.
6. Repeat until an empty position is found.
7. Insert the new node at that position.

---

# 8. BST Searching

Searching means finding whether a particular value exists in the BST.

Example:

                    50
                  /    \
                30      70
               /  \    /  \
             20   40  60   80

Search for 60.

Step 1:

60 > 50

Move right.

Step 2:

60 < 70

Move left.

Step 3:

60 == 60

Element found.

---

## Searching Algorithm

1. Start from the root.
2. Compare the search value with the current node.
3. If both values are equal, the element is found.
4. If the search value is smaller, move to the left subtree.
5. If the search value is greater, move to the right subtree.
6. Repeat until the element is found or NULL is reached.

---

# 9. Minimum Element

In a BST, the minimum element is the leftmost node.

Example:

                    50
                  /    \
                30      70
               /  \
             20   40

The minimum element is:

    20

To find the minimum:

1. Start from the root.
2. Keep moving to the left.
3. Stop when the left pointer becomes NULL.
4. The current node contains the minimum value.

---

# 10. Maximum Element

In a BST, the maximum element is the rightmost node.

Example:

                    50
                  /    \
                30      70
               /  \    /  \
             20   40  60   80

The maximum element is:

    80

To find the maximum:

1. Start from the root.
2. Keep moving to the right.
3. Stop when the right pointer becomes NULL.
4. The current node contains the maximum value.

---

# 11. BST Deletion

Deletion means removing a node from the BST while maintaining the BST property.

Deletion is one of the most important BST operations.

There are three main cases.

---

## Case 1: Deleting a Leaf Node

A leaf node has no children.

Example:

                    50
                  /    \
                30      70
               /
             20

Delete 20.

Since 20 has no children, simply remove it.

Result:

                    50
                  /    \
                30      70

---

## Case 2: Deleting a Node with One Child

Example:

                    50
                  /    \
                30      70
               /
             20
            /
          10

Suppose we delete 20.

20 has only one child: 10.

The child 10 takes the position of 20.

Result:

                    50
                  /    \
                30      70
               /
             10

---

## Case 3: Deleting a Node with Two Children

Example:

                    50
                  /    \
                30      70
               /  \    /  \
             20   40  60   80

Suppose we delete 50.

50 has two children.

We can replace 50 with:

- Inorder successor, or
- Inorder predecessor.

### Inorder Successor

The inorder successor is the smallest value in the right subtree.

For 50:

Right subtree:

                    70
                   /  \
                 60    80

The smallest value is 60.

Therefore, 60 can replace 50.

### Inorder Predecessor

The inorder predecessor is the largest value in the left subtree.

For 50:

Left subtree:

                    30
                   /  \
                 20    40

The largest value is 40.

Therefore, 40 can also replace 50.

---

# 12. BST Traversals

A BST can be traversed using different traversal methods.

The main traversals are:

1. Preorder
2. Inorder
3. Postorder
4. Level Order

---

## Preorder Traversal

Order:

    Root → Left → Right

For:

                    50
                  /    \
                30      70
               /  \    /  \
             20   40  60   80

Preorder:

    50 30 20 40 70 60 80

---

## Inorder Traversal

Order:

    Left → Root → Right

For the same BST:

    20 30 40 50 60 70 80

An important property of BST:

### Inorder traversal of a valid BST gives values in sorted ascending order.

This is one of the most important BST facts for exams and interviews.

---

## Postorder Traversal

Order:

    Left → Right → Root

For the same BST:

    20 40 30 60 80 70 50

---

## Level Order Traversal

Level Order visits nodes level by level.

For the same BST:

    50 30 70 20 40 60 80

Level Order traversal generally uses a queue.

---

# 13. Example of BST

Consider the following values:

    50, 30, 70, 20, 40, 60, 80

BST:

                    50
                  /    \
                30      70
               /  \    /  \
             20   40  60   80

Properties:

- Root = 50
- Minimum = 20
- Maximum = 80
- Left child of 50 = 30
- Right child of 50 = 70
- Leaf nodes = 20, 40, 60, 80
- Inorder = 20, 30, 40, 50, 60, 70, 80

---

# 14. Balanced BST

A balanced BST has approximately equal height on both sides.

Example:

                    50
                  /    \
                30      70
               /  \    /  \
             20   40  60   80

This tree is relatively balanced.

Searching can be efficient because the tree height is small.

---

# 15. Skewed BST

A BST can become skewed when values are inserted in sorted order.

For example:

    10, 20, 30, 40, 50

The tree may become:

    10
      \
       20
         \
          30
            \
             40
               \
                50

This behaves similar to a linked list.

Therefore, searching, insertion and deletion can become slow.

---

# 16. Time Complexity of BST

The time complexity depends on the height of the tree.

Let:

    h = height of the tree

### Searching

Average case:

    O(log n)

Worst case:

    O(n)

### Insertion

Average case:

    O(log n)

Worst case:

    O(n)

### Deletion

Average case:

    O(log n)

Worst case:

    O(n)

### Minimum

    O(h)

### Maximum

    O(h)

### Traversal

    O(n)

---

# 17. Space Complexity

For storing n nodes:

    O(n)

Additional recursive stack space depends on the height of the tree:

    O(h)

For a balanced BST:

    O(log n)

For a skewed BST:

    O(n)

---

# 18. BST vs Binary Tree

| Feature | Binary Tree | Binary Search Tree |
|---------|-------------|--------------------|
| Ordering | No specific ordering | Left < Root < Right |
| Searching | Usually O(n) | Average O(log n) |
| Insertion | Depends on method | Based on BST property |
| Deletion | Depends on method | Based on BST property |
| Inorder | Not necessarily sorted | Sorted order |
| Main purpose | Hierarchical data | Efficient searching |

---

# 19. Advantages of BST

1. Searching can be fast.
2. Insertion can be fast.
3. Deletion can be efficient.
4. Minimum and maximum can be found easily.
5. Inorder traversal produces sorted data.
6. Dynamic data can be stored efficiently.
7. It provides an ordered structure.

---

# 20. Disadvantages of BST

1. A normal BST can become skewed.
2. Worst-case operations can become O(n).
3. Extra memory is required for pointers.
4. Maintaining balance manually can be difficult.
5. A balanced tree such as AVL or Red-Black Tree may be required for guaranteed efficient operations.

---

# 21. Applications of BST

BSTs can be used in:

- Searching systems
- Maintaining sorted data
- Dictionary implementations
- Symbol tables
- Database indexing concepts
- Maintaining dynamic ordered data
- Range searching
- Set implementations
- Map implementations
- Searching and sorting related applications

---

# 22. Important BST Facts

1. BST stands for Binary Search Tree.
2. Every BST is a binary tree.
3. Every binary tree is not necessarily a BST.
4. Left subtree values are smaller than the root.
5. Right subtree values are greater than the root.
6. Inorder traversal of a BST gives sorted order.
7. Minimum element is the leftmost node.
8. Maximum element is the rightmost node.
9. BST deletion has three major cases.
10. A BST can become skewed.
11. Balanced BSTs provide better performance.
12. Worst-case search, insertion and deletion can be O(n).
13. Average-case search, insertion and deletion are commonly O(log n) for a reasonably balanced BST.
14. BST uses dynamic memory and pointers in its linked-node implementation.

---

# 23. Important Exam/Viva Questions

### Q1. What is a BST?

A BST is a binary tree in which the left subtree contains smaller values and the right subtree contains greater values than the node.

### Q2. What is the main property of BST?

    Left Subtree < Root < Right Subtree

### Q3. Which traversal gives sorted order in BST?

Inorder traversal.

### Q4. Where is the minimum element located?

At the leftmost node.

### Q5. Where is the maximum element located?

At the rightmost node.

### Q6. How many cases are there in BST deletion?

Three:

1. Leaf node
2. Node with one child
3. Node with two children

### Q7. What happens if sorted data is inserted into a normal BST?

The BST can become skewed.

### Q8. What is the worst-case search complexity?

    O(n)

### Q9. What is the average search complexity of a reasonably balanced BST?

    O(log n)

### Q10. What can be used to replace a node having two children?

Its inorder successor or inorder predecessor.

---

# 24. Quick Revision

```text
BST
 |
 +-- Binary Tree
 |
 +-- Left subtree < Root
 |
 +-- Right subtree > Root
 |
 +-- Search
 |
 +-- Insertion
 |
 +-- Deletion
 |     |
 |     +-- Leaf
 |     +-- One Child
 |     +-- Two Children
 |
 +-- Minimum = Leftmost
 |
 +-- Maximum = Rightmost
 |
 +-- Inorder = Sorted Order
 |
 +-- Average Operations = O(log n)
 |
 +-- Worst Case = O(n)

 25. Overall Concept

The main idea of a Binary Search Tree is to keep data in an ordered binary-tree structure.

When searching for a value:

If the value is smaller than the current node, go left.
If the value is greater than the current node, go right.
If the value is equal to the current node, the value is found.

The same ordering property makes insertion and deletion possible.

The most important concept to remember is:

Left < Root < Right

And the most important traversal fact is:

Inorder Traversal of BST = Sorted Order

However, a normal BST does not automatically remain balanced. If it becomes skewed, its performance can degrade from approximately O(log n) to O(n).

This limitation leads to self-balancing trees such as AVL Trees and Red-Black Trees.

26. Conclusion

A Binary Search Tree is an important data structure used for storing and managing ordered data.

It provides efficient searching, insertion and deletion when the tree remains reasonably balanced.

The most important concepts of BST are:

BST property
Creation
Insertion
Searching
Deletion
Minimum and maximum
Tree traversals
Inorder sorted property
Balanced and skewed BST
Time and space complexity

Understanding BST is also important before learning advanced tree structures such as AVL Trees, Red-Black Trees and other balanced search trees.