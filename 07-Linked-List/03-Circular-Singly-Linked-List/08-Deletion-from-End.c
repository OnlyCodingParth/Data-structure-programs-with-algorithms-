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
    // Circular Singly Linked List - Deletion from End

    struct Node *head = NULL;
    struct Node *newNode;
    struct Node *temp;
    struct Node *previous;

    int n, i, value;

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

    // Important step - Handle the single-node case
    if (head->next == head)
    {
        free(head);
        head = NULL;
    }
    else
    {
        temp = head;

        // Important step - Find the last node
        while (temp->next != head)
        {
            previous = temp;
            temp = temp->next;
        }

        // Connect the previous node to head
        previous->next = head;

        // Delete the last node
        free(temp);
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

Circular Singly Linked List - Deletion from End

Definition:
Deletion from end means removing the last node of the
circular linked list.

Cases:

1. Empty list:
   Deletion is not possible.

2. Only one node:
   Delete the node and make head NULL.

3. More than one node:
   - Find the last node.
   - Keep track of the node before it.
   - Connect the previous node to head.
   - Delete the last node.

Important Logic:

while (temp->next != head)
{
    previous = temp;
    temp = temp->next;
}

previous->next = head;
free(temp);

Example:

Before:

10 → 20 → 30 → 40
↑                   ↓
└───────────────────┘

After deleting 40:

10 → 20 → 30
↑         ↓
└─────────┘

Time Complexity:
O(n)

Space Complexity:
O(1)

Note:
With a tail pointer, deletion from end is still O(n)
in a circular singly linked list because we need to find
the node before the last node.
*/