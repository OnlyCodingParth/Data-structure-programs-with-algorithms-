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
    // Circular Singly Linked List - Deletion from Position

    struct Node *head = NULL;
    struct Node *newNode;
    struct Node *temp;
    struct Node *previous;

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

    // Important step - Check if the list is empty
    if (head == NULL)
    {
        printf("\nList is empty. Deletion is not possible.\n");
        return 0;
    }

    printf("\nEnter the position to delete: ");
    scanf("%d", &pos);

    // Important step - Delete the first node
    if (pos == 1)
    {
        // Handle the single-node case
        if (head->next == head)
        {
            free(head);
            head = NULL;
        }
        else
        {
            temp = head;

            // Find the last node
            while (temp->next != head)
            {
                temp = temp->next;
            }

            // Store old head
            previous = head;

            // Move head to the next node
            head = head->next;

            // Important step - Connect last node to new head
            temp->next = head;

            // Delete old head
            free(previous);
        }
    }
    else
    {
        temp = head;

        // Move to the node before the position
        for (i = 1; i < pos - 1; i++)
        {
            temp = temp->next;

            // Position is invalid if we reach head again
            if (temp == head)
            {
                printf("Invalid position.\n");
                return 0;
            }
        }

        // Store the node to be deleted
        previous = temp->next;

        // Important step - Skip the node to be deleted
        temp->next = previous->next;

        // Delete the node
        free(previous);
    }

    printf("\nCircular Singly Linked List after deletion:\n");

    if (head == NULL)
    {
        printf("List is empty.\n");
    }
    else
    {
        temp = head;

        // Important step - Traverse until head is reached again
        do
        {
            printf("%d -> ", temp->data);
            temp = temp->next;
        }
        while (temp != head);

        printf("(head)\n");
    }

    return 0;
}

/*

Circular Singly Linked List - Deletion from Position

Definition:
Deletion from position means removing a node from a
specific position in the circular linked list.

Steps:

1. Check whether the list is empty.
2. Take the position from the user.
3. If position is 1:
   - Handle the single-node case.
   - Otherwise find the last node.
   - Move head to the second node.
   - Connect the last node to the new head.
   - Delete the old head.
4. For other positions:
   - Move to the node before the required position.
   - Store the node to be deleted.
   - Skip that node.
   - Free the deleted node.

Important Logic:

previous = temp->next;
temp->next = previous->next;
free(previous);

Example:

Before:

10 → 20 → 30 → 40
↑                   ↓
└───────────────────┘

Delete position 3:

10 → 20 → 40
↑         ↓
└─────────┘

Time Complexity:
O(n)

Space Complexity:
O(1)

*/