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
    // Circular Singly Linked List - Insertion at Beginning

    struct Node *head = NULL;
    struct Node *newNode;
    struct Node *temp;

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

            // Important step - Move to the last node
            while (temp->next != head)
            {
                temp = temp->next;
            }

            temp->next = newNode;
            newNode->next = head;
        }
    }

    printf("\nEnter the value to insert at beginning: ");
    scanf("%d", &value);

    // Create a new node
    newNode = (struct Node *)malloc(sizeof(struct Node));

    newNode->data = value;

    // Important step - Handle an empty list
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

        // Important step - Connect new node to old head
        newNode->next = head;

        // Important step - Last node points to new head
        temp->next = newNode;

        // Important step - Update head
        head = newNode;
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

Circular Singly Linked List - Insertion at Beginning

Definition:
Insertion at beginning means adding a new node before
the current first node.

Steps:

1. Create a new node.
2. If the list is empty, make the new node the head
   and point it to itself.
3. Otherwise, find the last node.
4. Make the new node point to the current head.
5. Make the last node point to the new node.
6. Update head to the new node.

Important Logic:

newNode->next = head;
temp->next = newNode;
head = newNode;

Example:

Before:

10 → 20 → 30
↑         ↓
└─────────┘

Insert 5

After:

5 → 10 → 20 → 30
↑              ↓
└──────────────┘

Time Complexity:
O(n)

Space Complexity:
O(1) auxiliary space

Note:
If a tail pointer is maintained, insertion at beginning
can be performed in O(1) time.

*/