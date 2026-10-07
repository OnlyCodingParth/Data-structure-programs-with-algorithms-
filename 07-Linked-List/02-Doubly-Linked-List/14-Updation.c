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
    // Doubly Linked List - Updation

    struct Node *head = NULL;
    struct Node *newNode;
    struct Node *temp;

    int n, i, value;
    int pos, newValue;

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

    printf("\nEnter the position to update: ");
    scanf("%d", &pos);

    printf("Enter the new value: ");
    scanf("%d", &newValue);

    // Important step - Check whether position is valid
    if (pos < 1 || pos > n)
    {
        printf("\nInvalid position!\n");
        return 0;
    }

    temp = head;

    // Important step - Move to the required position
    for (i = 1; i < pos; i++)
    {
        temp = temp->next;
    }

    // Important step - Update the data
    temp->data = newValue;

    printf("\nDoubly Linked List after updation:\n");

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

Doubly Linked List - Updation

Definition:
Updation means changing the data stored in a node
at a specific position.

Steps:

1. Check whether the list is empty.
2. Enter the position to update.
3. Check whether the position is valid.
4. Traverse to the required node.
5. Replace the old data with the new data.

Important Logic:

temp = head;

for (i = 1; i < pos; i++)
{
    temp = temp->next;
}

temp->data = newValue;

Example:

Before:
NULL ← 10 ⇄ 20 ⇄ 30 → NULL

Update position 2 with 50

After:
NULL ← 10 ⇄ 50 ⇄ 30 → NULL

Time Complexity:
O(n)

Space Complexity:
O(1) auxiliary space

*/