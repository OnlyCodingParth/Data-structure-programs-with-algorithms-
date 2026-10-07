# Hashing - Complete Theory

## 1. What is Hashing?

Hashing is a technique used to store and retrieve data quickly.

It uses a special function called a **Hash Function** to convert a key into an index of a hash table.

### Basic Process

Key
↓
Hash Function
↓
Index
↓
Hash Table

For example:

If the hash table size is 10:

    Hash Index = Key % 10

For key 25:

    25 % 10 = 5

Therefore, key 25 is stored at index 5.

---

## 2. What is a Hash Table?

A hash table is a data structure that stores data using an array-like structure.

Each position in the table is called a **slot** or **index**.

For example:

    Index     Value
    0         -
    1         -
    2         32
    3         -
    4         -
    5         25
    6         -
    7         47
    8         -
    9         -

The index is obtained using the hash function.

---

## 3. Hash Function

A hash function converts a key into a valid index of the hash table.

A simple hash function is:

    hash(key) = key % table_size

Example:

    Key = 37
    Table Size = 10

    37 % 10 = 7

Therefore:

    Index = 7

### Characteristics of a Good Hash Function

A good hash function should:

1. Be simple to calculate.
2. Be fast.
3. Distribute keys uniformly.
4. Reduce collisions.
5. Always produce a valid table index.

---

## 4. Collision

A collision occurs when two or more keys produce the same hash index.

Example:

    25 % 10 = 5
    35 % 10 = 5
    45 % 10 = 5

All three keys want index 5.

Therefore, a collision occurs.

Collision handling is an important part of hashing.

---

# 5. Collision Resolution Techniques

The main collision resolution techniques are:

1. Linear Probing
2. Quadratic Probing
3. Double Hashing
4. Chaining

---

# 6. Linear Probing

Linear probing is an open-addressing collision resolution technique.

If the calculated position is occupied, we check the next position.

### Formula

    New Index = (Index + i) % SIZE

where:

    i = 0, 1, 2, 3, ...

### Example

Suppose:

    Key = 25
    25 % 10 = 5

If index 5 is occupied:

    5 → 6 → 7 → 8 → ...

We continue until an empty position is found.

### Advantages

- Simple to implement.
- Does not require linked lists.
- Good cache performance.

### Disadvantages

- Can cause primary clustering.
- Performance decreases when the table becomes heavily occupied.

---

# 7. Quadratic Probing

Quadratic probing is another open-addressing technique.

Instead of checking consecutive positions, it uses square values.

### Formula

    New Index = (Index + i²) % SIZE

where:

    i = 0, 1, 2, 3, ...

### Example

Suppose the initial index is 5:

    i = 0 → 5
    i = 1 → 6
    i = 2 → 9
    i = 3 → 4

Therefore, the probing sequence is:

    5 → 6 → 9 → 4 → ...

### Advantage

It reduces primary clustering compared with linear probing.

### Disadvantage

It can still have secondary clustering.

---

# 8. Double Hashing

Double hashing uses two hash functions.

The first hash function gives the initial position.

The second hash function gives the step size.

### Formula

    New Index = (Hash1(key) + i × Hash2(key)) % SIZE

Example:

    Hash1(key) = key % 10

    Hash2(key) = 7 - (key % 7)

Suppose:

    Key = 25

Then:

    Hash1(25) = 25 % 10 = 5

    Hash2(25) = 7 - (25 % 7)
              = 7 - 4
              = 3

The probing sequence becomes:

    5 → 8 → 1 → 4 → ...

### Advantages

- Reduces clustering.
- Usually provides better distribution than linear probing.

### Disadvantages

- More calculations are required.
- The second hash function must be chosen carefully.

---

# 9. Chaining

Chaining is a collision resolution technique where every hash-table position can contain a linked list.

If multiple keys produce the same index, they are stored in the linked list at that index.

Example:

    25 % 10 = 5
    35 % 10 = 5
    45 % 10 = 5

Therefore:

    Index 5:

    45 → 35 → 25 → NULL

### Advantages

- Multiple keys can be stored at the same index.
- Hash table does not require every slot to be empty before insertion.
- Deletion is relatively simple.

### Disadvantages

- Requires extra memory for linked-list nodes.
- Additional pointer operations are required.

---

# 10. Open Addressing

Linear probing, quadratic probing, and double hashing are examples of **open addressing**.

In open addressing, all elements are stored directly inside the hash table.

If a position is occupied, another position is searched.

Types:

1. Linear Probing
2. Quadratic Probing
3. Double Hashing

---

# 11. Hashing with Chaining vs Open Addressing

| Feature | Chaining | Open Addressing |
|---|---|---|
| Collision handling | Linked list | Find another slot |
| Extra memory | Required | Usually not required |
| Storage | Table + linked lists | Table itself |
| Examples | Chaining | Linear, Quadratic, Double Hashing |
| Deletion | Easier | More complicated |
| Clustering | No probing clustering | Can occur |

---

# 12. Load Factor

Load factor tells us how full a hash table is.

### Formula

    Load Factor = Number of Elements / Table Size

It is commonly represented by:

    α = n / m

where:

    n = number of elements
    m = size of hash table

