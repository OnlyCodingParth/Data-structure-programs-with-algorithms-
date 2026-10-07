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
    // Circular Doubly Linked List - Forward Traversal

    struct Node *head = NULL;
    struct Node *newNode;
    struct Node *temp;

    int n, i, value;

    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    // Important step - Create the circular doubly linked list
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

            // Move to the last node
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

    printf("\nCircular Doubly Linked List (Forward):\n");

    if (head == NULL)
    {
        printf("List is empty.\n");
    }
    else
    {
        temp = head;

        // Important step - Traverse using next pointer
        do
        {
            printf("%d <-> ", temp->data);
            temp = temp->next;
        }
        while (temp != head);

        printf("(head)\n");
    }

    return 0;
}

/*

Circular Doubly Linked List - Forward Traversal

Definition:
Forward traversal means visiting every node from head
towards the last node using the next pointer.

Example:

10 ⇄ 20 ⇄ 30 ⇄ 40
↑                   ↓
└───────────────────┘

Steps:

1. Start from head.
2. Print the current node.
3. Move using temp->next.
4. Stop when temp becomes head again.

Important Logic:

temp = head;

do
{
    printf("%d", temp->data);
    temp = temp->next;
}
while (temp != head);

Unlike a normal doubly linked list, we do not stop at NULL
because the list is circular.

Time Complexity:
O(n)

Space Complexity:
O(1)

*/