# Stack

## 1. Introduction

A **Stack** is a linear data structure in which insertion and deletion are performed from only one end called the **TOP**.

Stack follows the **LIFO** principle.

**LIFO = Last In, First Out**

### Example

A stack of plates follows LIFO. The last plate placed on the top is the first plate removed.

---

# 2. Basic Structure of Stack

```text
      TOP
       ↓
     | 30 |
     | 20 |
     | 10 |
     ------
```

The element `30` is the top element.

All insertion and deletion operations take place at the TOP.

---

# 3. Basic Operations

## 3.1 Push

**Push** means inserting an element into the stack.

Example:

```text
Before:

30  ← TOP
20
10
```

Push `40`:

```text
40  ← TOP
30
20
10
```

### Complexity

* Time: O(1)
* Space: O(1) for one operation

---

## 3.2 Pop

**Pop** means removing the top element from the stack.

Example:

```text
40  ← TOP
30
20
10
```

After Pop:

```text
30  ← TOP
20
10
```

### Complexity

* Time: O(1)
* Space: O(1)

---

## 3.3 Peek

**Peek** means viewing the top element without removing it.

Example:

```text
30  ← TOP
20
10
```

Peek returns:

```text
30
```

The stack remains unchanged.

### Complexity

* Time: O(1)
* Space: O(1)

---

## 3.4 Display

Display prints all elements of the stack from TOP to bottom.

### Complexity

* Time: O(n)
* Space: O(1)

---

# 4. Stack Implementation

A stack can mainly be implemented using:

1. Array
2. Linked List

---

# 5. Stack Using Array

In an array implementation, a variable called `top` keeps track of the top element.

Initially:

```c
top = -1;
```

This means the stack is empty.

### Push

```c
top++;
stack[top] = value;
```

### Pop

```c
value = stack[top];
top--;
```

### Advantages

* Simple implementation
* Fast operations
* Easy to understand

### Disadvantages

* Fixed size
* May cause overflow when the array is full

---

# 6. Stack Using Linked List

In a linked-list implementation, each element is stored in a node.

```text
TOP
 ↓
[30 | •] → [20 | •] → [10 | NULL]
```

The `top` pointer points to the first node.

### Push

A new node is inserted at the beginning.

### Pop

The first node is removed.

### Advantages

* Dynamic size
* No fixed array size
* Memory is allocated when required

### Disadvantages

* Requires extra memory for pointers
* More complex than array implementation

---

# 7. Stack Overflow

**Stack Overflow** occurs when we try to insert an element into a full stack.

For an array-based stack:

```text
top == MAX - 1
```

means the stack is full.

---

# 8. Stack Underflow

**Stack Underflow** occurs when we try to remove an element from an empty stack.

For a stack using an array:

```text
top == -1
```

means the stack is empty.

---

# 9. Applications of Stack

Stacks are widely used in:

1. Function calls
2. Recursion
3. Expression conversion
4. Expression evaluation
5. Parentheses matching
6. Undo/Redo operations
7. Browser back button
8. Backtracking
9. Depth First Search (DFS)
10. Compiler processing

---

# 10. Expression Conversion Using Stack

Stack is used to convert expressions between:

* Infix
* Prefix
* Postfix

### Example

Infix:

```text
A + B
```

Prefix:

```text
+AB
```

Postfix:

```text
AB+
```

### Common forms

| Form    | Example |
| ------- | ------- |
| Infix   | `A+B`   |
| Prefix  | `+AB`   |
| Postfix | `AB+`   |

---

# 11. Postfix Evaluation

In postfix evaluation:

1. Scan the expression from left to right.
2. If the character is an operand, push it.
3. If it is an operator, pop two operands.
4. Perform the operation.
5. Push the result back.
6. The final stack element is the answer.

### Example

```text
23*54*+
```

Working:

```text
2 × 3 = 6
5 × 4 = 20
6 + 20 = 26
```

Result:

```text
26
```

Time Complexity: **O(n)**

Space Complexity: **O(n)**

---

# 12. Advantages of Stack

1. Simple and easy to implement.
2. Push and Pop operations are fast.
3. Useful for recursion and function calls.
4. Useful in expression processing.
5. Useful in backtracking algorithms.

---

# 13. Disadvantages of Stack

1. Only the top element can be directly accessed.
2. Array implementation has a fixed size.
3. Overflow can occur in a fixed-size stack.
4. Random access is not efficient.

---

# 14. Stack vs Queue

| Stack                    | Queue                   |
| ------------------------ | ----------------------- |
| Follows LIFO             | Follows FIFO            |
| Insertion at TOP         | Insertion at REAR       |
| Deletion from TOP        | Deletion from FRONT     |
| Example: Stack of plates | Example: Line of people |

**LIFO:** Last In, First Out

**FIFO:** First In, First Out

---

# 15. Complexity Summary

| Operation | Time Complexity |
| --------- | --------------: |
| Push      |            O(1) |
| Pop       |            O(1) |
| Peek      |            O(1) |
| Display   |            O(n) |

For an array or linked-list stack, Push, Pop, and Peek are normally O(1).

---

# 16. Important Exam Points

1. Stack is a linear data structure.
2. Stack follows LIFO.
3. TOP is the end from which insertion and deletion occur.
4. Push is used for insertion.
5. Pop is used for deletion.
6. Peek returns the top element without removing it.
7. Overflow occurs when a full stack receives a new element.
8. Underflow occurs when deletion is attempted on an empty stack.
9. Stack can be implemented using arrays or linked lists.
10. Stack is used in recursion, expression conversion, expression evaluation, and backtracking.

---

# 17. Conclusion

Stack is an important linear data structure based on the **LIFO principle**. Its main operations are Push, Pop, Peek, and Display. Because Push and Pop are efficient, stacks are widely used in recursion, expression processing, function calls, and many algorithms.