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
    // Circular Singly Linked List - Insertion at End

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

    printf("\nEnter the value to insert at end: ");
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

        // Important step - Connect last node to new node
        temp->next = newNode;

        // Important step - Connect new node back to head
        newNode->next = head;
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

Circular Singly Linked List - Insertion at End

Definition:
Insertion at end means adding a new node after the
current last node.

Steps:

1. Create a new node.
2. If the list is empty, make the new node the head
   and point it to itself.
3. Otherwise, move to the last node.
4. Connect the last node to the new node.
5. Connect the new node to head.

Important Logic:

while (temp->next != head)
{
    temp = temp->next;
}

temp->next = newNode;
newNode->next = head;

Example:

Before:

10 → 20 → 30
↑         ↓
└─────────┘

Insert 40

After:

10 → 20 → 30 → 40
↑              ↓
└──────────────┘

Time Complexity:
O(n)

Space Complexity:
O(1) auxiliary space

Note:
If a tail pointer is maintained, insertion at end
can be performed in O(1) time.

*/