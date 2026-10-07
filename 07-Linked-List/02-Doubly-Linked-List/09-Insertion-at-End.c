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
    // Doubly Linked List - Insertion at End

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

    printf("\nEnter the value to insert at end: ");
    scanf("%d", &value);

    // Create a new node
    newNode = (struct Node *)malloc(sizeof(struct Node));

    newNode->data = value;
    newNode->next = NULL;

    // Important step - Handle an empty linked list
    if (head == NULL)
    {
        newNode->prev = NULL;
        head = newNode;
    }
    else
    {
        temp = head;

        // Important step - Move to the last node
        while (temp->next != NULL)
        {
            temp = temp->next;
        }

        // Important step - Connect the last node to new node
        temp->next = newNode;

        // Important step - Connect new node back to last node
        newNode->prev = temp;
    }

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

Doubly Linked List - Insertion at End

Definition:
Insertion at end means adding a new node after the
current last node.

Steps:

1. Create a new node.
2. Store the value in the new node.
3. Set newNode->next = NULL.
4. If the list is empty, make newNode the head.
5. Otherwise, move to the last node.
6. Connect the last node to newNode using next.
7. Connect newNode back to the last node using prev.

Important Logic:

while (temp->next != NULL)
{
    temp = temp->next;
}

temp->next = newNode;
newNode->prev = temp;

Example:

Before:
NULL ← 10 ⇄ 20 ⇄ 30 → NULL

Insert 40

After:
NULL ← 10 ⇄ 20 ⇄ 30 ⇄ 40 → NULL

Time Complexity:
O(n)

Space Complexity:
O(1) auxiliary space

*/