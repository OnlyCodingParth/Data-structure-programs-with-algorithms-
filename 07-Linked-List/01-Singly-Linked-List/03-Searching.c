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
    // Singly Linked List - Searching

    struct Node *head = NULL;
    struct Node *newNode;
    struct Node *temp;

    int n, i, value, found = 0, position = 1;

    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    // Important step - Create the linked list
    for (i = 0; i < n; i++)
    {
        newNode = (struct Node *)malloc(sizeof(struct Node));

        printf("Enter the value: ");
        scanf("%d", &newNode->data);

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

    printf("Enter the element to search: ");
    scanf("%d", &value);

    temp = head;

    // Important step - Compare each node with the search value
    while (temp != NULL)
    {
        if (temp->data == value)
        {
            printf("Element found at position %d\n", position);
            found = 1;
            break;
        }

        // Important step - Move to the next node
        temp = temp->next;
        position++;
    }

    if (found == 0)
    {
        printf("Element not found\n");
    }

    return 0;
}

/*

Singly Linked List - Searching

Definition:
Searching means finding a particular element in the
linked list.

Steps:

1. Start from the head node.
2. Compare the current node's data with the search value.
3. If the value matches, the element is found.
4. Otherwise, move to the next node.
5. Continue until the element is found or NULL is reached.

Important Logic:

while (temp != NULL)
{
    if (temp->data == value)
    {
        // Element found
    }

    temp = temp->next;
}

Example:

10 → 20 → 30 → 40 → NULL

Search: 30

Result:
Element found at position 3

Time Complexity:
Best Case  = O(1)
Average Case = O(n)
Worst Case = O(n)

Space Complexity:
O(1)

*/