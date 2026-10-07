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

    printf("Enter key to search: ");
    scanf("%d", &key);

    // Important step - Find index using hash function
    index = hashFunction(key);

    // Important step - Check whether key exists at calculated index
    if (hashTable[index] == key)
    {
        printf("Key %d found at index %d\n", key, index);
    }
    else
    {
        printf("Key %d not found\n", key);
    }

    return 0;
}

/*
    Theory:
    Searching in a hash table uses the hash function to find
    the expected position of a key.
    This avoids checking every element when there is no collision.

    Algorithm:
    1. Create the hash table with some keys.
    2. Take the key to be searched from the user.
    3. Calculate its index using the hash function.
    4. Check the value at the calculated index.
    5. If the value is equal to the key, display that the key is found.
    6. Otherwise, display that the key is not found.

    Time Complexity:
    Average Case: O(1)
    Worst Case: O(n) when collisions are present

    Space Complexity:
    O(n)
*/