# Circular Doubly Linked List - Theory

## 1. What is a Circular Doubly Linked List?

A **Circular Doubly Linked List** is a linked list in which every node contains three parts:

```text
+--------+--------+--------+
|  prev  |  data  |  next  |
+--------+--------+--------+
```

* `prev` stores the address of the previous node.
* `data` stores the actual value.
* `next` stores the address of the next node.

It is called:

* **Doubly** because each node has both `prev` and `next` pointers.
* **Circular** because the last node is connected back to the first node.

---

## 2. Node Structure

```c
struct Node
{
    struct Node *prev;
    int data;
    struct Node *next;
};
```

---

## 3. Circular Connection

For a list containing:

```text
10 <-> 20 <-> 30
```

The connections are:

```text
head->prev = last
last->next = head
```

Therefore:

```text
        ┌──────────────────────┐
        ↓                      │
      10 <-> 20 <-> 30 ────────┘
      ↑
      └────────────────────────
```

More precisely:

```text
10.prev = 30
10.next = 20

20.prev = 10
20.next = 30

30.prev = 20
30.next = 10
```

There is **no `NULL` at either end**.

---

## 4. Main Features

* Each node has `prev`, `data`, and `next`.
* Forward traversal is possible.
* Backward traversal is possible.
* The last node points to the first node.
* The first node points back to the last node through `prev`.
* There is no `NULL` link at the ends.
* Traversal can continue circularly.

---

## 5. Traversal

### Forward Traversal

Start from `head` and follow `next`.

```c
temp = head;

do
{
    printf("%d ", temp->data);
    temp = temp->next;
}
while (temp != head);
```

Example:

```text
10 -> 20 -> 30 -> back to 10
```

### Backward Traversal

Start from `head->prev`, which is the last node, and follow `prev`.

```text
30 -> 20 -> 10 -> back to 30
```

---

# 6. Operations

## 6.1 Creation

Nodes are created one by one.

For the first node:

```c
newNode->prev = newNode;
newNode->next = newNode;
```

For subsequent nodes, the new node is connected between the last node and `head`.

---

## 6.2 Traversal

Traversal can be performed in both directions:

```text
Forward:
10 -> 20 -> 30 -> 10

Backward:
30 -> 20 -> 10 -> 30
```

---

## 6.3 Searching

Search each node's `data` until:

* The value is found, or
* We reach `head` again.

```text
Time Complexity: O(n)
```

---

## 6.4 Insertion at Beginning

Suppose:

```text
10 <-> 20 <-> 30
```

Insert `5`.

Result:

```text
5 <-> 10 <-> 20 <-> 30
```

Important connections:

```c
last = head->prev;

newNode->next = head;
newNode->prev = last;

last->next = newNode;
head->prev = newNode;

head = newNode;
```

With a `head` pointer, insertion at beginning is:

```text
Time Complexity: O(1)
```

---

## 6.5 Insertion at End

The last node can be obtained directly:

```c
last = head->prev;
```

Then the new node is connected between `last` and `head`.

```text
Time Complexity: O(1)
```

---

## 6.6 Insertion at Position

To insert at a specific position:

1. Check whether the position is valid.
2. If position is `1`, insert at beginning.
3. Otherwise, move to the node before the required position.
4. Connect the new node using both `prev` and `next`.

```text
Time Complexity: O(n)
```

---

## 6.7 Deletion from Beginning

The first node is removed and `head` is moved to the next node.

Important:

```c
temp = head->prev;
head = head->next;

temp->next = head;
head->prev = temp;
```

```text
Time Complexity: O(1)
```

---

## 6.8 Deletion from End

The last node can be accessed directly using:

```c
last = head->prev;
```

The node before it is:

```c
temp = last->prev;
```

Then reconnect:

```c
temp->next = head;
head->prev = temp;
```

```text
Time Complexity: O(1)
```

---

## 6.9 Deletion from Position

Move to the required node and reconnect its neighboring nodes:

```c
deleteNode->prev->next = deleteNode->next;
deleteNode->next->prev = deleteNode->prev;
```

Then:

```c
free(deleteNode);
```

```text
Time Complexity: O(n)
```

---

## 6.10 Updation

Updation means changing the data of an existing node.

Example:

