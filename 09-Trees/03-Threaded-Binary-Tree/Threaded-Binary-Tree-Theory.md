# Threaded Binary Tree - Complete Theory

## 1. Introduction

A Threaded Binary Tree is a special type of binary tree in which NULL pointers are replaced with useful links called threads.

In a normal binary tree, many left and right pointers are NULL.

These NULL pointers do not contain useful information.

A threaded binary tree uses these NULL pointers to store links to other nodes, usually related to inorder traversal.

The main purpose of a threaded binary tree is to make tree traversal easier and more efficient.

A major advantage is that inorder traversal can be performed without recursion and without using an extra stack.

---

# 2. Why Threaded Binary Tree is Needed

Consider a normal binary tree:

              50
             /  \
           30    70
          /  \
        20    40

Inorder traversal:

20 30 40 50 70

In a normal binary tree, several pointers are NULL.

For example:

- Node 20 has no left child.
- Node 20 has no right child.
- Node 40 has no left child.
- Node 40 has no right child.
- Node 70 has no left child.
- Node 70 has no right child.

Instead of keeping these pointers NULL, a threaded binary tree can use them to store traversal-related information.

---

# 3. What is a Thread?

A thread is a pointer that replaces a NULL child pointer and points to another useful node.

For inorder traversal:

- A left thread points to the inorder predecessor.
- A right thread points to the inorder successor.

Therefore, threads help us move from one node to the next without using recursion or a stack.

---

# 4. Types of Threaded Binary Trees

There are mainly three types:

1. Left-Threaded Binary Tree
2. Right-Threaded Binary Tree
3. Double-Threaded Binary Tree

---

# 5. Left-Threaded Binary Tree

In a left-threaded binary tree, NULL left pointers are replaced by threads.

The left thread points to the inorder predecessor.

Example:

              50
             /  \
           30    70
          /  \
        20    40

Inorder:

20 30 40 50 70

Possible left threads:

20 -> NULL

40 -> 30

70 -> 50

The left pointer of a node may therefore contain either:

- An actual left child
- An inorder predecessor thread

A flag is used to distinguish between them.

---

# 6. Left Thread Flag

For a left-threaded tree:

leftThread = 0

means:

The left pointer is an actual left child.

leftThread = 1

means:

The left pointer is an inorder predecessor thread.

Example:

Node 40:

left = 30
leftThread = 1

This means 40 does not have a real left child.

Its left pointer points to its inorder predecessor, 30.

---

# 7. Right-Threaded Binary Tree

In a right-threaded binary tree, NULL right pointers are replaced by threads.

The right thread points to the inorder successor.

Example:

              50
             /  \
           30    70
          /  \
        20    40

Inorder:

20 30 40 50 70

Possible right threads:

20 -> 30

40 -> 50

70 -> NULL

The right pointer of a node may therefore contain either:

- An actual right child
- An inorder successor thread

---

# 8. Right Thread Flag

For a right-threaded tree:

rightThread = 0

means:

The right pointer is an actual right child.

rightThread = 1

means:

The right pointer is an inorder successor thread.

Example:

Node 40:

right = 50
rightThread = 1

This means 40 does not have a real right child.

Its right pointer points to its inorder successor, 50.

---

# 9. Double-Threaded Binary Tree

A Double-Threaded Binary Tree uses both left and right NULL pointers as threads.

Therefore:

- Left thread -> inorder predecessor
- Right thread -> inorder successor

Example:

              50
             /  \
           30    70
          /  \
        20    40

Inorder:

20 30 40 50 70

Threads:

Node 20:
left -> NULL
right -> 30

Node 40:
left -> 30
right -> 50

Node 70:
left -> 50
right -> NULL

---

# 10. Node Structure of Double-Threaded Tree

A common C structure is:

    struct Node
    {
        int data;
        struct Node *left;
        struct Node *right;
        int leftThread;
        int rightThread;
    };

Here:

data
stores the value.

left
stores either a left child or predecessor thread.

right
stores either a right child or successor thread.

leftThread
identifies whether left is a thread.

