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
    // Singly Linked List - Updation

    struct Node *head = NULL;
    struct Node *newNode;
    struct Node *temp;

    int n, i, value, pos, newValue;

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

    printf("\nEnter the position to update: ");
    scanf("%d", &pos);

    // Important step - Check whether the position is valid
    if (pos < 1 || pos > n)
    {
        printf("Invalid position\n");
        return 0;
    }

    printf("Enter the new value: ");
    scanf("%d", &newValue);

    temp = head;

    // Important step - Move to the required position
    for (i = 1; i < pos; i++)
    {
        temp = temp->next;
    }

    // Important step - Update the node value
    temp->data = newValue;

    printf("\nLinked List after updation:\n");

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

Singly Linked List - Updation

Definition:
Updation means changing the data value of a node
at a specific position in the linked list.

Steps:

1. Check whether the linked list is empty.
2. Check whether the position is valid.
3. Start from the head node.
4. Traverse to the required position.
5. Replace the old value with the new value.
6. Display the updated linked list.

Important Logic:

for (i = 1; i < pos; i++)
{
    temp = temp->next;
}

temp->data = newValue;

Example:

Before:
10 → 20 → 30 → 40 → NULL

Update position 3 to 99

After:
10 → 20 → 99 → 40 → NULL

Time Complexity:
O(n)

Space Complexity:
O(1)

*/