```text
Before:
10 <-> 20 <-> 30

Update position 2 to 50.

After:
10 <-> 50 <-> 30
```

Only `data` changes.

The `prev` and `next` pointers remain unchanged.

```text
Time Complexity: O(n)
```

---

## 6.11 Reversal

To reverse a circular doubly linked list:

1. Visit every node.
2. Swap its `prev` and `next` pointers.
3. Change `head` to the old last node.

Example:

```text
Before:
10 <-> 20 <-> 30

After:
30 <-> 20 <-> 10
```

```text
Time Complexity: O(n)
Space Complexity: O(1)
```

---

# 7. Time Complexity Summary

| Operation               | Time Complexity |
| ----------------------- | --------------: |
| Creation                |            O(n) |
| Forward Traversal       |            O(n) |
| Backward Traversal      |            O(n) |
| Searching               |            O(n) |
| Insertion at Beginning  |            O(1) |
| Insertion at End        |            O(1) |
| Insertion at Position   |            O(n) |
| Deletion from Beginning |            O(1) |
| Deletion from End       |            O(1) |
| Deletion from Position  |            O(n) |
| Updation                |            O(n) |
| Reversal                |            O(n) |

---

# 8. Advantages

1. Can be traversed in both directions.
2. No `NULL` at the ends.
3. Easy access to the last node using `head->prev`.
4. Insertion at beginning can be done in O(1).
5. Deletion from beginning can be done in O(1).
6. Deletion from end can be done in O(1).
7. Useful when circular movement in both directions is required.

---

# 9. Disadvantages

1. Requires extra memory for the `prev` pointer.
2. Pointer manipulation is more complicated.
3. Traversal needs a stopping condition based on `head`.
4. Incorrect pointer updates can break the circular structure.
5. Debugging is more difficult than with a singly linked list.

---

# 10. Applications

Circular doubly linked lists can be useful in:

* Music playlists
* Browser history
* Undo/redo systems
* Navigation systems
* Operating-system scheduling
* Games with circular player turns
* Circular menus
* Deque implementations

---

# 11. Difference from Other Linked Lists

| Feature              | Singly | Doubly | Circular Singly | Circular Doubly |
| -------------------- | ------ | ------ | --------------- | --------------- |
| `prev` pointer       | No     | Yes    | No              | Yes             |
| `next` pointer       | Yes    | Yes    | Yes             | Yes             |
| Last points to first | No     | No     | Yes             | Yes             |
| Forward traversal    | Yes    | Yes    | Yes             | Yes             |
| Backward traversal   | No     | Yes    | No              | Yes             |
| `NULL` at end        | Yes    | Yes    | No              | No              |

---

# 12. Important Pointer Concept

The most important concept to remember is:

```c
head->prev
```

In a circular doubly linked list, this directly gives the **last node**.

And:

```c
last->next
```

directly gives the **head**.

Therefore:

```text
head->prev = last
last->next = head
```

These two connections make the list circular.

---

# 13. Overall Structure

```text
             ┌──────────────────────────────┐
             ↓                              │
        +----+----+    +----+----+    +----+----+
        | prev   |    | prev   |    | prev   |
        |  10    |<-->|  20    |<-->|  30    |
        | next   |    | next   |    | next   |
        +----+----+    +----+----+    +----+----+
             ↑                              │
             └──────────────────────────────┘
```

A Circular Doubly Linked List combines:

```text
Doubly Linked List
        +
Circular connection
        =
Circular Doubly Linked List
```

---

# 14. Key Points for Exams

* Each node contains `prev`, `data`, and `next`.
* `head->prev` points to the last node.
* `last->next` points to `head`.
* There is no `NULL` at the ends.
* Traversal can be performed in both directions.
* Insertion at beginning is O(1).
* Insertion at end is O(1) when `head->prev` is used.
* Deletion at beginning is O(1).
* Deletion at end is O(1).
* Position-based operations generally require O(n).
* Reversal is performed by swapping `prev` and `next`.

---

## Conclusion

A **Circular Doubly Linked List** is a combination of the flexibility of a doubly linked list and the circular structure of a circular linked list.

Its most important property is:

```text
head->prev = last
last->next = head
```

Because of this circular connection and the presence of both `prev` and `next` pointers, the list can move **forward and backward continuously**.