Example:

    Number of elements = 7
    Table size = 10

    Load Factor = 7 / 10
                = 0.7

A high load factor generally means more collisions and slower operations.

---

# 13. Insertion in Hashing

The basic insertion process is:

1. Take the key.
2. Apply the hash function.
3. Calculate the index.
4. Check whether the position is available.
5. If available, insert the key.
6. If occupied, handle the collision.
7. Repeat until the key is inserted.

---

# 14. Searching in Hashing

The basic searching process is:

1. Take the key to be searched.
2. Apply the hash function.
3. Calculate the initial index.
4. Check the position.
5. If the key is found, return success.
6. If a collision technique is being used, follow its probing sequence.
7. If the key is not found, return failure.

---

# 15. Deletion in Hashing

Deletion depends on the collision resolution technique.

In simple hashing without collision handling, the position can be marked as empty.

In open addressing, simply marking a position as empty can cause problems during future searches.

Therefore, a special marker called a **tombstone** or **deleted marker** is often used.

In chaining, the corresponding node can simply be removed from the linked list.

---

# 16. Time Complexity

Average-case complexity of hashing operations is generally:

| Operation | Average Case | Worst Case |
|---|---:|---:|
| Insertion | O(1) | O(n) |
| Searching | O(1) | O(n) |
| Deletion | O(1) | O(n) |

The worst case can occur when many keys produce the same index.

For example, with chaining, if all keys are stored in the same linked list, searching may require traversing the entire list.

---

# 17. Space Complexity

For a hash table containing n elements:

    Space Complexity = O(n)

Additional space may be required depending on the collision resolution technique.

Chaining requires additional memory for linked-list nodes.

---

# 18. Hashing vs Array

| Feature | Array | Hash Table |
|---|---|---|
| Access | Index-based | Key-based |
| Searching | O(n) generally | O(1) average |
| Insertion | Can require shifting | O(1) average |
| Deletion | Can require shifting | O(1) average |
| Ordering | Maintained by index | Usually not maintained |
| Collision | No | Possible |

---

# 19. Advantages of Hashing

1. Very fast average-case searching.
2. Fast insertion.
3. Fast deletion.
4. Useful for key-value storage.
5. Efficient for large datasets.
6. Useful in databases and programming languages.

---

# 20. Disadvantages of Hashing

1. Collisions can occur.
2. A good hash function is important.
3. Performance can decrease when the table becomes too full.
4. Data is generally not stored in sorted order.
5. Collision handling makes implementation more complicated.

---

# 21. Applications of Hashing

Hashing is used in:

- Dictionaries
- Symbol tables
- Databases
- Caches
- Password storage systems
- Compiler design
- Sets and maps
- Duplicate detection
- File systems
- Data indexing
- Fast lookup systems

---

# 22. Important Hashing Terms

### Key

The value used as input to the hash function.

### Hash Function

Function that converts a key into a table index.

### Hash Table

Data structure used to store keys and associated values.

### Collision

When two or more keys produce the same index.

### Load Factor

Ratio of the number of stored elements to the table size.

### Probing

The process of finding another position after a collision.

### Chaining

Using a linked list at each hash-table index to handle collisions.

---

# 23. Important Formulas

### Simple Hash Function

    hash(key) = key % SIZE

### Linear Probing

    New Index = (Index + i) % SIZE

### Quadratic Probing

    New Index = (Index + i²) % SIZE

### Double Hashing

    New Index = (Hash1(key) + i × Hash2(key)) % SIZE

### Load Factor

    α = Number of Elements / Table Size

---

# 24. Important Exam Points

1. Hashing provides fast average-case searching.
2. A hash function converts a key into an index.
3. Collision occurs when two keys have the same hash index.
4. Linear probing checks consecutive positions.
5. Quadratic probing uses squared increments.
6. Double hashing uses two hash functions.
7. Chaining uses linked lists to handle collisions.
8. Linear probing, quadratic probing, and double hashing use open addressing.
9. Load factor indicates how full the hash table is.
10. Average-case hashing operations are generally O(1).
11. Worst-case hashing operations can become O(n).
12. A good hash function should distribute keys uniformly.
13. Chaining requires additional memory for linked lists.
14. Hashing generally does not maintain sorted order.

---

# 25. Overall Hashing Concept

The complete concept can be represented as:

    Key
     ↓
    Hash Function
     ↓
    Hash Index
     ↓
    ┌──────────────────────┐
    │     Hash Table       │
    └──────────────────────┘
             ↓
       Is position free?
          /        \
        Yes         No
         ↓           ↓
      Insert      Collision
                     ↓
          ┌──────────┼──────────┐
          ↓          ↓          ↓
       Linear    Quadratic    Double
       Probing    Probing     Hashing

                     OR

                  Chaining
                     ↓
               Linked List

---

# Conclusion

Hashing is an important data structure technique used for fast data storage and retrieval.

The main idea is to convert a key into an index using a hash function.

When collisions occur, techniques such as:

- Linear Probing
- Quadratic Probing
- Double Hashing
- Chaining

are used to resolve them.

With a good hash function and suitable table size, hashing provides very fast average-case insertion, searching, and deletion.

Average Time Complexity:

    O(1)

Worst-case Time Complexity:

    O(n)

Space Complexity:

    O(n)