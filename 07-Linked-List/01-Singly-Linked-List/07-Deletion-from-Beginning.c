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
    // Singly Linked List - Deletion from Beginning

    struct Node *head = NULL;
    struct Node *newNode;
    struct Node *temp;

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

    // Important step - Store the first node temporarily
    temp = head;

    // Important step - Move head to the second node
    head = head->next;

    // Important step - Free the deleted node
    free(temp);

    printf("\nLinked List after deletion from beginning:\n");

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

Singly Linked List - Deletion from Beginning

Definition:
Deletion from beginning means removing the first node
of the linked list.

Steps:

1. Check whether the linked list is empty.
2. Store the first node in a temporary pointer.
3. Move head to the next node.
4. Free the old first node.
5. Display the updated linked list.

Important Logic:

temp = head;
head = head->next;
free(temp);

Example:

Before:
10 → 20 → 30 → NULL

After deleting 10:
20 → 30 → NULL

Time Complexity:
O(1)

Space Complexity:
O(1)

*/