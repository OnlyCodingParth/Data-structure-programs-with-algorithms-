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
    // Circular Doubly Linked List - Backward Traversal

    struct Node *head = NULL;
    struct Node *newNode;
    struct Node *temp;
    struct Node *last;

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

    printf("\nCircular Doubly Linked List (Backward):\n");

    if (head == NULL)
    {
        printf("List is empty.\n");
    }
    else
    {
        // Important step - Start from the last node
        last = head->prev;
        temp = last;

        // Important step - Traverse using prev pointer
        do
        {
            printf("%d <-> ", temp->data);
            temp = temp->prev;
        }
        while (temp != last);

        printf("(last)\n");
    }

    return 0;
}

/*

Circular Doubly Linked List - Backward Traversal

Definition:
Backward traversal means visiting every node from the
last node towards the first node using the prev pointer.

Example:

Forward:

10 ⇄ 20 ⇄ 30 ⇄ 40
↑                   ↓
└───────────────────┘

Backward:

40 ⇄ 30 ⇄ 20 ⇄ 10

Steps:

1. Find the last node using:
   
   last = head->prev;

2. Start from the last node.
3. Print the current node.
4. Move using temp->prev.
5. Stop when temp reaches the last node again.

Important Logic:

last = head->prev;
temp = last;

do
{
    printf("%d", temp->data);
    temp = temp->prev;
}
while (temp != last);

Because the list is circular, traversal does not stop at NULL.

Time Complexity:
O(n)

Space Complexity:
O(1)

*/