rightThread
identifies whether right is a thread.

---

# 11. Meaning of Thread Flags

## Left Thread

leftThread = 0

Left pointer is an actual child.

leftThread = 1

Left pointer is an inorder predecessor thread.

## Right Thread

rightThread = 0

Right pointer is an actual child.

rightThread = 1

Right pointer is an inorder successor thread.

---

# 12. Inorder Predecessor

The inorder predecessor of a node is the node that comes immediately before it in inorder traversal.

For:

              50
             /  \
           30    70
          /  \
        20    40

Inorder:

20 30 40 50 70

Therefore:

Predecessor of 30 = 20

Predecessor of 40 = 30

Predecessor of 50 = 40

Predecessor of 70 = 50

A left thread can point to the inorder predecessor.

---

# 13. Inorder Successor

The inorder successor of a node is the node that comes immediately after it in inorder traversal.

For:

              50
             /  \
           30    70
          /  \
        20    40

Inorder:

20 30 40 50 70

Therefore:

Successor of 20 = 30

Successor of 30 = 40

Successor of 40 = 50

Successor of 50 = 70

A right thread can point to the inorder successor.

---

# 14. Normal Binary Tree vs Threaded Binary Tree

| Feature | Normal Binary Tree | Threaded Binary Tree |
|---|---|---|
| NULL pointers | Remain NULL | Used as threads |
| Traversal | Usually recursion/stack | Can use threads |
| Extra stack | Often required | Not required for threaded inorder |
| Traversal | More overhead | More efficient traversal |
| Pointer meaning | Child or NULL | Child or thread |
| Flags | Usually not required | Required |

---

# 15. Left-Threaded vs Right-Threaded

| Feature | Left-Threaded | Right-Threaded |
|---|---|---|
| Thread location | Left pointer | Right pointer |
| Thread points to | Inorder predecessor | Inorder successor |
| Main flag | leftThread | rightThread |
| Traversal information | Previous node | Next node |

---

# 16. Single-Threaded vs Double-Threaded

A single-threaded tree uses only one side for threads.

It can be:

- Left-threaded
- Right-threaded

A double-threaded tree uses both sides.

Therefore:

Single-threaded:

One type of thread is used.

Double-threaded:

Both predecessor and successor threads are used.

---

# 17. Creation of Threaded Binary Tree

Creation involves:

1. Creating nodes.
2. Connecting actual child pointers.
3. Finding NULL child pointers.
4. Finding inorder predecessors and successors.
5. Replacing suitable NULL pointers with threads.
6. Setting the appropriate thread flags.

For a double-threaded tree:

- NULL left pointer -> predecessor
- NULL right pointer -> successor

---

# 18. Inorder Traversal

Inorder traversal follows:

Left -> Root -> Right

A threaded tree makes inorder traversal easier because threads directly provide predecessor or successor information.

For a right-threaded tree:

1. Start at root.
2. Move to the leftmost node.
3. Print the node.
4. If rightThread is 1, follow the right thread.
5. Otherwise move to the right child.
6. Again move to the leftmost node.
7. Continue until traversal is complete.

---

# 19. Inorder Traversal Example

Tree:

              50
             /  \
           30    70
          /  \
        20    40

Inorder:

20 30 40 50 70

Using threads:

20 -> 30 -> 40 -> 50 -> 70

Therefore, the traversal can move directly between nodes.

---

# 20. Preorder Traversal

Preorder traversal follows:

Root -> Left -> Right

For a threaded tree, thread pointers must not be treated as actual children.

Before moving through a pointer, we must check the appropriate thread flag.

For example:

if leftThread == 0

the left pointer is a real child.

If:

leftThread == 1

the left pointer is a thread and must not be treated as a child.

Similarly:

if rightThread == 0

the right pointer is a real child.

If:

rightThread == 1

the right pointer is a thread.

---

# 21. Search in Threaded Binary Tree

If the threaded tree also follows Binary Search Tree ordering, searching can be performed similarly to a BST.

BST property:

Left subtree < Root < Right subtree

During search:

