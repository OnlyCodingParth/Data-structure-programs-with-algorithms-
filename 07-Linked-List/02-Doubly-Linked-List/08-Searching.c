#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node
{
    struct Node *prev;
    int data;
    struct Node *next;
};

int main()
{
    // Doubly Linked List - Searching

    struct Node *head = NULL;
    struct Node *newNode;
    struct Node *temp;

    int n, i, value, searchValue;
    int position = 1;
    int found = 0;

    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    // Important step - Create the doubly linked list
    for (i = 0; i < n; i++)
    {
        newNode = (struct Node *)malloc(sizeof(struct Node));

        printf("Enter the value: ");
        scanf("%d", &value);

        newNode->data = value;
        newNode->prev = NULL;
        newNode->next = NULL;

        if (head == NULL)
        {
            head = newNode;
        }
        else
        {
            temp = head;

            while (temp->next != NULL)
            {
                temp = temp->next;
            }

            // Important step - Connect both directions
            temp->next = newNode;
            newNode->prev = temp;
        }
    }

    printf("\nEnter the value to search: ");
    scanf("%d", &searchValue);

    temp = head;

    // Important step - Search each node from beginning
    while (temp != NULL)
    {
        if (temp->data == searchValue)
        {
            found = 1;
            break;
        }

        temp = temp->next;
        position++;
    }

    if (found == 1)
    {
        printf("Value found at position %d\n", position);
    }
    else
    {
        printf("Value not found\n");
    }

    return 0;
}

/*

Doubly Linked List - Searching

Definition:
Searching means finding a particular value in the
linked list.

Steps:

1. Start from the head.
2. Compare the current node's data with the search value.
3. If the values are equal, the value is found.
4. Otherwise, move to the next node.
5. Continue until the value is found or NULL is reached.

Important Logic:

while (temp != NULL)
{
    if (temp->data == searchValue)
    {
        found = 1;
        break;
    }

    temp = temp->next;
}

Example:

NULL ← 10 ⇄ 20 ⇄ 30 ⇄ 40 → NULL

Search: 30

Output:
Value found at position 3

Time Complexity:
Best Case: O(1)
Average Case: O(n)
Worst Case: O(n)

Space Complexity:
O(1)

*/