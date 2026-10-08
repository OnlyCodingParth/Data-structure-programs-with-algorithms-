# AVL Tree

## 1. Introduction

An AVL Tree is a **self-balancing Binary Search Tree (BST)**.

The name AVL comes from the names of its inventors:

- Adelson-Velsky
- Landis

In a normal Binary Search Tree, the tree can become skewed if values are inserted in sorted order.

Example:

    10
      \
       20
         \
          30
            \
             40

In this case, the BST behaves almost like a linked list.

An AVL Tree automatically keeps the tree balanced after insertion and deletion.

---

## 2. Definition of AVL Tree

An AVL Tree is a Binary Search Tree in which the difference between the heights of the left and right subtrees of every node is at most 1.

This difference is called the **Balance Factor**.

### Balance Factor

    Balance Factor =
    Height of Left Subtree - Height of Right Subtree

For every node in an AVL Tree, the balance factor must be:

    -1
     0
    +1

If the balance factor becomes:

    +2 or -2

the tree becomes unbalanced and rotation is required.

---

## 3. AVL Tree Node Structure

An AVL Tree node normally contains:

1. Data
2. Height
3. Pointer to left child
4. Pointer to right child

Example:

    struct Node
    {
        int data;
        int height;
        struct Node *left;
        struct Node *right;
    };

The `height` field is important because AVL trees need height information to calculate the balance factor.

---

## 4. Important Terms

### Node

An individual element of the AVL Tree.

### Root

The topmost node of the tree.

### Parent

A node that has one or more child nodes.

### Child

A node connected below another node.

### Leaf Node

A node that has no children.

### Height

The height of a node represents the longest path from that node to a leaf.

In our programs:

    Height of NULL = 0
    Height of leaf node = 1

---

## 5. Balance Factor

The balance factor is calculated as:

    Balance Factor =
    Height(Left Subtree) - Height(Right Subtree)

There are three valid balance factors:

    +1
     0
    -1

### Balance Factor +1

The left subtree is one level taller.

### Balance Factor 0

Both subtrees have equal height.

### Balance Factor -1

The right subtree is one level taller.

If the balance factor becomes +2 or -2, the node is unbalanced.

---

## 6. Why AVL Tree Is Needed

A normal BST can become unbalanced.

Example:

    10
      \
       20
         \
          30
            \
             40
               \
                50

Searching in this tree may require visiting many nodes.

An AVL Tree prevents this problem by automatically balancing itself.

Therefore, AVL Trees maintain approximately logarithmic height.

---

## 7. AVL Tree Property

An AVL Tree follows two important rules:

### Rule 1 - BST Property

For every node:

    Left subtree < Root < Right subtree

### Rule 2 - Balance Property

For every node:

    -1 <= Balance Factor <= +1

Both conditions must be satisfied.

---

# 8. AVL Tree Insertion

Insertion in an AVL Tree is similar to insertion in a Binary Search Tree.

After insertion, the heights are updated and the balance factor is checked.

If the tree becomes unbalanced, an appropriate rotation is performed.

### Steps

1. Start from the root.
2. Compare the new value with the current node.
3. Move left if the value is smaller.
4. Move right if the value is larger.
5. Insert the new node.
6. Update the height of affected nodes.
7. Calculate the balance factor.
8. Check for imbalance.
9. Perform the required rotation.
10. Return the new root.

---

# 9. Four Types of AVL Rotations

There are four possible imbalance cases:

1. LL Rotation
2. RR Rotation
3. LR Rotation
4. RL Rotation

These rotations restore the balance of the AVL Tree.

---

# 10. LL Rotation

LL stands for:

    Left - Left

It occurs when a node is inserted into the left subtree of the left child.

Example:

        30
       /
      20
     /
    10

The balance factor of 30 becomes +2.

This is an LL imbalance.

### Solution

Perform a **Right Rotation**.

After rotation:

        20
       /  \
      10   30

### Important Point

    LL Case -> Right Rotation

---

# 11. RR Rotation

RR stands for:

    Right - Right

It occurs when a node is inserted into the right subtree of the right child.

Example:

    10
      \
       20
         \
          30

The balance factor of 10 becomes -2.

This is an RR imbalance.

### Solution

Perform a **Left Rotation**.

After rotation:

        20
       /  \
      10   30

### Important Point

    RR Case -> Left Rotation

---

# 12. LR Rotation

LR stands for:

    Left - Right

It occurs when a node is inserted into the right subtree of the left child.

Example:

        30
       /
      10
        \
         20

This is an LR imbalance.

Two rotations are required.

### Step 1

Perform a Left Rotation on the left child.

### Step 2

Perform a Right Rotation on the unbalanced node.

Final tree:

        20
       /  \
      10   30

### Important Point

    LR Case ->
    Left Rotation
    +
    Right Rotation

---

# 13. RL Rotation

RL stands for:

    Right - Left

It occurs when a node is inserted into the left subtree of the right child.

Example:

    10
      \
       30
      /
     20

This is an RL imbalance.

Two rotations are required.

### Step 1

Perform a Right Rotation on the right child.

