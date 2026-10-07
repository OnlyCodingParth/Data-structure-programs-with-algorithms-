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
    // Circular Doubly Linked List - Creation

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

        // Important step - First node
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

            // Connect new node with last node
            newNode->prev = temp;
            newNode->next = head;

            // Connect last node with new node
            temp->next = newNode;

            // Connect head back to new node
            head->prev = newNode;
        }
    }

    printf("\nCircular Doubly Linked List:\n");

    if (head == NULL)
    {
        printf("List is empty.\n");
    }
    else
    {
        temp = head;

        // Important step - Traverse until head is reached again
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

Circular Doubly Linked List - Creation

Definition:
A Circular Doubly Linked List is a linked list in which
each node has two pointers:

1. prev - points to the previous node.
2. next - points to the next node.

The last node points to the first node and the first
node points back to the last node.

Structure:

        ┌─────────────────────────────┐
        ↓                             │
10 ⇄ 20 ⇄ 30 ⇄ 40
↑                   ↓
└───────────────────┘

Important Conditions:

head->prev = last;
last->next = head;

For the first node:

newNode->prev = head;
newNode->next = head;

Steps:

1. Create a new node.
2. If the list is empty:
   - Make the new node the head.
   - Make both prev and next point to head.
3. Otherwise:
   - Find the last node.
   - Connect the new node after the last node.
   - Connect the new node back to head.
   - Update head->prev.

Time Complexity:
O(n²)

Space Complexity:
O(n)

Note:
The creation implementation searches for the last node
for every new node. With a tail pointer, creation can
be performed in O(n) overall.
*/