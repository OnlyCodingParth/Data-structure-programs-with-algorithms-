#include <stdio.h>

#define SIZE 10

// Important step - First hash function
int hashFunction1(int key)
{
    return key % SIZE;
}

// Important step - Second hash function
int hashFunction2(int key)
{
    return 7 - (key % 7);
}

int main()
{
    int hashTable[SIZE];
    int key;
    int index;
    int step;
    int newIndex;
    int i;

    // Initialize hash table
    for (i = 0; i < SIZE; i++)
    {
        hashTable[i] = -1;
    }

    printf("Enter key to insert: ");
    scanf("%d", &key);

    // Important step - Calculate first hash value
    index = hashFunction1(key);

    // Important step - Calculate step size using second hash function
    step = hashFunction2(key);

    // Important step - Double hashing
    i = 0;

    while (i < SIZE)
    {
        newIndex = (index + i * step) % SIZE;

        if (hashTable[newIndex] == -1)
        {
            // Important step - Insert key at empty position
            hashTable[newIndex] = key;

            printf("Key %d inserted at index %d\n", key, newIndex);
            break;
        }

        i++;
    }

    if (i == SIZE)
    {
        printf("Hash table is full. Key cannot be inserted.\n");
    }

    printf("\nHash Table:\n");

    for (i = 0; i < SIZE; i++)
    {
        printf("Index %d = %d\n", i, hashTable[i]);
    }

    return 0;
}

/*
    Theory:
    Double Hashing is a collision resolution technique that uses
    two hash functions.

    The first hash function determines the initial index.
    The second hash function determines the step size.

    Formula:
    New Index = (Hash1(key) + i * Hash2(key)) % SIZE

    Algorithm:
    1. Create the hash table.
    2. Initialize all positions with -1.
    3. Take a key from the user.
    4. Calculate the first hash value.
    5. Calculate the second hash value.
    6. Set i = 0.
    7. Calculate the new index using the double hashing formula.
    8. If the position is empty, insert the key.
    9. If the position is occupied, increment i.
    10. Repeat until an empty position is found or the table is full.
    11. Display the hash table.

    Time Complexity:
    Average Case: O(1)
    Worst Case: O(n)

    Space Complexity:
    O(n)
*/