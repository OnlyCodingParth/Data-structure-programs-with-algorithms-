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
    // Circular Doubly Linked List - Insertion at End

    struct Node *head = NULL;
    struct Node *newNode;
    struct Node *temp;
    struct Node *last;

    int n, i, value;

    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    // Important step - Create the existing circular doubly linked list
    for (i = 0; i < n; i++)
    {
        newNode = (struct Node *)malloc(sizeof(struct Node));

        printf("Enter the value: ");
        scanf("%d", &value);

        newNode->data = value;

        if (head == NULL)
        {
            head = newNode;

            newNode->prev = head;
            newNode->next = head;
        }
        else
        {
            temp = head;

            // Find the last node
            while (temp->next != head)
            {
                temp = temp->next;
            }

            newNode->prev = temp;
            newNode->next = head;

            temp->next = newNode;
            head->prev = newNode;
        }
    }

    printf("\nEnter the value to insert at end: ");
    scanf("%d", &value);

    // Create a new node
    newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = value;

    // Important step - Handle an empty list
    if (head == NULL)
    {
        head = newNode;

        newNode->prev = head;
        newNode->next = head;
    }
    else
    {
        // Important step - Get the last node directly
        last = head->prev;

        // Connect new node with last and head
        newNode->prev = last;
        newNode->next = head;

        // Connect last node with new node
        last->next = newNode;

        // Connect head back to new node
        head->prev = newNode;
    }

    printf("\nCircular Doubly Linked List after insertion:\n");

    temp = head;

    // Important step - Traverse until head is reached again
    do
    {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }
    while (temp != head);

    printf("(head)\n");

    return 0;
}

/*

Circular Doubly Linked List - Insertion at End

Definition:
Insertion at end means adding a new node after the
current last node.

Example:

Before:

10 ⇄ 20 ⇄ 30
↑             ↓
└─────────────┘

Insert 40.

After:

10 ⇄ 20 ⇄ 30 ⇄ 40
↑                   ↓
└───────────────────┘

Steps:

1. Create a new node.
2. If the list is empty:
   - Make the new node the head.
   - Make prev and next point to itself.
3. Otherwise:
   - Get the last node using head->prev.
   - Connect new node after the last node.
   - Connect new node to head.
   - Update head->prev.

Important Logic:

last = head->prev;

newNode->prev = last;
newNode->next = head;

last->next = newNode;
head->prev = newNode;

Time Complexity:
O(1)

Space Complexity:
O(1)

Note:
Because head->prev directly gives the last node,
insertion at end does not require traversal.
*/