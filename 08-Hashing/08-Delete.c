#include <stdio.h>

#define SIZE 10

// Important step - Hash function
int hashFunction(int key)
{
    return key % SIZE;
}

int main()
{
    int hashTable[SIZE] = { -1, -1, -1, -1, -1, 25, -1, 37, -1, -1 };

    int key;
    int index;

    printf("Enter key to delete: ");
    scanf("%d", &key);

    // Important step - Find index using hash function
    index = hashFunction(key);

    // Important step - Check whether key exists
    if (hashTable[index] == key)
    {
        // Important step - Delete key by marking the position as empty
        hashTable[index] = -1;

        printf("Key %d deleted successfully\n", key);
    }
    else
    {
        printf("Key %d not found\n", key);
    }

    printf("\nHash Table:\n");

    for (int i = 0; i < SIZE; i++)
    {
        printf("Index %d = %d\n", i, hashTable[i]);
    }

    return 0;
}

/*
    Theory:
    Deletion means removing a key from the hash table.
    In this basic implementation, the key is replaced with -1
    to indicate that the position is empty.

    Algorithm:
    1. Create the hash table with some keys.
    2. Take the key to be deleted from the user.
    3. Calculate its index using the hash function.
    4. Check whether the key exists at that index.
    5. If the key is found, replace it with -1.
    6. Display the updated hash table.

    Time Complexity:
    Average Case: O(1)
    Worst Case: O(n) when collision handling is required

    Space Complexity:
    O(n)
*/