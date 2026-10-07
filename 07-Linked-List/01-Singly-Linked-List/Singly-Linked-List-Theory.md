# Singly Linked List

## 1. Definition

A **Singly Linked List** is a linear data structure in which elements are stored in separate nodes.

Each node contains two parts:

1. **Data** – stores the value.
2. **Next** – stores the address of the next node.

The last node points to `NULL`.

### Basic Structure

```text
Head
 ↓
[Data | Next] → [Data | Next] → [Data | NULL]
```

Example:

```text
10 → 20 → 30 → NULL
```

---

## 2. Node Structure in C

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
* `struct Node *next` is a pointer to another node.

---

## 3. Important Terms

### Head

`head` is a pointer that stores the address of the first node.

```c
struct Node *head = NULL;
```

If the list is empty:

```text
head → NULL
```

### Node

A node contains data and a pointer to the next node.

### NULL

The last node contains `NULL` in its `next` pointer.

```text
10 → 20 → 30 → NULL
```

---

## 4. Working of Singly Linked List

Nodes are connected using pointers.

For example:

```text
10 → 20 → 30 → NULL
```

The first node points to the second node, the second node points to the third node, and the last node points to `NULL`.

To move through the list, we use a temporary pointer:

```c
temp = head;

while (temp != NULL)
{
    printf("%d ", temp->data);
    temp = temp->next;
}
```

---

## 5. Creation of Singly Linked List

Steps:

1. Create a new node using `malloc()`.
2. Store data in the node.
3. Set `next` to `NULL`.
4. If the list is empty, make the new node the `head`.
5. Otherwise, connect the new node to the last node.

Example:

```text
10 → 20 → 30 → NULL
```

---

# 6. Operations on Singly Linked List

The main operations are:

1. Creation
2. Traversal
3. Searching
4. Insertion
5. Deletion
6. Updation
7. Reversal

---

## 7. Traversal

Traversal means visiting each node of the linked list one by one.

### Algorithm

1. Start from `head`.
2. Store `head` in a temporary pointer.
3. Visit the current node.
4. Move to the next node.
5. Repeat until the pointer becomes `NULL`.

### Important Logic

```c
temp = head;

while (temp != NULL)
{
    printf("%d ", temp->data);
    temp = temp->next;
}
```

### Complexity

* Time: **O(n)**
* Space: **O(1)**

---

## 8. Searching

Searching means finding a particular value in the linked list.

### Algorithm

1. Start from `head`.
2. Compare the node data with the required value.
3. If equal, the value is found.
4. Otherwise, move to the next node.
5. Continue until the value is found or `NULL` is reached.

### Complexity

* Best Case: **O(1)**
* Average Case: **O(n)**
* Worst Case: **O(n)**
* Space: **O(1)**

---

# 9. Insertion

Insertion means adding a new node to the linked list.

Types of insertion:

1. Insertion at beginning
2. Insertion at end
3. Insertion at a specific position

---

## 9.1 Insertion at Beginning

A new node is added before the current first node.

### Important Logic

```c
newNode->next = head;
head = newNode;
```

Example:

```text
Before:
10 → 20 → 30 → NULL

Insert 5

After:
5 → 10 → 20 → 30 → NULL
```

### Complexity

* Time: **O(1)**
* Space: **O(1)** auxiliary space

---

## 9.2 Insertion at End

A new node is added after the last node.

### Important Logic

```c
while (temp->next != NULL)
{
    temp = temp->next;
}

temp->next = newNode;
```

Example:

```text
Before:
10 → 20 → 30 → NULL

Insert 40

After:
10 → 20 → 30 → 40 → NULL
```

### Complexity

* Time: **O(n)**
* Space: **O(1)** auxiliary space

> If a tail pointer is maintained, insertion at the end can be performed in **O(1)** time.

---

## 9.3 Insertion at Position

A new node is inserted at a specific position.

Example:

```text
Before:
10 → 20 → 30 → 40 → NULL

Insert 25 at position 3

After:
10 → 20 → 25 → 30 → 40 → NULL
```

### Important Logic

```c
newNode->next = temp->next;
temp->next = newNode;
```

### Complexity

* Best Case: **O(1)** for position 1
* Worst Case: **O(n)**
* Space: **O(1)** auxiliary space

---

# 10. Deletion

Deletion means removing a node from the linked list.

Types of deletion:

1. Deletion from beginning
2. Deletion from end
3. Deletion from a specific position

---

## 10.1 Deletion from Beginning

The first node is removed.

### Important Logic

```c
temp = head;
head = head->next;
free(temp);
```

Example:

```text
Before:
10 → 20 → 30 → NULL

After:
20 → 30 → NULL
```

### Complexity

* Time: **O(1)**
* Space: **O(1)**

---

## 10.2 Deletion from End

The last node is removed.

In a singly linked list, we normally need to reach the last node and keep track of the previous node.

### Important Logic

