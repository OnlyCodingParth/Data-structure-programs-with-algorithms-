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
    // Singly Linked List - Insertion at Position

    struct Node *head = NULL;
    struct Node *newNode;
    struct Node *temp;

    int n, i, value, pos;

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

    printf("Enter the position to insert: ");
    scanf("%d", &pos);

    printf("Enter the value to insert: ");
    scanf("%d", &value);

    // Important step - Check whether the position is valid
    if (pos < 1 || pos > n + 1)
    {
        printf("Invalid position\n");
        return 0;
    }

    // Create a new node
    newNode = (struct Node *)malloc(sizeof(struct Node));

    newNode->data = value;
    newNode->next = NULL;

    // Important step - Insert at the beginning
    if (pos == 1)
    {
        newNode->next = head;
        head = newNode;
    }
    else
    {
        temp = head;

        // Important step - Move to the node before the required position
        for (i = 1; i < pos - 1; i++)
        {
            temp = temp->next;
        }

        // Important step - Adjust the links
        newNode->next = temp->next;
        temp->next = newNode;
    }

    printf("\nLinked List after insertion:\n");

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

Singly Linked List - Insertion at Position

Definition:
Insertion at position means adding a new node at a
specific position in the linked list.

Steps:

1. Check whether the position is valid.
2. Create a new node.
3. If position is 1, insert the node at the beginning.
4. Otherwise, reach the node before the required position.
5. Connect the new node with the next node.
6. Connect the previous node with the new node.

Important Logic:

newNode->next = temp->next;
temp->next = newNode;

Example:

Before:
10 → 20 → 30 → 40 → NULL

Insert 25 at position 3

After:
10 → 20 → 25 → 30 → 40 → NULL

Time Complexity:
O(n)

Space Complexity:
O(1) auxiliary space
(O(1) extra space for the newly created node)

*/