### Step 2

Perform a Left Rotation on the unbalanced node.

Final tree:

        20
       /  \
      10   30

### Important Point

    RL Case ->
    Right Rotation
    +
    Left Rotation

---

# 14. Rotation Summary

| Case | Imbalance | Rotation |
|------|-----------|----------|
| LL | Left of Left | Right Rotation |
| RR | Right of Right | Left Rotation |
| LR | Right of Left | Left Rotation + Right Rotation |
| RL | Left of Right | Right Rotation + Left Rotation |

This table is very important for exams and viva.

---

# 15. Right Rotation

Right Rotation is mainly used for the LL case.

Before rotation:

        y
       /
      x
       \
        T2

After rotation:

        x
         \
          y

The general operation is:

    x = y->left
    T2 = x->right

    x->right = y
    y->left = T2

The heights are then updated.

### Time Complexity

    O(1)

---

# 16. Left Rotation

Left Rotation is mainly used for the RR case.

Before rotation:

    x
     \
      y
     /
    T2

After rotation:

        y
       /
      x

The general operation is:

    y = x->right
    T2 = y->left

    y->left = x
    x->right = T2

The heights are then updated.

### Time Complexity

    O(1)

---

# 17. AVL Tree Deletion

Deletion in an AVL Tree is similar to deletion in a Binary Search Tree.

There are three normal BST deletion cases.

### Case 1 - Node with No Child

The node is simply removed.

Example:

    20
   /
  10

Delete 10:

    20

---

### Case 2 - Node with One Child

The node is replaced by its child.

Example:

    20
      \
       30
         \
          40

If 30 is deleted, 40 takes its position.

---

### Case 3 - Node with Two Children

When a node has two children, we can replace its value with its inorder successor.

The inorder successor is the smallest value in the right subtree.

Example:

        50
       /  \
      30   70
          /
         60

If 50 is deleted, 60 can replace it.

After deletion, the AVL tree must be checked for imbalance.

---

# 18. Steps for AVL Deletion

1. Search for the node.
2. Delete the node using BST deletion.
3. Update the height.
4. Calculate the balance factor.
5. Check whether the node is balanced.
6. If unbalanced, determine the rotation case.
7. Perform the required rotation.
8. Continue checking toward the root.
9. Return the balanced tree.

---

# 19. Balance Cases During Deletion

After deletion, the following cases can occur:

### LL Case

    Balance > 1
    and left subtree is balanced toward left

Solution:

    Right Rotation

### LR Case

    Balance > 1
    and left subtree is balanced toward right

Solution:

    Left Rotation
    followed by
    Right Rotation

### RR Case

    Balance < -1
    and right subtree is balanced toward right

Solution:

    Left Rotation

### RL Case

    Balance < -1
    and right subtree is balanced toward left

Solution:

    Right Rotation
    followed by
    Left Rotation

---

# 20. AVL Tree Searching

Searching in an AVL Tree follows the same rules as a Binary Search Tree.

If the required value is smaller than the current node:

    Move to the left subtree.

If the required value is larger than the current node:

    Move to the right subtree.

If the value is equal:

    Element is found.

Because an AVL Tree remains balanced, searching takes:

    O(log n)

in the average and worst case for a properly maintained AVL tree.

---

# 21. AVL Tree Traversals

AVL Trees can be traversed using the same traversal methods as Binary Trees.

## Inorder Traversal

Order:

    Left -> Root -> Right

For a BST or AVL Tree, inorder traversal produces values in sorted order.

Example:

        30
       /  \
      20   40

Inorder:

    20 30 40

---

## Preorder Traversal

Order:

    Root -> Left -> Right

Example:

        30
       /  \
      20   40

Preorder:

    30 20 40

---

## Postorder Traversal

Order:

    Left -> Right -> Root

Example:

        30
       /  \
      20   40

Postorder:

    20 40 30

---

## Level Order Traversal

Level order visits nodes level by level.

Example:

        30
       /  \
      20   40

Level order:

    30 20 40

Level order traversal normally uses a queue.

---

# 22. Example of AVL Tree

Consider inserting:

    30
    20
    10

After inserting 30:

        30

After inserting 20:

        30
       /
      20

After inserting 10:

        30
       /
      20
     /
    10

This creates an LL imbalance.

Perform Right Rotation.

Final AVL Tree:

        20
       /  \
      10   30

The tree is balanced again.

---

# 23. Another Example

Consider inserting:

    10
    20
    30

The tree becomes:

    10
      \
       20
         \
          30

This creates an RR imbalance.

Perform Left Rotation.

Final tree:

        20
       /  \
      10   30

---

# 24. Height of AVL Tree

The height of an AVL Tree is O(log n).

This is one of the most important advantages of AVL Trees.

Because the tree remains balanced, operations do not normally degrade to O(n).

---

# 25. Time Complexity

| Operation | Time Complexity |
|-----------|-----------------|
| Search | O(log n) |
| Insertion | O(log n) |
| Deletion | O(log n) |
| LL Rotation | O(1) |
| RR Rotation | O(1) |
| LR Rotation | O(1) |
| RL Rotation | O(1) |
| Inorder Traversal | O(n) |
| Preorder Traversal | O(n) |
| Postorder Traversal | O(n) |
| Level Order Traversal | O(n) |

