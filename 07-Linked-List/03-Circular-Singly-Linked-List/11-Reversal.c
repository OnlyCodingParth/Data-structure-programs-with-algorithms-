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
    // Circular Singly Linked List - Reversal

    struct Node *head = NULL;
    struct Node *newNode;
    struct Node *temp;

    struct Node *previous;
    struct Node *current;
    struct Node *nextNode;
    struct Node *last;

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
        printf("\nList is empty. Reversal is not possible.\n");
        return 0;
    }

    // Important step - Handle the single-node case
    if (head->next != head)
    {
        previous = head;
        current = head->next;

        // Find the last node
        last = head;

        while (last->next != head)
        {
            last = last->next;
        }

        // Reverse the links
        while (current != head)
        {
            nextNode = current->next;
            current->next = previous;
            previous = current;
            current = nextNode;
        }

        // Important step - Make old head point to itself temporarily
        head->next = previous;

        // Important step - Make the last node the new head
        head = previous;
    }

    printf("\nCircular Singly Linked List after reversal:\n");

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

Circular Singly Linked List - Reversal

Definition:
Reversal means reversing the direction of all links
in the circular linked list.

Example:

Before:

10 → 20 → 30 → 40
↑                   ↓
└───────────────────┘

After:

40 → 30 → 20 → 10
↑                   ↓
└───────────────────┘

Steps:

1. Check if the list is empty.
2. If there is only one node, no reversal is needed.
3. Use three pointers:
   - previous
   - current
   - nextNode
4. Reverse the links one by one.
5. Make the old head point to the new head.
6. Make the last node the new head.

Important Logic:

nextNode = current->next;
current->next = previous;
previous = current;
current = nextNode;

Finally:

head->next = previous;
head = previous;

Time Complexity:
O(n)

Space Complexity:
O(1)

*/