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
    // Singly Linked List - Deletion from End

    struct Node *head = NULL;
    struct Node *newNode;
    struct Node *temp;
    struct Node *prev;

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

    // Important step - Check whether the list is empty
    if (head == NULL)
    {
        printf("Linked List is empty\n");
        return 0;
    }

    // Important step - Handle a list containing only one node
    if (head->next == NULL)
    {
        free(head);
        head = NULL;
    }
    else
    {
        temp = head;

        // Important step - Move to the last node
        while (temp->next != NULL)
        {
            prev = temp;
            temp = temp->next;
        }

        // Important step - Remove the last node
        prev->next = NULL;
        free(temp);
    }

    printf("\nLinked List after deletion from end:\n");

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

Singly Linked List - Deletion from End

Definition:
Deletion from end means removing the last node
of the linked list.

Steps:

1. Check whether the linked list is empty.
2. If there is only one node, delete it and make head NULL.
3. Otherwise, traverse to the last node.
4. Keep track of the previous node.
5. Set the previous node's next to NULL.
6. Free the last node.

Important Logic:

while (temp->next != NULL)
{
    prev = temp;
    temp = temp->next;
}

prev->next = NULL;
free(temp);

Example:

Before:
10 → 20 → 30 → 40 → NULL

After deleting 40:
10 → 20 → 30 → NULL

Time Complexity:
O(n)

Space Complexity:
O(1)

*/