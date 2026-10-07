#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node
{
    int data;
    struct Node *next;
};

int main()
{
    // Circular Singly Linked List - Searching

    struct Node *head = NULL;
    struct Node *newNode;
    struct Node *temp;

    int n, i, value;
    int searchValue;
    int position = 1;
    int found = 0;

    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    // Important step - Create the circular linked list
    for (i = 0; i < n; i++)
    {
        newNode = (struct Node *)malloc(sizeof(struct Node));

        printf("Enter the value: ");
        scanf("%d", &value);

        newNode->data = value;

        if (head == NULL)
        {
            head = newNode;
            newNode->next = head;
        }
        else
        {
            temp = head;

            // Important step - Move to the last node
            while (temp->next != head)
            {
                temp = temp->next;
            }

            temp->next = newNode;
            newNode->next = head;
        }
    }

    printf("\nEnter the value to search: ");
    scanf("%d", &searchValue);

    // Important step - Start searching from head
    if (head != NULL)
    {
        temp = head;

        // Important step - Stop when temp reaches head again
        do
        {
            if (temp->data == searchValue)
            {
                found = 1;
                break;
            }

            temp = temp->next;
            position++;
        }
        while (temp != head);
    }

    if (found == 1)
    {
        printf("\nValue found at position %d.\n", position);
    }
    else
    {
        printf("\nValue not found.\n");
    }

    return 0;
}

/*

Circular Singly Linked List - Searching

Definition:
Searching means finding a particular value in the
circular singly linked list.

Steps:

1. Start from head.
2. Compare the current node's data with the search value.
3. If the value is found, display its position.
4. Otherwise, move to the next node.
5. Stop when the pointer reaches head again.

Important Logic:

temp = head;

do
{
    if (temp->data == searchValue)
    {
        found = 1;
        break;
    }

    temp = temp->next;
    position++;
}
while (temp != head);

Example:

Circular List:

10 → 20 → 30 → 40
↑              ↓
└──────────────┘

Search: 30

Output:
Value found at position 3.

Time Complexity:
Best Case: O(1)
Average Case: O(n)
Worst Case: O(n)

Space Complexity:
O(1) auxiliary space

*/