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
    // Circular Singly Linked List - Traversal

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

    printf("\nCircular Singly Linked List:\n");

    // Important step - Start traversal from head
    if (head != NULL)
    {
        temp = head;

        // Important step - Stop when temp reaches head again
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

Circular Singly Linked List - Traversal

Definition:
Traversal means visiting and displaying every node
of the circular singly linked list.

Important Point:
The last node points back to head, so there is no NULL
at the end of the list.

Steps:

1. Start from head.
2. Visit the current node.
3. Move to the next node.
4. Continue until the pointer reaches head again.

Important Logic:

temp = head;

do
{
    printf("%d -> ", temp->data);
    temp = temp->next;
}
while (temp != head);

Example:

Circular List:

10 → 20 → 30
↑         ↓
└─────────┘

Output:

10 -> 20 -> 30 -> (head)

Time Complexity:
O(n)

Space Complexity:
O(1) auxiliary space

*/