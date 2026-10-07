# Circular Singly Linked List

## 1. Introduction

A Circular Singly Linked List is a linked list in which the last node points back to the first node (`head`) instead of pointing to `NULL`.

In a normal singly linked list:

```text
10 → 20 → 30 → NULL
```

In a circular singly linked list:

```text
10 → 20 → 30
↑         ↓
└─────────┘
```

The last node always points back to `head`.

---

## 2. Node Structure

A node contains two parts:

1. `data` — stores the value.
2. `next` — stores the address of the next node.

```c
struct Node
{
    int data;
    struct Node *next;
};
```

---

## 3. Structure of a Circular Singly Linked List

Example:

```text
head
 ↓
10 → 20 → 30 → 40
↑                   ↓
└───────────────────┘
```

Here:

```text
40->next = head
```

There is no `NULL` at the end of the list.

---

## 4. Important Difference from Singly Linked List

### Singly Linked List

```text
10 → 20 → 30 → NULL
```

The last node contains:

```c
last->next = NULL;
```

### Circular Singly Linked List

```text
10 → 20 → 30
↑         ↓
└─────────┘
```

The last node contains:

```c
last->next = head;
```

---

# 5. Creation

To create a circular singly linked list:

1. Create a new node.
2. If the list is empty, make it the `head`.
3. Make the new node point to `head`.
4. For additional nodes, find the last node.
5. Connect the last node to the new node.
6. Make the new node point to `head`.

Important logic:

```c
temp->next = newNode;
newNode->next = head;
```

### Time Complexity

`O(n²)` in the basic implementation because the last node is searched for every insertion.

### Space Complexity

`O(n)` for storing the nodes.

---

# 6. Traversal

Traversal means visiting every node of the circular linked list.

A circular linked list cannot normally be traversed using:

```c
while (temp != NULL)
```

because `temp` never becomes `NULL`.

Instead, use:

```c
temp = head;

do
{
    printf("%d", temp->data);
    temp = temp->next;
}
while (temp != head);
```

The traversal stops when we reach `head` again.

### Time Complexity

`O(n)`

### Space Complexity

`O(1)`

---

# 7. Searching

Searching means finding a particular value in the circular linked list.

Steps:

1. Start from `head`.
2. Compare the current node's data with the search value.
3. Move to the next node.
4. Stop if the value is found.
5. Stop when we reach `head` again.

Example:

```text
10 → 20 → 30 → 40
↑                   ↓
└───────────────────┘
```

Search for `30`.

The search checks:

```text
10 → 20 → 30
```

and stops when `30` is found.

### Time Complexity

* Best Case: `O(1)`
* Average Case: `O(n)`
* Worst Case: `O(n)`

### Space Complexity

`O(1)`

---

# 8. Insertion at Beginning

Insertion at beginning means adding a new node before the current `head`.

Example:

```text
Before:

10 → 20 → 30
↑         ↓
└─────────┘
```

Insert `5`.

```text
After:

5 → 10 → 20 → 30
↑                   ↓
└───────────────────┘
```

Steps:

1. Create a new node.
2. Find the last node.
3. Make the new node point to the current head.
4. Make the last node point to the new node.
5. Make the new node the new head.

Important logic:

```c
newNode->next = head;
last->next = newNode;
head = newNode;
```

### Time Complexity

`O(n)` with only a head pointer.

### Space Complexity

`O(1)` auxiliary space.

---

# 9. Insertion at End

Insertion at end means adding a new node after the current last node.

Example:

```text
Before:

10 → 20 → 30
↑         ↓
└─────────┘
```

Insert `40`.

```text
After:

10 → 20 → 30 → 40
↑              ↓
└──────────────┘
```

Steps:

1. Create a new node.
2. Find the last node.
3. Make the last node point to the new node.
4. Make the new node point to `head`.

Important logic:

```c
temp->next = newNode;
newNode->next = head;
```

### Time Complexity

`O(n)` with only a head pointer.

### Space Complexity

`O(1)` auxiliary space.

---

# 10. Insertion at Position

Insertion at position means adding a new node at a specific position.

Example:

```text
Before:

10 → 20 → 30 → 40
```

Insert `25` at position `3`.

```text
After:

10 → 20 → 25 → 30 → 40
```

Steps:

1. Create a new node.
2. Take the required position.
3. If the position is `1`, update the head and last node.
4. Otherwise, move to the node before the required position.
5. Connect the new node between the two nodes.

Important logic:

```c
newNode->next = temp->next;
temp->next = newNode;
```

### Time Complexity

`O(n)`

### Space Complexity

`O(1)` auxiliary space.

---

# 11. Deletion from Beginning

Deletion from beginning removes the first node.

Example:

```text
Before:

10 → 20 → 30
↑         ↓
└─────────┘
```

After deleting `10`:

```text
20 → 30
↑     ↓
└─────┘
```

Steps:

