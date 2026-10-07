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
    // Doubly Linked List - Deletion from Beginning

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

    // Important step - Check whether the list is empty
    if (head == NULL)
    {
        printf("\nLinked List is empty.\n");
        return 0;
    }

    // Important step - Store the first node temporarily
    temp = head;

    // Important step - Move head to the second node
    head = head->next;

    // Important step - Remove the backward link of the new head
    if (head != NULL)
    {
        head->prev = NULL;
    }

    // Important step - Free the deleted node
    free(temp);

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

Doubly Linked List - Deletion from Beginning

Definition:
Deletion from beginning means removing the first node
of the doubly linked list.

Steps:

1. Check whether the list is empty.
2. Store the first node in a temporary pointer.
3. Move head to the second node.
4. Set the prev of the new head to NULL.
5. Free the old first node.

Important Logic:

temp = head;
head = head->next;

if (head != NULL)
{
    head->prev = NULL;
}

free(temp);

Example:

Before:
NULL ← 10 ⇄ 20 ⇄ 30 → NULL

Delete first node (10)

After:
NULL ← 20 ⇄ 30 → NULL

Time Complexity:
O(1)

Space Complexity:
O(1) auxiliary space

*/