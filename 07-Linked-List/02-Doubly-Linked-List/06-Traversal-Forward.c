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
    // Doubly Linked List - Forward Traversal

    struct Node *head = NULL;
    struct Node *newNode;
    struct Node *temp;

    int n, i, value;

    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    // Important step - Create the doubly linked list
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

            // Important step - Connect both directions
            temp->next = newNode;
            newNode->prev = temp;
        }
    }

    printf("\nDoubly Linked List in Forward Direction:\n");

    temp = head;

    // Important step - Traverse using next pointer
    while (temp != NULL)
    {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }

    printf("NULL\n");

    return 0;
}

/*

Doubly Linked List - Forward Traversal

Definition:
Forward traversal means visiting every node from the
first node to the last node.

Steps:

1. Start from head.
2. Print the current node's data.
3. Move to the next node using next.
4. Repeat until temp becomes NULL.

Important Logic:

temp = head;

while (temp != NULL)
{
    printf("%d ", temp->data);
    temp = temp->next;
}

Example:

NULL ← 10 ⇄ 20 ⇄ 30 → NULL

Forward traversal:
10 → 20 → 30

Time Complexity:
O(n)

Space Complexity:
O(1)

*/