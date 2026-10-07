#include <stdio.h>

#define SIZE 10

// Important step - Hash function
int hashFunction(int key)
{
    return key % SIZE;
}

int main()
{
    int key;
    int index;

    printf("Enter a key: ");
    scanf("%d", &key);

    index = hashFunction(key);

    printf("Key = %d\n", key);
    printf("Hash Index = %d\n", index);

    return 0;
}

/*
    Theory:
    A hash function converts a key into an index of the hash table.
    In this program, the modulo operator is used.

    Formula:
    Hash Index = Key % Table Size

    Algorithm:
    1. Take a key from the user.
    2. Pass the key to the hash function.
    3. Calculate the index using key % SIZE.
    4. Display the calculated hash index.

    Time Complexity:
    O(1)

    Space Complexity:
    O(1)
*/