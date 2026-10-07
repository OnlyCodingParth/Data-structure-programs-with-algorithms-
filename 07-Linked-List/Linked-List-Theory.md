# Linked List - Theory

## 1. What is a Linked List?

A **Linked List** is a linear data structure in which elements are stored in separate memory locations called **nodes**.

Unlike an array, linked-list nodes do not need to be stored in contiguous memory locations.

Each node contains:

1. Data
2. Pointer to another node

Basic structure:

```text
+--------+--------+
|  Data  |  Next  |
+--------+--------+
```

---

# 2. Node Structure

A basic singly linked-list node in C:

```c
struct Node
{
    int data;
    struct Node *next;
};
```

Here:

* `data` stores the value.
* `next` stores the address of the next node.

Example:

```text
+------+------+
|  10  |  *---|---->
+------+------+
```

---

# 3. Types of Linked Lists

There are four major types:

```text
Linked List
│
├── 1. Singly Linked List
│
├── 2. Doubly Linked List
│
├── 3. Circular Singly Linked List
│
└── 4. Circular Doubly Linked List
```

---

# 4. Singly Linked List

A **Singly Linked List** contains nodes with:

* Data
* Next pointer

Structure:

```text
+------+------+
| Data | Next |
+------+------+
```

Example:

```text
10 -> 20 -> 30 -> NULL
```

The last node points to `NULL`.

### Node Structure

```c
struct Node
{
    int data;
    struct Node *next;
};
```

### Characteristics

* Traversal is possible only in the forward direction.
* Each node has one pointer.
* The last node points to `NULL`.
* Memory is dynamically allocated.

### Operations

* Creation
* Traversal
* Searching
* Insertion at beginning
* Insertion at end
* Insertion at position
* Deletion from beginning
* Deletion from end
* Deletion from position
* Updation
* Reversal

---

# 5. Doubly Linked List

A **Doubly Linked List** contains three parts:

```text
+--------+--------+--------+
|  Prev  |  Data  |  Next  |
+--------+--------+--------+
```

Each node has:

* Pointer to previous node
* Data
* Pointer to next node

Example:

```text
NULL <- 10 <-> 20 <-> 30 -> NULL
```

### Node Structure

```c
struct Node
{
    struct Node *prev;
    int data;
    struct Node *next;
};
```

### Characteristics

* Traversal is possible in both directions.
* Each node has two pointers.
* The first node's `prev` is `NULL`.
* The last node's `next` is `NULL`.
* Requires more memory than a singly linked list.

### Operations

* Creation
* Forward traversal
* Backward traversal
* Searching
* Insertion at beginning
* Insertion at end
* Insertion at position
* Deletion from beginning
* Deletion from end
* Deletion from position
* Updation
* Reversal

---

# 6. Circular Singly Linked List

A **Circular Singly Linked List** is similar to a singly linked list, but the last node points back to the first node.

Example:

```text
10 -> 20 -> 30
^           |
|___________|
```

There is no `NULL` at the end.

The important connection is:

```c
last->next = head;
```

### Node Structure

```c
struct Node
{
    int data;
    struct Node *next;
};
```

### Traversal

A `do-while` loop is commonly used:

```c
temp = head;

do
{
    printf("%d ", temp->data);
    temp = temp->next;
}
while (temp != head);
```

The traversal stops when `temp` reaches `head` again.

### Characteristics

* Last node points to the first node.
* No `NULL` at the end.
* Forward traversal is possible.
* Useful for cyclic or repeating processes.

---

# 7. Circular Doubly Linked List

A **Circular Doubly Linked List** combines the properties of a doubly linked list and a circular linked list.

Each node contains:

```text
+--------+--------+--------+
|  Prev  |  Data  |  Next  |
+--------+--------+--------+
```

Example:

```text
        ┌───────────────────┐
        ↓                   │
10 <-> 20 <-> 30            │
^                           │
└───────────────────────────┘
```

The important connections are:

```c
head->prev = last;
last->next = head;
```

There is no `NULL` at either end.

### Node Structure

```c
struct Node
{
    struct Node *prev;
    int data;
    struct Node *next;
};
```

### Characteristics

* Forward traversal is possible.
* Backward traversal is possible.
* Last node points to head.
* Head's `prev` points to the last node.
* No `NULL` at either end.

---

# 8. Comparison of Linked Lists

| Feature              | Singly | Doubly | Circular Singly | Circular Doubly |
| -------------------- | ------ | ------ | --------------- | --------------- |
| `prev` pointer       | No     | Yes    | No              | Yes             |
| `next` pointer       | Yes    | Yes    | Yes             | Yes             |
| Forward traversal    | Yes    | Yes    | Yes             | Yes             |
| Backward traversal   | No     | Yes    | No              | Yes             |
| Last points to first | No     | No     | Yes             | Yes             |
| `NULL` at end        | Yes    | Yes    | No              | No              |
| Memory usage         | Low    | Higher | Low             | Highest         |

