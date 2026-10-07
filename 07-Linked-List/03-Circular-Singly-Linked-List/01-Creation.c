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
    // Circular Singly Linked List - Creation

    struct Node *head = NULL;
    struct Node *newNode;
    struct Node *temp;

    int n, i, value;

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

            // Important step - First node points to itself
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

            // Important step - Connect last node to new node
            temp->next = newNode;

            // Important step - Connect new node back to head
            newNode->next = head;
        }
    }

    printf("\nCircular Singly Linked List:\n");

    if (head != NULL)
    {
        temp = head;

        // Important step - Stop when we reach head again
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

Circular Singly Linked List - Creation

Definition:
A Circular Singly Linked List is a linked list in which
the last node points back to the first node instead of
pointing to NULL.

Structure:

head
 ↓
10 → 20 → 30
↑         ↓
└─────────┘

Steps:

1. Create a new node.
2. If the list is empty, make the new node the head.
3. Make the first node point to itself.
4. Otherwise, move to the last node.
5. Connect the last node to the new node.
6. Connect the new node back to head.

Important Logic:

while (temp->next != head)
{
    temp = temp->next;
}

temp->next = newNode;
newNode->next = head;

Traversal:

A circular linked list does not end with NULL.
Therefore, traversal stops when the pointer reaches head again.

Example:

10 → 20 → 30
↑         ↓
└─────────┘

Time Complexity:
O(n²)

Space Complexity:
O(n)

*/