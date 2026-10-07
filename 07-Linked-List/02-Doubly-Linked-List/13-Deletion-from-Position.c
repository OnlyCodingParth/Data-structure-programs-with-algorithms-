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
    // Doubly Linked List - Deletion from Position

    struct Node *head = NULL;
    struct Node *newNode;
    struct Node *temp;
    struct Node *deleteNode;

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

    // Important step - Check whether the list is empty
    if (head == NULL)
    {
        printf("\nLinked List is empty.\n");
        return 0;
    }

    printf("\nEnter the position to delete: ");
    scanf("%d", &pos);

    // Important step - Check whether position is valid
    if (pos < 1 || pos > n)
    {
        printf("\nInvalid position!\n");
        return 0;
    }

    // Important step - Delete the first node
    if (pos == 1)
    {
        deleteNode = head;
        head = head->next;

        if (head != NULL)
        {
            head->prev = NULL;
        }

        free(deleteNode);
    }
    else
    {
        temp = head;

        // Important step - Move to the node at the required position
        for (i = 1; i < pos; i++)
        {
            temp = temp->next;
        }

        deleteNode = temp;

        // Important step - Connect previous node to next node
        temp->prev->next = temp->next;

        // Important step - Connect next node back to previous node
        if (temp->next != NULL)
        {
            temp->next->prev = temp->prev;
        }

        // Important step - Free the deleted node
        free(deleteNode);
    }

    printf("\nDoubly Linked List after deletion:\n");

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

Doubly Linked List - Deletion from Position

Definition:
Deletion from position means removing a node from a
specific position in the doubly linked list.

Steps:

1. Check whether the list is empty.
2. Check whether the position is valid.
3. If position is 1, delete the first node.
4. Otherwise, move to the required node.
5. Connect its previous node to its next node.
6. Connect its next node back to its previous node.
7. Free the deleted node.

Important Logic:

temp->prev->next = temp->next;

if (temp->next != NULL)
{
    temp->next->prev = temp->prev;
}

free(temp);

Example:

Before:
NULL ← 10 ⇄ 20 ⇄ 30 ⇄ 40 → NULL

Delete position 3 (30)

After:
NULL ← 10 ⇄ 20 ⇄ 40 → NULL

Time Complexity:
O(n)

Space Complexity:
O(1) auxiliary space

*/