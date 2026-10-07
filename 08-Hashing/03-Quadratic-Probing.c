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
    int newIndex;
    int i = 0;

    // Initialize hash table
    for (i = 0; i < SIZE; i++)
    {
        hashTable[i] = -1;
    }

    printf("Enter key to insert: ");
    scanf("%d", &key);

    // Important step - Find initial index
    index = hashFunction(key);

    // Important step - Quadratic probing
    i = 0;

    while (i < SIZE)
    {
        newIndex = (index + i * i) % SIZE;

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
    Quadratic Probing is a collision resolution technique.
    When a collision occurs, instead of checking the next position
    one by one, it checks positions using quadratic increments.

    Formula:
    New Index = (Index + i²) % SIZE

    where i = 0, 1, 2, 3, ...

    Algorithm:
    1. Create the hash table.
    2. Initialize all positions with -1.
    3. Take a key from the user.
    4. Calculate the initial index using the hash function.
    5. Set i = 0.
    6. Calculate the new index using (index + i²) % SIZE.
    7. If the position is empty, insert the key.
    8. If the position is occupied, increment i.
    9. Repeat until an empty position is found or the table is full.
    10. Display the hash table.

    Time Complexity:
    Average Case: O(1)
    Worst Case: O(n)

    Space Complexity:
    O(n)
*/