# Queue - Theory

## 1. Introduction

A **Queue** is a linear data structure in which insertion is performed from one end called **Rear** and deletion is performed from another end called **Front**.

Queue follows the **FIFO (First In, First Out)** principle.

Example:

```text
10 → 20 → 30 → 40
↑              ↑
Front          Rear
```

The element `10` will be removed first.

---

## 2. Basic Terminology

### Front

`Front` points to the first element of the queue.

### Rear

`Rear` points to the last element of the queue.

### Enqueue

Adding an element to the rear of the queue.

### Dequeue

Removing an element from the front of the queue.

### Peek

Accessing the front element without removing it.

---

## 3. Basic Operations of Queue

### 1. Enqueue

Enqueue means inserting an element at the rear.

Example:

```text
Before:
10 → 20 → 30

Enqueue(40)

After:
10 → 20 → 30 → 40
```

**Time Complexity:** O(1)

---

### 2. Dequeue

Dequeue means removing an element from the front.

Example:

```text
Before:
10 → 20 → 30

Dequeue()

After:
20 → 30
```

**Time Complexity:** O(1)

---

### 3. Peek

Peek returns the front element without removing it.

```text
Queue:
10 → 20 → 30

Peek = 10
```

**Time Complexity:** O(1)

---

### 4. Display

Display prints all queue elements from front to rear.

**Time Complexity:** O(n)

---

## 4. Queue Representation

A queue can be implemented using:

1. Array
2. Linked List

### Array Queue

```text
[10][20][30][40]
 ↑           ↑
Front       Rear
```

It has a fixed size.

### Linked List Queue

```text
Front
  ↓
[10] → [20] → [30] → NULL
                         ↑
                        Rear
```

It has a dynamic size.

---

# 5. Types of Queue

The main types of queues are:

1. Linear Queue
2. Circular Queue
3. Deque
4. Priority Queue

---

## 5.1 Linear Queue

A Linear Queue is the basic queue that follows FIFO.

Insertion is performed at the rear and deletion at the front.

```text
Front → 10 → 20 → 30 ← Rear
```

### Disadvantage

In an array implementation, empty spaces created after deletion may not be reused.

Example:

```text
[ ][ ][30][40][50]
 ↑
unused space
```

This problem is solved by using a Circular Queue.

---

## 5.2 Circular Queue

A Circular Queue is a queue in which the last position is connected back to the first position.

It allows the unused spaces created by deletion to be reused.

Important formula:

```c
rear = (rear + 1) % MAX;
front = (front + 1) % MAX;
```

### Full Condition

```c
(rear + 1) % MAX == front
```

### Empty Condition

```c
front == -1
```

### Advantages

* Efficient use of array space
* Reuses empty positions
* Enqueue and Dequeue take O(1) time

### Applications

* CPU scheduling
* Memory management
* Buffer management
* Traffic systems

---

## 5.3 Deque

**Deque** stands for **Double-Ended Queue**.

In a deque, insertion and deletion can be performed from both ends.

```text
Front ←→ Rear
```

Operations:

* Insert at Front
* Insert at Rear
* Delete from Front
* Delete from Rear

### Advantages

* More flexible than a normal queue
* Can behave like both stack and queue

### Applications

* Task scheduling
* Sliding window problems
* Undo/Redo systems
* Palindrome checking

---

## 5.4 Priority Queue

A Priority Queue is a queue in which each element has a priority.

The element with higher priority is served first.

Example:

```text
Value     Priority

10          3
20          1
30          2
```

If smaller number means higher priority:

```text
20 → 30 → 10
```

### Important Point

A Priority Queue does not strictly follow FIFO. Priority determines the order of deletion.

### Applications

* CPU scheduling
* Printer scheduling
* Network packet management
* Dijkstra's algorithm
* Event simulation

---

# 6. Queue Using Linked List

A queue can also be implemented using a linked list.

Two pointers are generally used:

```text
front → First Node
rear  → Last Node
```

Example:

```text
front
  ↓
[10] → [20] → [30] → NULL
                         ↑
                        rear
```

### Enqueue

Insert a new node at the rear.

### Dequeue

Delete a node from the front.

### Advantages

* Dynamic size
* No fixed array limit
* Efficient insertion and deletion

### Disadvantages

* Extra memory for pointers
* Dynamic memory allocation is required

---

# 7. Overflow and Underflow

### Queue Overflow

Overflow occurs when we try to insert an element into a full queue.

```text
Queue is Full
    ↓
Enqueue → Overflow
```

### Queue Underflow

Underflow occurs when we try to delete an element from an empty queue.

```text
Queue is Empty
    ↓
Dequeue → Underflow
```

---

# 8. Time Complexity

| Operation      | Linear Queue | Circular Queue | Deque | Priority Queue |
| -------------- | -----------: | -------------: | ----: | -------------: |
| Enqueue/Insert |         O(1) |           O(1) |  O(1) |          O(1)* |
| Dequeue/Delete |         O(1) |           O(1) |  O(1) |          O(n)* |
| Peek           |         O(1) |           O(1) |  O(1) |          O(n)* |
| Display        |         O(n) |           O(n) |  O(n) |           O(n) |

`*` Complexity depends on the implementation. The table matches the simple array implementation used in this repository.

---

# 9. Queue vs Stack

| Queue                 | Stack                    |
| --------------------- | ------------------------ |
| Follows FIFO          | Follows LIFO             |
| Insertion at rear     | Insertion at top         |
| Deletion from front   | Deletion from top        |
| Uses Front and Rear   | Uses Top                 |
| Example: waiting line | Example: stack of plates |

---

# 10. Queue vs Circular Queue

| Linear Queue                   | Circular Queue          |
| ------------------------------ | ----------------------- |
| Linear arrangement             | Circular arrangement    |
| Empty spaces may be wasted     | Empty spaces are reused |
| Simple implementation          | Slightly more complex   |
| May suffer from false overflow | Avoids false overflow   |

---

# 11. Advantages of Queue

1. Follows a simple FIFO principle.
2. Useful for scheduling tasks.
3. Enqueue and Dequeue can be performed efficiently.
4. Useful in resource sharing and buffering.
5. Can be implemented using arrays or linked lists.

---

# 12. Disadvantages of Queue

1. Normal array queue has fixed size.
2. Linear queue may waste unused space.
3. Searching for a particular element is inefficient.
4. Priority Queue requires additional logic for priorities.

---

# 13. Applications of Queue

Queues are used in:

* CPU scheduling
* Printer scheduling
* Keyboard and I/O buffering
* Network packet handling
* Breadth First Search (BFS)
* Customer service systems
* Traffic management
* Operating systems
* Task scheduling

---

# 14. Important Points for Exam

* Queue follows **FIFO**.
* Insertion is called **Enqueue**.
* Deletion is called **Dequeue**.
* Insertion takes place at **Rear**.
* Deletion takes place at **Front**.
* Peek accesses the front element without deleting it.
* Circular Queue reuses empty array positions.
* Deque allows insertion and deletion from both ends.
* Priority Queue removes elements according to priority.
* Queue can be implemented using an **Array or Linked List**.
* BFS uses a Queue.
* Empty Queue can cause **Underflow**.
* Full Queue can cause **Overflow**.

---

# 15. Conclusion

A Queue is an important linear data structure based on the **FIFO principle**. Its main operations are Enqueue, Dequeue, Peek, and Display.

Different types such as **Circular Queue, Deque, and Priority Queue** are used to solve different problems efficiently. Queue can be implemented using arrays or linked lists and is widely used in operating systems, scheduling, networking, and graph traversal.