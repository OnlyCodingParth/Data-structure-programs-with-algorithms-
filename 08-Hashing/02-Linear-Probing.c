#include <stdio.h>

#define SIZE 10

// Important step - Hash function
int hashFunction(int key)
{
    return key % SIZE;
}

int main()
{
    int hashTable[SIZE];
    int key;
    int index;
    int i;

    // Initialize hash table
    for (i = 0; i < SIZE; i++)
    {
        hashTable[i] = -1;
    }

    printf("Enter key to insert: ");
    scanf("%d", &key);

    // Important step - Find initial index
    index = hashFunction(key);

    // Important step - Linear probing
    while (hashTable[index] != -1)
    {
        index = (index + 1) % SIZE;
    }

    // Important step - Insert key at empty position
    hashTable[index] = key;

    printf("Key %d inserted at index %d\n", key, index);

    printf("\nHash Table:\n");

    for (i = 0; i < SIZE; i++)
    {
        printf("Index %d = %d\n", i, hashTable[i]);
    }

    return 0;
}

/*
    Theory:
    Linear Probing is a collision resolution technique used in hashing.
    When the calculated index is already occupied, the next available
    position is checked.

    Formula:
    New Index = (Index + 1) % SIZE

    Algorithm:
    1. Create the hash table.
    2. Initialize all positions with -1.
    3. Take a key from the user.
    4. Calculate the initial index using the hash function.
    5. Check whether the calculated position is empty.
    6. If it is occupied, move to the next position.
    7. Continue until an empty position is found.
    8. Insert the key at the empty position.
    9. Display the hash table.

    Time Complexity:
    Average Case: O(1)
    Worst Case: O(n)

    Space Complexity:
    O(n)
*/