---

# 9. Linked List Operations

## 9.1 Creation

Creation means creating nodes dynamically and connecting them.

Example:

```text
10 -> 20 -> 30 -> NULL
```

In C, memory can be allocated using:

```c
malloc()
```

Example:

```c
struct Node *newNode;

newNode = (struct Node *)malloc(sizeof(struct Node));
```

---

# 10. Traversal

Traversal means visiting every node of the linked list.

### Singly / Doubly Linked List

Continue until `NULL`.

```c
while (temp != NULL)
{
    printf("%d ", temp->data);
    temp = temp->next;
}
```

### Circular Linked List

Continue until `temp` reaches `head` again.

```c
do
{
    printf("%d ", temp->data);
    temp = temp->next;
}
while (temp != head);
```

Time Complexity:

```text
O(n)
```

---

# 11. Searching

Searching means finding a particular value in the linked list.

Example:

```text
10 -> 20 -> 30 -> 40
```

Search for `30`.

The list is checked node by node:

```text
10 -> 20 -> 30
             ↑
           Found
```

Time Complexity:

```text
Best Case: O(1)
Worst Case: O(n)
```

---

# 12. Insertion

Insertion means adding a new node to the linked list.

Common insertion operations:

1. Insertion at beginning
2. Insertion at end
3. Insertion at a specific position

---

## 12.1 Insertion at Beginning

Example:

```text
Before:

10 -> 20 -> 30

Insert 5

After:

5 -> 10 -> 20 -> 30
```

For a singly linked list:

```c
newNode->next = head;
head = newNode;
```

Time Complexity:

```text
O(1)
```

---

## 12.2 Insertion at End

Example:

```text
10 -> 20 -> 30

Insert 40

10 -> 20 -> 30 -> 40
```

Without a tail pointer, traversal is required.

Time Complexity:

```text
O(n)
```

With a tail pointer:

```text
O(1)
```

---

## 12.3 Insertion at Position

Example:

```text
10 -> 20 -> 30

Insert 25 at position 3

10 -> 20 -> 25 -> 30
```

The node before the required position is located and the new node is connected.

Typical time complexity:

```text
O(n)
```

---

# 13. Deletion

Deletion means removing a node from the linked list.

Common deletion operations:

1. Deletion from beginning
2. Deletion from end
3. Deletion from a specific position

---

## 13.1 Deletion from Beginning

Example:

```text
Before:

10 -> 20 -> 30

Delete first node.

After:

20 -> 30
```

For a singly linked list:

```c
temp = head;
head = head->next;
free(temp);
```

Time Complexity:

```text
O(1)
```

---

## 13.2 Deletion from End

Example:

```text
10 -> 20 -> 30

Delete last node.

10 -> 20
```

The node before the last node is located and its `next` pointer is changed.

Time Complexity without a tail/previous pointer:

```text
O(n)
```

---

## 13.3 Deletion from Position

Example:

```text
10 -> 20 -> 30 -> 40

Delete position 3.

10 -> 20 -> 40
```

The target node is located and removed.

Time Complexity:

```text
O(n)
```

---

# 14. Updation

Updation means changing the data stored in a node.

Example:

```text
Before:

10 -> 20 -> 30

Update 20 to 50.

After:

10 -> 50 -> 30
```

Only the `data` value is changed.

The links remain unchanged.

Time Complexity:

```text
O(n)
```

---

# 15. Reversal

Reversal means changing the order of nodes.

Example:

```text
Before:

10 -> 20 -> 30 -> NULL

After:

30 -> 20 -> 10 -> NULL
```

For a singly linked list, three pointers are commonly used:

```text
prev
current
next
```

Basic idea:

```c
next = current->next;
current->next = prev;
prev = current;
current = next;
```

Time Complexity:

```text
O(n)
```

Space Complexity:

```text
O(1)
```

---

# 16. Memory Allocation

Linked lists generally use dynamic memory allocation.

In C:

```c
malloc()
```

is used to allocate memory.

Example:

```c
newNode = (struct Node *)malloc(sizeof(struct Node));
```

When a node is deleted, its memory should be released:

```c
free(temp);
```

Failing to free dynamically allocated memory can cause a **memory leak**.

---

# 17. Advantages of Linked Lists

1. Dynamic size.
2. Efficient insertion and deletion at known positions.
3. Does not require contiguous memory.
4. Memory is allocated when required.
5. Useful for implementing stacks and queues.
6. Can be modified easily during program execution.

