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
    // Doubly Linked List - Insertion at Position

    struct Node *head = NULL;
    struct Node *newNode;
    struct Node *temp;

    int n, i, value, pos;

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

    printf("\nEnter the position: ");
    scanf("%d", &pos);

    printf("Enter the value to insert: ");
    scanf("%d", &value);

    // Important step - Check whether position is valid
    if (pos < 1 || pos > n + 1)
    {
        printf("\nInvalid position!\n");
        return 0;
    }

    // Create a new node
    newNode = (struct Node *)malloc(sizeof(struct Node));

    newNode->data = value;
    newNode->prev = NULL;
    newNode->next = NULL;

    // Important step - Insert at beginning
    if (pos == 1)
    {
        newNode->next = head;

        if (head != NULL)
        {
            head->prev = newNode;
        }

        head = newNode;
    }
    else
    {
        temp = head;

        // Important step - Move to the node before the position
        for (i = 1; i < pos - 1; i++)
        {
            temp = temp->next;
        }

        // Important step - Connect new node with both sides
        newNode->next = temp->next;
        newNode->prev = temp;

        // Important step - Update previous link of next node
        if (temp->next != NULL)
        {
            temp->next->prev = newNode;
        }

        // Important step - Update next link of previous node
        temp->next = newNode;
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

Doubly Linked List - Insertion at Position

Definition:
Insertion at position means adding a new node at a
specific position in the doubly linked list.

Steps:

1. Create a new node.
2. Store the value in the new node.
3. Check whether the position is valid.
4. If position is 1, insert the node at the beginning.
5. Otherwise, move to the node before the required position.
6. Connect the new node with the previous node using prev.
7. Connect the new node with the next node using next.
8. Update the links of the surrounding nodes.

Important Logic:

newNode->next = temp->next;
newNode->prev = temp;

if (temp->next != NULL)
{
    temp->next->prev = newNode;
}

temp->next = newNode;

Example:

Before:
NULL ← 10 ⇄ 20 ⇄ 30 → NULL

Insert 25 at position 3

After:
NULL ← 10 ⇄ 20 ⇄ 25 ⇄ 30 → NULL

Time Complexity:
O(n)

Space Complexity:
O(1) auxiliary space

*/