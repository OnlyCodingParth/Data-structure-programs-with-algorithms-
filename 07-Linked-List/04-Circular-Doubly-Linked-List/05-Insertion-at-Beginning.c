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
    // Circular Doubly Linked List - Insertion at Beginning

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

    printf("\nEnter the value to insert at beginning: ");
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
        // Important step - Find the last node
        last = head->prev;

        // Connect new node with old head
        newNode->next = head;
        newNode->prev = last;

        // Connect last node with new node
        last->next = newNode;

        // Connect old head back to new node
        head->prev = newNode;

        // Important step - Make new node the head
        head = newNode;
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

Circular Doubly Linked List - Insertion at Beginning

Definition:
Insertion at beginning means adding a new node before
the current head.

Example:

Before:

10 ⇄ 20 ⇄ 30
↑             ↓
└─────────────┘

Insert 5.

After:

5 ⇄ 10 ⇄ 20 ⇄ 30
↑                 ↓
└─────────────────┘

Steps:

1. Create a new node.
2. If the list is empty:
   - Make the new node the head.
   - Make prev and next point to itself.
3. Otherwise:
   - Find the last node using head->prev.
   - Connect new node between last and head.
   - Update head.
4. Make the new node the new head.

Important Logic:

last = head->prev;

newNode->next = head;
newNode->prev = last;

last->next = newNode;
head->prev = newNode;

head = newNode;

Time Complexity:
O(1)

Space Complexity:
O(1)

Note:
In a circular doubly linked list, the last node can be
directly accessed using head->prev. Therefore, unlike a
circular singly linked list, we do not need to traverse
to find the last node.
*/