```c
while (temp->next != NULL)
{
    prev = temp;
    temp = temp->next;
}

prev->next = NULL;
free(temp);
```

### Complexity

* Time: **O(n)**
* Space: **O(1)**

---

## 10.3 Deletion from Position

A node at a specific position is removed.

Example:

```text
Before:
10 → 20 → 30 → 40 → NULL

Delete position 3

After:
10 → 20 → 40 → NULL
```

### Important Logic

```c
prev = temp->next;
temp->next = prev->next;
free(prev);
```

### Complexity

* Best Case: **O(1)** for position 1
* Worst Case: **O(n)**
* Space: **O(1)**

---

# 11. Updation

Updation means changing the data value of a node.

Example:

```text
Before:
10 → 20 → 30 → 40 → NULL

Update position 3 to 99

After:
10 → 20 → 99 → 40 → NULL
```

### Important Logic

```c
temp->data = newValue;
```

The links are not changed.

### Complexity

* Best Case: **O(1)**
* Worst Case: **O(n)**
* Space: **O(1)**

---

# 12. Reversal

Reversal means changing the direction of all links in the linked list.

Example:

```text
Before:
10 → 20 → 30 → 40 → NULL

After:
40 → 30 → 20 → 10 → NULL
```

Three pointers are commonly used:

* `prev`
* `current`
* `next`

### Important Logic

```c
next = current->next;
current->next = prev;
prev = current;
current = next;
```

Finally:

```c
head = prev;
```

### Complexity

* Time: **O(n)**
* Space: **O(1)**

---

# 13. Advantages of Singly Linked List

1. Dynamic size.
2. Memory is allocated when required.
3. Insertion and deletion at the beginning are fast.
4. Does not require contiguous memory.
5. Memory can be used efficiently according to the required size.

---

# 14. Disadvantages of Singly Linked List

1. No direct/random access to elements.
2. Traversal is only in the forward direction.
3. Extra memory is required for the `next` pointer.
4. Searching takes **O(n)** time in the worst case.
5. Deletion from the end requires traversal because there is no previous pointer.

---

# 15. Applications

Singly linked lists are used in:

* Dynamic memory management
* Implementing stacks
* Implementing queues
* Polynomial representation
* Graph adjacency lists
* Hash table chaining
* Memory management systems

---

# 16. Singly Linked List vs Array

| Feature       | Singly Linked List | Array                  |
| ------------- | ------------------ | ---------------------- |
| Memory        | Non-contiguous     | Contiguous             |
| Size          | Dynamic            | Usually fixed          |
| Random Access | Not available      | Available              |
| Access Time   | O(n)               | O(1)                   |
| Insertion     | Easier             | Requires shifting      |
| Deletion      | Easier             | Requires shifting      |
| Extra Memory  | Pointer required   | No pointer per element |

---

# 17. Singly Linked List vs Doubly Linked List

| Feature            | Singly Linked List | Doubly Linked List   |
| ------------------ | ------------------ | -------------------- |
| Pointers per node  | One                | Two                  |
| Direction          | Forward            | Forward and backward |
| Memory             | Less               | More                 |
| Backward Traversal | Not possible       | Possible             |
| Node Structure     | `data + next`      | `data + prev + next` |

---

# 18. Time Complexity Summary

| Operation               | Time Complexity | Extra Space |
| ----------------------- | --------------: | ----------: |
| Creation*               |           O(n²) |        O(n) |
| Traversal               |            O(n) |        O(1) |
| Searching               |            O(n) |        O(1) |
| Insertion at Beginning  |            O(1) |        O(1) |
| Insertion at End        |            O(n) |        O(1) |
| Insertion at Position   |            O(n) |        O(1) |
| Deletion from Beginning |            O(1) |        O(1) |
| Deletion from End       |            O(n) |        O(1) |
| Deletion from Position  |            O(n) |        O(1) |
| Updation                |            O(n) |        O(1) |
| Reversal                |            O(n) |        O(1) |

*The creation program in this repository traverses to the end for every new node, so its creation time is O(n²). With a maintained tail pointer, creation can be O(n).

---

# 19. Important Exam Points

* A singly linked list consists of nodes.
* Each node contains **data and a next pointer**.
* The first node is accessed using `head`.
* The last node points to `NULL`.
* Nodes do not need contiguous memory.
* Singly linked lists support only forward traversal.
* Insertion and deletion at the beginning take **O(1)** time.
* Searching takes **O(n)** time in the worst case.
* Reversal can be performed using three pointers: `prev`, `current`, and `next`.
* `malloc()` is used to dynamically allocate memory for a node.
* `free()` is used to release memory of a deleted node.

---

# 20. Conclusion

A **Singly Linked List** is a dynamic linear data structure made up of nodes connected using pointers. It provides efficient insertion and deletion at the beginning and flexible memory usage. However, it does not support direct access and allows traversal only in the forward direction.

It is one of the fundamental data structures used to understand more advanced structures such as doubly linked lists, circular linked lists, stacks, queues, and graphs.