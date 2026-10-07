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
    // Singly Linked List - Deletion from Position

    struct Node *head = NULL;
    struct Node *newNode;
    struct Node *temp;
    struct Node *prev;

    int n, i, value, pos;

    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    // Important step - Create the existing linked list
    for (i = 0; i < n; i++)
    {
        newNode = (struct Node *)malloc(sizeof(struct Node));

        printf("Enter the value: ");
        scanf("%d", &value);

        newNode->data = value;
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
        }
    }

    printf("\nOriginal Linked List:\n");

    temp = head;

    while (temp != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }

    printf("NULL\n");

    // Important step - Check whether the list is empty
    if (head == NULL)
    {
        printf("Linked List is empty\n");
        return 0;
    }

    printf("\nEnter the position to delete: ");
    scanf("%d", &pos);

    // Important step - Check whether the position is valid
    if (pos < 1 || pos > n)
    {
        printf("Invalid position\n");
        return 0;
    }

    // Important step - Delete the first node
    if (pos == 1)
    {
        temp = head;
        head = head->next;
        free(temp);
    }
    else
    {
        temp = head;

        // Important step - Move to the node before the position
        for (i = 1; i < pos - 1; i++)
        {
            temp = temp->next;
        }

        // Store the node to be deleted
        prev = temp->next;

        // Important step - Skip the node to be deleted
        temp->next = prev->next;

        // Important step - Free the deleted node
        free(prev);
    }

    printf("\nLinked List after deletion:\n");

    temp = head;

    while (temp != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }

    printf("NULL\n");

    return 0;
}

/*

Singly Linked List - Deletion from Position

Definition:
Deletion from position means removing a node from
a specific position in the linked list.

Steps:

1. Check whether the linked list is empty.
2. Check whether the position is valid.
3. If position is 1, delete the first node.
4. Otherwise, move to the node before the required position.
5. Store the node to be deleted.
6. Change the link to skip the deleted node.
7. Free the deleted node.

Important Logic:

prev = temp->next;
temp->next = prev->next;
free(prev);

Example:

Before:
10 → 20 → 30 → 40 → NULL

Delete position 3

After:
10 → 20 → 40 → NULL

Time Complexity:
O(n)

Space Complexity:
O(1)

*/