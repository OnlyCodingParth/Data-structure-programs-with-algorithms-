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
    // Doubly Linked List - Creation

    struct Node *head = NULL;
    struct Node *newNode;
    struct Node *temp;

    int n, i, value;

    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    // Important step - Create the doubly linked list
    for (i = 0; i < n; i++)
    {
        newNode = (struct Node *)malloc(sizeof(struct Node));

        printf("Enter the value: ");
        scanf("%d", &value);

        newNode->data = value;
        newNode->prev = NULL;
        newNode->next = NULL;

        if (head == NULL)
        {
            head = newNode;
        }
        else
        {
            temp = head;

            // Move to the last node
            while (temp->next != NULL)
            {
                temp = temp->next;
            }

            // Important step - Connect both directions
            temp->next = newNode;
            newNode->prev = temp;
        }
    }

    printf("\nDoubly Linked List:\n");

    temp = head;

    while (temp != NULL)
    {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }

    printf("NULL\n");

    return 0;
}

/*

Doubly Linked List - Creation

Definition:
A Doubly Linked List is a linked list in which each node
contains data and two pointers:

1. prev - points to the previous node.
2. next - points to the next node.

Node structure:

[ prev | data | next ]

Steps:

1. Create a new node.
2. Store the value in the node.
3. Set prev and next to NULL.
4. If the list is empty, make the node the head.
5. Otherwise, move to the last node.
6. Connect the last node to the new node using next.
7. Connect the new node back to the last node using prev.

Example:

NULL ← 10 ⇄ 20 ⇄ 30 → NULL

Time Complexity:
O(n²)

Space Complexity:
O(n)

*/