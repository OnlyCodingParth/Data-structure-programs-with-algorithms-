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
    // Doubly Linked List - Backward Traversal

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

    // Important step - Move to the last node
    temp = head;

    while (temp != NULL && temp->next != NULL)
    {
        temp = temp->next;
    }

    printf("\nDoubly Linked List in Backward Direction:\n");

    // Important step - Traverse using prev pointer
    while (temp != NULL)
    {
        printf("%d <-> ", temp->data);
        temp = temp->prev;
    }

    printf("NULL\n");

    return 0;
}

/*

Doubly Linked List - Backward Traversal

Definition:
Backward traversal means visiting every node from the
last node to the first node.

Steps:

1. Start from head.
2. Move to the last node using next.
3. Print the current node's data.
4. Move to the previous node using prev.
5. Repeat until temp becomes NULL.

Important Logic:

while (temp->next != NULL)
{
    temp = temp->next;
}

while (temp != NULL)
{
    printf("%d ", temp->data);
    temp = temp->prev;
}

Example:

NULL ← 10 ⇄ 20 ⇄ 30 → NULL

Backward traversal:
30 → 20 → 10

Time Complexity:
O(n)

Space Complexity:
O(1)

*/