---

# 26. Space Complexity

The AVL Tree requires:

    O(n)

space to store n nodes.

For recursive operations such as insertion and deletion, the recursion stack requires:

    O(log n)

auxiliary space because the height of the AVL Tree is O(log n).

Individual rotations use:

    O(1)

extra space.

---

# 27. Advantages of AVL Tree

1. It is always balanced.
2. Searching is efficient.
3. Insertion is efficient.
4. Deletion is efficient.
5. Worst-case search is O(log n).
6. It prevents the BST from becoming highly skewed.
7. It is useful when searching is performed frequently.
8. It provides predictable performance.

---

# 28. Disadvantages of AVL Tree

1. Implementation is more complex than a normal BST.
2. Rotations are required after insertion or deletion.
3. Extra height information must be stored.
4. Maintaining balance requires additional operations.
5. Code is more complicated than an ordinary Binary Search Tree.

---

# 29. AVL Tree vs Binary Search Tree

| Feature | BST | AVL Tree |
|---------|-----|----------|
| Self-balancing | No | Yes |
| Balance Factor | Not required | Required |
| Search | O(log n) average, O(n) worst | O(log n) worst |
| Insertion | O(log n) average, O(n) worst | O(log n) |
| Deletion | O(log n) average, O(n) worst | O(log n) |
| Rotations | Not normally required | Required |
| Implementation | Simpler | More complex |
| Height | Can become O(n) | O(log n) |

---

# 30. AVL Tree vs Normal BST Example

### Normal BST

If values are inserted as:

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

Height becomes large.

### AVL Tree

The AVL Tree automatically performs rotations to keep the tree balanced.

Therefore, its height remains logarithmic.

---

# 31. Applications of AVL Trees

AVL Trees can be used in:

1. Searching systems
2. Database indexing
3. Memory management
4. Symbol tables
5. Dictionary implementations
6. File systems
7. Computer networks
8. Information retrieval systems
9. Applications requiring fast searching
10. Ordered data storage

---

# 32. Important Exam Points

1. AVL Tree is a self-balancing BST.
2. AVL was introduced by Adelson-Velsky and Landis.
3. Balance Factor = Height of Left Subtree - Height of Right Subtree.
4. Valid balance factors are -1, 0 and +1.
5. Balance factor +2 or -2 indicates imbalance.
6. LL case requires Right Rotation.
7. RR case requires Left Rotation.
8. LR case requires Left Rotation followed by Right Rotation.
9. RL case requires Right Rotation followed by Left Rotation.
10. AVL search takes O(log n).
11. AVL insertion takes O(log n).
12. AVL deletion takes O(log n).
13. A rotation takes O(1) time.
14. Inorder traversal of an AVL Tree gives sorted order.
15. AVL Tree is more balanced than an ordinary BST.
16. AVL Tree requires extra height information.
17. AVL Tree has O(log n) height.
18. AVL Tree is useful when fast searching is important.

---

# 33. Quick Rotation Trick

Remember:

    LL -> Right
    RR -> Left
    LR -> Left + Right
    RL -> Right + Left

Another easy way to remember:

    Outside cases -> Single Rotation
    Inside cases  -> Double Rotation

Outside cases:

    LL
    RR

Inside cases:

    LR
    RL

---

# 34. Overall AVL Tree Working

The complete working of an AVL Tree can be summarized as:

    Insert/Delete
         |
         v
    Update Height
         |
         v
    Calculate Balance Factor
         |
         v
    Is Tree Balanced?
       /       \
     Yes        No
      |          |
      |       Find Case
      |          |
      |     LL/RR/LR/RL
      |          |
      |       Rotation
      |          |
      +----------+
             |
             v
       Balanced AVL Tree

---

# 35. Complete AVL Tree Concept

An AVL Tree combines the advantages of a Binary Search Tree with automatic balancing.

It maintains the BST property:

    Left < Root < Right

and also maintains the balance condition:

    -1 <= Balance Factor <= +1

Whenever an insertion or deletion causes imbalance, the tree performs one or more rotations.

The four possible rotations are:

    LL -> Right Rotation

    RR -> Left Rotation

    LR -> Left Rotation + Right Rotation

    RL -> Right Rotation + Left Rotation

Because the AVL Tree remains balanced, searching, insertion and deletion can be performed efficiently in O(log n) time.

---

# 36. Conclusion

An AVL Tree is an important self-balancing Binary Search Tree.

Its main purpose is to prevent a BST from becoming skewed.

The most important concepts are:

- Balance Factor
- Height
- AVL Insertion
- AVL Deletion
- LL Rotation
- RR Rotation
- LR Rotation
- RL Rotation

The key rule to remember is:

    LL -> Right Rotation
    RR -> Left Rotation
    LR -> Left + Right Rotation
    RL -> Right + Left Rotation

AVL Trees are especially useful when efficient and predictable searching, insertion and deletion are required.