---

# 18. Disadvantages of Linked Lists

1. Extra memory is required for pointers.
2. Random access is not available.
3. Searching is generally O(n).
4. Pointer manipulation can be difficult.
5. More complex than arrays.
6. Dynamic memory management is required.

---

# 19. Array vs Linked List

| Feature                | Array                     | Linked List    |
| ---------------------- | ------------------------- | -------------- |
| Memory                 | Usually contiguous        | Non-contiguous |
| Size                   | Usually fixed             | Dynamic        |
| Random access          | Yes                       | No             |
| Access by index        | O(1)                      | O(n)           |
| Insertion at beginning | O(n)                      | O(1)           |
| Deletion at beginning  | O(n)                      | O(1)           |
| Extra pointer memory   | No                        | Yes            |
| Memory allocation      | Usually static/fixed-size | Dynamic        |

---

# 20. Time Complexity Summary

| Operation        | Singly | Doubly | Circular Singly | Circular Doubly |
| ---------------- | -----: | -----: | --------------: | --------------: |
| Traversal        |   O(n) |   O(n) |            O(n) |            O(n) |
| Searching        |   O(n) |   O(n) |            O(n) |            O(n) |
| Insert Beginning |   O(1) |   O(1) |            O(1) |            O(1) |
| Insert End*      |   O(n) |   O(n) |            O(n) |            O(1) |
| Insert Position  |   O(n) |   O(n) |            O(n) |            O(n) |
| Delete Beginning |   O(1) |   O(1) |            O(1) |            O(1) |
| Delete End*      |   O(n) |   O(n) |            O(n) |            O(1) |
| Delete Position  |   O(n) |   O(n) |            O(n) |            O(n) |
| Updation         |   O(n) |   O(n) |            O(n) |            O(n) |
| Reversal         |   O(n) |   O(n) |            O(n) |            O(n) |

`*` Complexity depends on whether an appropriate tail pointer is maintained.

---

# 21. Important Pointer Concepts

## Singly Linked List

```text
last->next = NULL;
```

## Doubly Linked List

```text
head->prev = NULL;
last->next = NULL;
```

## Circular Singly Linked List

```text
last->next = head;
```

## Circular Doubly Linked List

```text
head->prev = last;
last->next = head;
```

These connections are the key differences between the four types.

---

# 22. Applications

Linked lists are used in:

* Stack implementation
* Queue implementation
* Graph adjacency lists
* Hash table chaining
* Music playlists
* Browser history
* Undo/redo systems
* Memory management
* Polynomial representation
* Sparse matrix representation
* Operating-system scheduling

---

# 23. Important Exam Points

* A linked list is a dynamic linear data structure.
* Nodes are generally created using dynamic memory allocation.
* A singly linked list has one pointer.
* A doubly linked list has two pointers.
* Circular linked lists do not have `NULL` at the end.
* Doubly linked lists support forward and backward traversal.
* Linked lists do not provide direct/random access like arrays.
* Insertion and deletion can be efficient when the required node/location is already known.
* `malloc()` allocates dynamic memory.
* `free()` releases dynamically allocated memory.
* Incorrect pointer manipulation can cause memory leaks or broken lists.

---

# 24. Overall Concept

The four major linked-list types can be remembered like this:

```text
Singly
10 -> 20 -> 30 -> NULL


Doubly
NULL <- 10 <-> 20 <-> 30 -> NULL


Circular Singly
      ┌─────────────────┐
      ↓                 │
10 -> 20 -> 30 ─────────┘


Circular Doubly
      ┌─────────────────────┐
      ↓                     │
10 <-> 20 <-> 30            │
↑                           │
└───────────────────────────┘
```

The fundamental difference is based on two questions:

1. Does the node have a `prev` pointer?
2. Does the last node connect back to the first node?

```text
                  prev?
                 /     \
                No      Yes
                |        |
             Singly    Doubly
                |        |
             Circular? Circular?
             /     \     /     \
            No     Yes   No     Yes
            |       |     |       |
         Singly  Circular Doubly Circular
                 Singly          Doubly
```

---

# Conclusion

A linked list is an important dynamic data structure that provides flexible memory usage and efficient insertion and deletion.

The four major types are:

1. **Singly Linked List**
2. **Doubly Linked List**
3. **Circular Singly Linked List**
4. **Circular Doubly Linked List**

Understanding these four types provides the foundation for more advanced data structures such as:

* Stacks
* Queues
* Hash tables
* Graphs
* Trees

The most important skill is not memorizing code, but understanding how the **pointers change when nodes are inserted, deleted, updated, or reversed**.
