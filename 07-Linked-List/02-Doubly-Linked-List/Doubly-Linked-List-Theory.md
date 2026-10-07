# Doubly Linked List - Theory

## 1. Definition

A **Doubly Linked List (DLL)** is a linear dynamic data structure in which each node contains:

1. A pointer to the previous node (`prev`)
2. Data
3. A pointer to the next node (`next`)

### Node Structure

```c
struct Node
{
    struct Node *prev;
    int data;
    struct Node *next;
};
```

The first node has `prev = NULL` and the last node has `next = NULL`.

---

## 2. Representation

A doubly linked list can be represented as:

```text
NULL ← 10 ⇄ 20 ⇄ 30 → NULL
```

Here:

* `prev` points to the previous node.
* `next` points to the next node.
* `head` points to the first node.

---

## 3. Working of Doubly Linked List

Each node is connected in **both directions**.

For example:

```text
10 ⇄ 20 ⇄ 30
```

For node `20`:

```text
20->prev → 10
20->next → 30
```

Therefore, we can traverse the list:

* From beginning to end using `next`
* From end to beginning using `prev`

---

## 4. Creation

Steps:

1. Create a new node using `malloc()`.
2. Store data in the node.
3. Set `prev` and `next`.
4. If the list is empty, make the new node the `head`.
5. Otherwise, move to the last node.
6. Connect the new node using both `next` and `prev`.

Important connection:

```c
temp->next = newNode;
newNode->prev = temp;
```

---

## 5. Traversal

### Forward Traversal

Start from `head` and follow the `next` pointer.

```c
temp = head;

while (temp != NULL)
{
    printf("%d ", temp->data);
    temp = temp->next;
}
```

### Backward Traversal

First move to the last node, then follow the `prev` pointer.

```c
while (temp->next != NULL)
{
    temp = temp->next;
}

while (temp != NULL)
{
    printf("%d ", temp->data);
    temp = temp->prev;
}
```

---

## 6. Searching

Searching means finding a particular value in the linked list.

Steps:

1. Start from `head`.
2. Compare the data of each node with the required value.
3. If found, return its position.
4. Otherwise, continue until `NULL`.

Time Complexity:

* Best: `O(1)`
* Average/Worst: `O(n)`

---

## 7. Insertion

Insertion means adding a new node to the linked list.

### Types of Insertion

1. Insertion at Beginning
2. Insertion at End
3. Insertion at Position

### Insertion at Beginning

Important logic:

```c
newNode->prev = NULL;
newNode->next = head;

if (head != NULL)
{
    head->prev = newNode;
}

head = newNode;
```

Time Complexity: `O(1)`

### Insertion at End

Move to the last node and connect the new node:

```c
temp->next = newNode;
newNode->prev = temp;
```

Time Complexity: `O(n)`

If a `tail` pointer is maintained, it can be `O(1)`.

### Insertion at Position

Move to the node before the required position and update four links:

```c
newNode->next = temp->next;
newNode->prev = temp;

if (temp->next != NULL)
{
    temp->next->prev = newNode;
}

temp->next = newNode;
```

Time Complexity: `O(n)`

---

## 8. Deletion

Deletion means removing a node from the linked list.

### Types of Deletion

1. Deletion from Beginning
2. Deletion from End
3. Deletion from Position

### Deletion from Beginning

```c
temp = head;
head = head->next;

if (head != NULL)
{
    head->prev = NULL;
}

free(temp);
```

Time Complexity: `O(1)`

### Deletion from End

Move to the last node and use its `prev` pointer:

```c
temp->prev->next = NULL;
free(temp);
```

Time Complexity: `O(n)`

With a `tail` pointer, it can be `O(1)`.

### Deletion from Position

Connect the previous node with the next node:

```c
temp->prev->next = temp->next;

if (temp->next != NULL)
{
    temp->next->prev = temp->prev;
}

free(temp);
```

Time Complexity: `O(n)`

---

## 9. Updation

Updation means changing the data stored in a particular node.

Steps:

1. Traverse to the required position.
2. Change the value of `data`.

```c
temp->data = newValue;
```

Time Complexity: `O(n)`

---

## 10. Reversal

Reversal means changing the direction of the linked list.

For every node, swap the `prev` and `next` pointers.

```c
next = current->next;

current->next = current->prev;
current->prev = next;

current = next;
```

After reversal:

```text
Before:
NULL ← 10 ⇄ 20 ⇄ 30 → NULL

After:
NULL ← 30 ⇄ 20 ⇄ 10 → NULL
```

Time Complexity: `O(n)`

Space Complexity: `O(1)` auxiliary space.

---

## 11. Advantages

1. Can be traversed in both directions.
2. Deletion is easier when the node is known.
3. Insertion and deletion do not require shifting elements.
4. Useful for applications requiring forward and backward movement.
5. More flexible than a singly linked list.

---

## 12. Disadvantages

1. Requires extra memory for the `prev` pointer.
2. More pointer operations are required.
3. Implementation is more complex than a singly linked list.
4. Incorrect pointer handling can break the list.

---

## 13. Applications

Doubly linked lists are used in:

* Browser forward/backward navigation
* Undo and redo operations
* Music playlists
* Image viewers
* Navigation systems
* LRU cache implementations
* Memory management systems

---

## 14. Doubly Linked List vs Singly Linked List

| Feature           | Singly Linked List    | Doubly Linked List   |
| ----------------- | --------------------- | -------------------- |
| Pointers per node | 1                     | 2                    |
| Direction         | Forward only          | Forward and backward |
| Memory            | Less                  | More                 |
| Reverse traversal | Not directly possible | Possible             |
| Deletion          | More pointer handling | Easier               |
| Implementation    | Simpler               | More complex         |

---

## 15. Complexity Summary

| Operation               | Time Complexity |
| ----------------------- | --------------: |
| Creation*               |         `O(n²)` |
| Forward Traversal       |          `O(n)` |
| Backward Traversal      |          `O(n)` |
| Searching               |          `O(n)` |
| Insertion at Beginning  |          `O(1)` |
| Insertion at End        |          `O(n)` |
| Insertion at Position   |          `O(n)` |
| Deletion from Beginning |          `O(1)` |
| Deletion from End       |          `O(n)` |
| Deletion from Position  |          `O(n)` |
| Updation                |          `O(n)` |
| Reversal                |          `O(n)` |

*The creation programs used in this folder traverse to the end for every new node. With a `tail` pointer, creation can be performed in `O(n)` time.

Most operations use **O(1) auxiliary space**, while the linked list itself requires **O(n)** memory.

---

## 16. Important Exam Points

* A doubly linked list contains `prev`, `data`, and `next`.
* `head` points to the first node.
* First node has `prev = NULL`.
* Last node has `next = NULL`.
* It supports traversal in both directions.
* It requires more memory than a singly linked list.
* Insertion and deletion require careful updating of both pointers.
* Reversal requires swapping `prev` and `next`.
* Dynamic memory allocation is commonly performed using `malloc()`.

---

## 17. Conclusion

A **Doubly Linked List** is a dynamic data structure in which every node contains links to both the previous and next nodes. It provides efficient bidirectional traversal and makes many insertion and deletion operations easier, but it requires additional memory and more complex pointer management compared with a singly linked list.