1. Start from root.
2. Compare the required value with current node.
3. If equal, the value is found.
4. If smaller, move left only if the left pointer is a real child.
5. If greater, move right only if the right pointer is a real child.
6. Never treat a thread as a child.

---

# 22. Insertion in Threaded Binary Tree

Insertion must maintain two things:

1. Binary Search Tree property
2. Thread relationships

For a new left child:

The new node's predecessor is the parent's old predecessor.

The new node's successor is the parent.

For a new right child:

The new node's predecessor is the parent.

The new node's successor is the parent's old successor.

Therefore, insertion requires careful updating of thread pointers.

---

# 23. Left Insertion in Double-Threaded Tree

Suppose a new node is inserted as the left child of parent.

Before insertion:

parent->left

may be a predecessor thread.

The new node receives:

newNode->left = parent->left

newNode->leftThread = 1

newNode->right = parent

newNode->rightThread = 1

Then:

parent->left = newNode

parent->leftThread = 0

This preserves predecessor and successor relationships.

---

# 24. Right Insertion in Double-Threaded Tree

Suppose a new node is inserted as the right child of parent.

The new node receives:

newNode->left = parent

newNode->leftThread = 1

newNode->right = parent->right

newNode->rightThread = 1

Then:

parent->right = newNode

parent->rightThread = 0

This preserves the threading structure.

---

# 25. Important Threaded Tree Rules

Remember these rules:

1. A thread is not a real child.

2. Always check the thread flag before treating a pointer as a child.

3. leftThread = 1 means predecessor thread.

4. rightThread = 1 means successor thread.

5. leftThread = 0 means real left child.

6. rightThread = 0 means real right child.

7. Right threads are useful for finding inorder successors.

8. Left threads are useful for finding inorder predecessors.

9. Threaded trees are especially useful for traversal.

10. Inorder traversal can be performed without recursion and without an explicit stack.

---

# 26. Advantages of Threaded Binary Tree

1. Inorder traversal can be performed without recursion.

2. No explicit stack is required for threaded inorder traversal.

3. NULL pointers are used effectively.

4. Inorder successor can be accessed quickly using right threads.

5. Inorder predecessor can be accessed quickly using left threads.

6. Traversal can be efficient.

7. It makes use of otherwise unused NULL pointers.

---

# 27. Disadvantages of Threaded Binary Tree

1. Implementation is more complicated than a normal binary tree.

2. Thread flags must be maintained correctly.

3. Insertion is more complicated.

4. Deletion is more complicated.

5. Developers must distinguish between child pointers and thread pointers.

6. Extra flag fields are required.

7. Debugging can be more difficult.

---

# 28. Time Complexity

For a threaded binary tree:

## Creation

O(n)

## Inorder Traversal

O(n)

## Preorder Traversal

O(n)

## Search

Average:

O(log n)

Worst:

O(n)

## Insertion

Average:

O(log n)

Worst:

O(n)

The exact search and insertion performance depends on the height of the tree.

---

# 29. Space Complexity

Each node stores:

- data
- left pointer
- right pointer
- thread flags

The tree requires:

O(n)

memory for n nodes.

Threaded inorder traversal requires:

O(1)

additional traversal space because no recursion or explicit stack is required.

---

# 30. Threaded Binary Tree and BST

A threaded binary tree is not necessarily a different ordering structure from a BST.

Threading is mainly a method of using NULL pointers.

A threaded tree can also maintain BST ordering.

Therefore:

BST defines the ordering.

Threading defines how NULL pointers are used.

A tree can therefore be:

- Binary Search Tree
- Right-threaded BST
- Left-threaded BST
- Double-threaded BST

---

# 31. Important Difference

Do not confuse these concepts:

Binary Tree:

A node can have at most two children.

Binary Search Tree:

A binary tree with an ordering rule.

Threaded Binary Tree:

A binary tree where NULL pointers are used as threads.

Therefore, threading is mainly related to pointer usage and traversal.

---

# 32. Example of Complete Double-Threaded Tree

Consider:

              50
             /  \
           30    70
          /  \
        20    40

