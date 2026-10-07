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
    // Circular Singly Linked List - Updation

    struct Node *head = NULL;
    struct Node *newNode;
    struct Node *temp;

    int n, i, value;
    int pos, newValue;

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
        printf("\nList is empty. Updation is not possible.\n");
        return 0;
    }

    printf("\nEnter the position to update: ");
    scanf("%d", &pos);

    printf("Enter the new value: ");
    scanf("%d", &newValue);

    temp = head;

    // Important step - Move to the required position
    for (i = 1; i < pos; i++)
    {
        temp = temp->next;

        // Position is invalid if we reach head again
        if (temp == head)
        {
            printf("Invalid position.\n");
            return 0;
        }
    }

    // Important step - Update the data
    temp->data = newValue;

    printf("\nCircular Singly Linked List after updation:\n");

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

Circular Singly Linked List - Updation

Definition:
Updation means changing the data of a node at a
specific position.

Steps:

1. Create the circular linked list.
2. Take the position from the user.
3. Take the new value.
4. Start from head.
5. Move to the required position.
6. Replace the old data with the new data.

Important Logic:

temp->data = newValue;

Example:

Before:

10 → 20 → 30 → 40
↑                   ↓
└───────────────────┘

Update position 3 with 35.

After:

10 → 20 → 35 → 40
↑                   ↓
└───────────────────┘

Time Complexity:
O(n)

Space Complexity:
O(1)

*/