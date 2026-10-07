#include <stdio.h>

#define SIZE 10

int main()
{
    int hashTable[SIZE];
    int i;

    // Initialize all positions with -1
    for (i = 0; i < SIZE; i++)
    {
        hashTable[i] = -1;
    }

    printf("Hash Table:\n");

    for (i = 0; i < SIZE; i++)
    {
        printf("Index %d = %d\n", i, hashTable[i]);
    }

    return 0;
}

/*
    Theory:
    A hash table is a data structure that stores data using an index.
    The table is usually implemented using an array.
    Each position of the array represents an index in the hash table.

    Algorithm:
    1. Create an array of fixed size.
    2. Initialize all positions with -1 to represent empty positions.
    3. Display all positions of the hash table.

    Time Complexity:
    O(n)

    Space Complexity:
    O(n)
*/