1. Check whether the list is empty.
2. If there is only one node, delete it and set `head = NULL`.
3. Otherwise, find the last node.
4. Move `head` to the second node.
5. Connect the last node to the new head.
6. Free the old head.

Important logic:

```c
head = head->next;
last->next = head;
free(temp);
```

### Time Complexity

`O(n)` with only a head pointer.

### Space Complexity

`O(1)`

---

# 12. Deletion from End

Deletion from end removes the last node.

Example:

```text
Before:

10 → 20 → 30 → 40
↑                   ↓
└───────────────────┘
```

After deleting `40`:

```text
10 → 20 → 30
↑         ↓
└─────────┘
```

Steps:

1. Check whether the list is empty.
2. Handle the single-node case.
3. Find the last node.
4. Keep track of the node before the last node.
5. Connect the previous node to `head`.
6. Free the last node.

Important logic:

```c
previous->next = head;
free(temp);
```

### Time Complexity

`O(n)`

### Space Complexity

`O(1)`

---

# 13. Deletion from Position

Deletion from position removes a node from a specific position.

Example:

```text
Before:

10 → 20 → 30 → 40
```

Delete position `3`.

```text
After:

10 → 20 → 40
```

Steps:

1. Check whether the list is empty.
2. If position is `1`, perform deletion from beginning.
3. Otherwise, move to the node before the required position.
4. Store the node to be deleted.
5. Skip that node.
6. Free the deleted node.

Important logic:

```c
previous = temp->next;
temp->next = previous->next;
free(previous);
```

### Time Complexity

`O(n)`

### Space Complexity

`O(1)`

---

# 14. Updation

Updation means changing the data stored in an existing node.

Example:

```text
Before:

10 → 20 → 30 → 40
```

Update position `3` with `35`.

```text
After:

10 → 20 → 35 → 40
```

Steps:

1. Take the position.
2. Start from `head`.
3. Move to the required position.
4. Replace the old data with the new value.

Important logic:

```c
temp->data = newValue;
```

### Time Complexity

`O(n)`

### Space Complexity

`O(1)`

---

# 15. Reversal

Reversal means reversing the direction of all links in the circular linked list.

Before:

```text
10 → 20 → 30 → 40
↑                   ↓
└───────────────────┘
```

After:

```text
40 → 30 → 20 → 10
↑                   ↓
└───────────────────┘
```

Three important pointers are used:

```c
previous
current
nextNode
```

Important logic:

```c
nextNode = current->next;
current->next = previous;
previous = current;
current = nextNode;
```

After reversing all links, the new head is assigned.

### Time Complexity

`O(n)`

### Space Complexity

`O(1)`

---

# 16. Advantages

1. The last node points directly to the first node.
2. Traversal can continue from the last node to the first node.
3. Useful for applications that require repeated circular processing.
4. No `NULL` pointer is required at the end.
5. Can be useful for implementing circular queues and round-robin scheduling.

---

# 17. Disadvantages

1. Implementation is slightly more complex than a normal singly linked list.
2. There is no `NULL` at the end to indicate termination.
3. Care must be taken to avoid infinite loops.
4. Searching for the last node takes `O(n)` when only a head pointer is maintained.
5. Incorrect pointer handling can easily break the circular structure.

---

# 18. Applications

Circular singly linked lists are commonly useful in:

* Round-robin CPU scheduling
* Circular queues
* Multiplayer turn systems
* Music playlists
* Repeated task scheduling
* Token passing systems
* Josephus problem
* Resource sharing systems

---

# 19. Time Complexity Summary

| Operation               | Time Complexity |
| ----------------------- | --------------: |
| Creation                |          O(n²)* |
| Traversal               |            O(n) |
| Searching               |            O(n) |
| Insertion at Beginning  |            O(n) |
| Insertion at End        |            O(n) |
| Insertion at Position   |            O(n) |
| Deletion from Beginning |            O(n) |
| Deletion from End       |            O(n) |
| Deletion from Position  |            O(n) |
| Updation                |            O(n) |
| Reversal                |            O(n) |

`*` The creation implementation used in this folder searches for the last node for every new node. With a tail pointer, creation and end insertion can be improved to `O(n)` overall and `O(1)` per insertion.

---

# 20. Important Rule

The most important rule of a circular singly linked list is:

```c
last->next = head;
```

Never use:

```c
last->next = NULL;
```

if you want to maintain the circular structure.

For traversal, remember:

```c
do
{
    // process node
    temp = temp->next;
}
while (temp != head);
```

This is the key difference between a normal singly linked list and a circular singly linked list.

---

# 21. Folder Programs

The Circular Singly Linked List folder contains:

```text
01-Creation.c
02-Traversal.c
03-Searching.c
04-Insertion-at-Beginning.c
05-Insertion-at-End.c
06-Insertion-at-Position.c
07-Deletion-from-Beginning.c
08-Deletion-from-End.c
09-Deletion-from-Position.c
10-Updation.c
11-Reversal.c
Circular-Singly-Linked-List-Theory.md
```

These programs cover the major operations of a Circular Singly Linked List.