#include <stdio.h>
#include <stdlib.h>

#define SIZE 10

struct Node
{
    int data;
    struct Node *next;
};

// Important step - Hash function
int hashFunction(int key)
{
    return key % SIZE;
}

// Important step - Insert key into the linked list
void insert(struct Node *hashTable[], int key)
{
    int index;
    struct Node *newNode;

    index = hashFunction(key);

    newNode = (struct Node *)malloc(sizeof(struct Node));

    newNode->data = key;
    newNode->next = hashTable[index];

    hashTable[index] = newNode;
}

// Important step - Display hash table
void display(struct Node *hashTable[])
{
    int i;
    struct Node *temp;

    for (i = 0; i < SIZE; i++)
    {
        printf("Index %d: ", i);

        temp = hashTable[i];

        while (temp != NULL)
        {
            printf("%d -> ", temp->data);
            temp = temp->next;
        }

        printf("NULL\n");
    }
}

int main()
{
    struct Node *hashTable[SIZE];
    int key;
    int n;
    int i;

    // Initialize all linked lists as empty
    for (i = 0; i < SIZE; i++)
    {
        hashTable[i] = NULL;
    }

    printf("Enter number of keys: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        printf("Enter key %d: ", i + 1);
        scanf("%d", &key);

        insert(hashTable, key);
    }

    printf("\nHash Table using Chaining:\n");

    display(hashTable);

    return 0;
}

/*
    Theory:
    Chaining is a collision resolution technique used in hashing.
    In chaining, every index of the hash table can contain a linked list.

    If multiple keys have the same hash index, they are stored
    in the linked list at that index.

    Example:
    25 % 10 = 5
    35 % 10 = 5
    45 % 10 = 5

    Therefore:

    Index 5: 45 -> 35 -> 25 -> NULL

    Algorithm:
    1. Create an array of linked-list pointers.
    2. Initialize every position with NULL.
    3. Take keys from the user.
    4. Calculate the hash index for each key.
    5. Create a new node for the key.
    6. Insert the new node into the linked list at that index.
    7. Repeat for all keys.
    8. Traverse every linked list and display the hash table.

    Time Complexity:
    Average Case Insertion: O(1)
    Average Case Search: O(1)
    Worst Case: O(n)

    Space Complexity:
    O(n)
*/