Inorder:

20 30 40 50 70

Threads:

Node 20:

leftThread = 1
left = NULL

rightThread = 1
right = 30


Node 30:

leftThread = 0
left = 20

rightThread = 0
right = 40


Node 40:

leftThread = 1
left = 30

rightThread = 1
right = 50


Node 50:

leftThread = 0
left = 30

rightThread = 0
right = 70


Node 70:

leftThread = 1
left = 50

rightThread = 1
right = NULL

---

# 33. Applications

Threaded binary trees can be useful in:

1. Tree traversal systems

2. Memory-efficient traversal

3. Compiler-related tree structures

4. Expression tree processing

5. Symbol table implementations

6. Ordered data structures

7. Systems where repeated inorder traversal is required

8. Educational implementations of tree traversal

---

# 34. Exam Important Points

Remember these points:

### Point 1

A threaded binary tree replaces NULL pointers with useful threads.

### Point 2

A left thread points to the inorder predecessor.

### Point 3

A right thread points to the inorder successor.

### Point 4

A double-threaded tree uses both left and right threads.

### Point 5

Thread flags identify whether a pointer is a child or a thread.

### Point 6

Inorder traversal can be performed without recursion and without an explicit stack.

### Point 7

Threading does not necessarily change the BST ordering.

### Point 8

Insertion must maintain both the tree structure and the thread relationships.

### Point 9

Search must never follow a thread as if it were a real child.

### Point 10

A threaded tree uses otherwise unused NULL pointers.

---

# 35. Short Definitions for Viva

### What is a threaded binary tree?

A threaded binary tree is a binary tree in which NULL pointers are replaced by threads pointing to useful nodes such as inorder predecessors or successors.

### What is a left-threaded binary tree?

A tree in which NULL left pointers are used as threads to inorder predecessors.

### What is a right-threaded binary tree?

A tree in which NULL right pointers are used as threads to inorder successors.

### What is a double-threaded binary tree?

A tree in which both NULL left and NULL right pointers are used as threads.

### What is an inorder predecessor?

The node that appears immediately before a given node in inorder traversal.

### What is an inorder successor?

The node that appears immediately after a given node in inorder traversal.

### Why are thread flags required?

Thread flags are required to distinguish between an actual child pointer and a thread pointer.

### What is the main advantage?

Inorder traversal can be performed without recursion or an explicit stack.

---

# 36. Overall Concept

The complete concept can be remembered as:

Normal Binary Tree
        |
        v
NULL pointers
        |
        v
Replace useful NULL pointers
        |
        v
Threaded Binary Tree
        |
        +------------------+
        |                  |
        v                  v
Left Thread           Right Thread
        |                  |
        v                  v
Predecessor            Successor
        |
        v
Double Threaded
        |
        +------------------+
        |                  |
        v                  v
Predecessor            Successor

The main idea is simple:

Use unused NULL pointers to store useful traversal information.

---

# 37. Summary

A Threaded Binary Tree is a binary tree that uses NULL pointers as threads.

There are three main types:

1. Left-Threaded Binary Tree
2. Right-Threaded Binary Tree
3. Double-Threaded Binary Tree

Left threads point to inorder predecessors.

Right threads point to inorder successors.

Double-threaded trees use both.

Thread flags are required to distinguish threads from actual child pointers.

The major advantage is efficient inorder traversal without recursion and without an explicit stack.

However, insertion and deletion become more complicated because thread relationships must be maintained.

---

# 38. Conclusion

Threaded Binary Trees provide an efficient way to use NULL pointers in binary trees.

Instead of leaving NULL pointers unused, they can store links to inorder predecessors or successors.

This makes traversal easier and reduces the need for recursion or additional stack memory.

The most important concept to remember is:

LEFT THREAD  -> INORDER PREDECESSOR

RIGHT THREAD -> INORDER SUCCESSOR

DOUBLE THREAD -> BOTH PREDECESSOR AND SUCCESSOR

Therefore, threaded binary trees are especially useful when efficient and repeated tree traversal is required.