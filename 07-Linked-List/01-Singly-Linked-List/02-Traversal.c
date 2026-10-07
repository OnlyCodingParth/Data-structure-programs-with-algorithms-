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
    // Singly Linked List - Traversal

    struct Node *head = NULL;
    struct Node *newNode;
    struct Node *temp;

    int n, i, value;

    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    // Important step - Create the linked list
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

    printf("\nLinked List:\n");

    // Important step - Start traversal from head
    temp = head;

    while (temp != NULL)
    {
        printf("%d -> ", temp->data);

        // Important step - Move to the next node
        temp = temp->next;
    }

    printf("NULL\n");

    return 0;
}

/*

Singly Linked List - Traversal

Definition:
Traversal means visiting each node of the linked list
from the first node to the last node.

Steps:

1. Start from head.
2. Access the data of the current node.
3. Move to the next node using next.
4. Repeat until current node becomes NULL.

Important Logic:

temp = head;

while (temp != NULL)
{
    printf("%d ", temp->data);
    temp = temp->next;
}

Example:

head
 ↓
[10] → [20] → [30] → NULL

Traversal:
10 → 20 → 30

Time Complexity:
O(n)

Space Complexity:
O(1)

*/