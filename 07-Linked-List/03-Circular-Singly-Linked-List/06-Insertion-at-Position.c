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
    // Circular Singly Linked List - Insertion at Position

    struct Node *head = NULL;
    struct Node *newNode;
    struct Node *temp;

    int n, i, value, pos;

    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    // Important step - Create the existing circular linked list
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

            while (temp->next != head)
            {
                temp = temp->next;
            }

            temp->next = newNode;
            newNode->next = head;
        }
    }

    printf("\nEnter the value to insert: ");
    scanf("%d", &value);

    printf("Enter the position: ");
    scanf("%d", &pos);

    // Create a new node
    newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = value;

    // Important step - Insert at beginning
    if (pos == 1)
    {
        temp = head;

        // Find the last node
        while (temp->next != head)
        {
            temp = temp->next;
        }

        newNode->next = head;
        temp->next = newNode;
        head = newNode;
    }
    else
    {
        temp = head;

        // Move to the node just before the required position
        for (i = 1; i < pos - 1; i++)
        {
            temp = temp->next;

            // Position is invalid if we reach head again
            if (temp == head)
            {
                printf("Invalid position.\n");
                free(newNode);
                return 0;
            }
        }

        // Important step - Insert the new node
        newNode->next = temp->next;
        temp->next = newNode;
    }

    printf("\nCircular Singly Linked List after insertion:\n");

    temp = head;

    // Important step - Traverse until head is reached again
    do
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    while (temp != head);

    printf("(head)\n");

    return 0;
}

/*

Circular Singly Linked List - Insertion at Position

Definition:
Insertion at position means adding a new node at a
specific position in the circular linked list.

Steps:

1. Create a new node.
2. Take the position from the user.
3. If position is 1:
   - Find the last node.
   - Connect new node to head.
   - Connect last node to new node.
   - Make new node the new head.
4. Otherwise:
   - Move to the node just before the required position.
   - Connect new node to the next node.
   - Connect previous node to new node.

Important Logic:

newNode->next = temp->next;
temp->next = newNode;

Example:

Before:

10 → 20 → 30 → 40
↑              ↓
└──────────────┘

Insert 25 at position 3:

10 → 20 → 25 → 30 → 40
↑                   ↓
└───────────────────┘

Time Complexity:
O(n)

Space Complexity:
O(1) auxiliary space

*/