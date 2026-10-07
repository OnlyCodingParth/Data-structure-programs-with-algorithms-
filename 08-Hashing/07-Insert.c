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

    printf("Enter a key: ");
    scanf("%d", &key);

    // Important step - Find index using hash function
    index = hashFunction(key);

    // Important step - Insert key at calculated index
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
    Insertion means storing a key in the hash table.
    The hash function is used to find the position where the key should be stored.
    This basic program assumes that the calculated position is empty.

    Algorithm:
    1. Create the hash table.
    2. Initialize all positions with -1.
    3. Take a key from the user.
    4. Calculate the index using the hash function.
    5. Store the key at the calculated index.
    6. Display the hash table.

    Time Complexity:
    Average Case: O(1)
    Worst Case: O(1) for this basic implementation

    Space Complexity:
    O(n)
*/