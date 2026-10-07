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
    // Singly Linked List - Reversal

    struct Node *head = NULL;
    struct Node *newNode;
    struct Node *temp;

    struct Node *prev = NULL;
    struct Node *current;
    struct Node *next;

    int n, i, value;

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

    // Important step - Reverse the linked list
    current = head;

    while (current != NULL)
    {
        // Store the next node
        next = current->next;

        // Reverse the current node's link
        current->next = prev;

        // Move prev forward
        prev = current;

        // Move current forward
        current = next;
    }

    // Important step - Make prev the new head
    head = prev;

    printf("\nLinked List after reversal:\n");

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

Singly Linked List - Reversal

Definition:
Reversal means changing the direction of all links
so that the last node becomes the first node.

Steps:

1. Set prev = NULL.
2. Set current = head.
3. Store the next node in a temporary pointer.
4. Reverse the current node's link.
5. Move prev to current.
6. Move current to the stored next node.
7. Repeat until current becomes NULL.
8. Make prev the new head.

Important Logic:

next = current->next;
current->next = prev;
prev = current;
current = next;

Example:

Before:
10 → 20 → 30 → 40 → NULL

After:
40 → 30 → 20 → 10 → NULL

Time Complexity:
O(n)

Space Complexity:
O(1)

*/