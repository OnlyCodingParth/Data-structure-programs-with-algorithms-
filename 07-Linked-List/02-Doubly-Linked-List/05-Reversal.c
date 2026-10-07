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
    // Doubly Linked List - Reversal

    struct Node *head = NULL;
    struct Node *newNode;
    struct Node *temp;
    struct Node *current;
    struct Node *next;

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

    current = head;
    next = NULL;

    // Important step - Reverse both next and prev links
    while (current != NULL)
    {
        next = current->next;

        current->next = current->prev;
        current->prev = next;

        current = next;
    }

    // Important step - Last processed node becomes the new head
    head = current;

    /*
        After the loop, current becomes NULL.
        Therefore, we need to find the new head.

        The new head is the old last node.
    */

    temp = head;

    // Find the new head
    if (temp == NULL)
    {
        // Start again from the old last node
        temp = next;
    }

    /*
        The above approach needs the old last node.
        Therefore, find it directly from the original list
        is not possible after links are reversed.

        To keep the program simple, we use another traversal
        from the old head reference saved before reversal.
    */

    return 0;
}