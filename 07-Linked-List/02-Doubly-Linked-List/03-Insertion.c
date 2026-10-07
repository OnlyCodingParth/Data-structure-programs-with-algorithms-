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
    // Doubly Linked List - Insertion at Beginning

    struct Node *head = NULL;
    struct Node *newNode;
    struct Node *temp;

    int n, i, value;

    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    // Important step - Create the existing doubly linked list
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

            while (temp->next != NULL)
            {
                temp = temp->next;
            }

            temp->next = newNode;
            newNode->prev = temp;
        }
    }

    printf("\nEnter the value to insert at beginning: ");
    scanf("%d", &value);

    // Create a new node
    newNode = (struct Node *)malloc(sizeof(struct Node));

    newNode->data = value;
    newNode->prev = NULL;

    // Important step - Connect new node to the current first node
    newNode->next = head;

    // Important step - Connect old first node back to new node
    if (head != NULL)
    {
        head->prev = newNode;
    }

    // Important step - Make new node the new head
    head = newNode;

    printf("\nDoubly Linked List after insertion:\n");

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

Doubly Linked List - Insertion at Beginning

Definition:
Insertion at beginning means adding a new node before
the current first node.

Steps:

1. Create a new node.
2. Store the value in the new node.
3. Set newNode->prev = NULL.
4. Connect newNode->next to head.
5. If the list is not empty, connect head->prev to newNode.
6. Make newNode the new head.

Important Logic:

newNode->next = head;

if (head != NULL)
{
    head->prev = newNode;
}

head = newNode;

Example:

Before:
NULL ← 10 ⇄ 20 ⇄ 30 → NULL

Insert 5

After:
NULL ← 5 ⇄ 10 ⇄ 20 ⇄ 30 → NULL

Time Complexity:
O(1)

Space Complexity:
O(1) auxiliary space

*/