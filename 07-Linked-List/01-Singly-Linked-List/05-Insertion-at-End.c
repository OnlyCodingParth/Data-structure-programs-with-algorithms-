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
    // Singly Linked List - Insertion at End

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

    printf("Enter the value to insert at end: ");
    scanf("%d", &value);

    // Create a new node
    newNode = (struct Node *)malloc(sizeof(struct Node));

    newNode->data = value;
    newNode->next = NULL;

    // Important step - Handle an empty linked list
    if (head == NULL)
    {
        head = newNode;
    }
    else
    {
        temp = head;

        // Important step - Move to the last node
        while (temp->next != NULL)
        {
            temp = temp->next;
        }

        // Important step - Connect the last node to the new node
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

Singly Linked List - Insertion at End

Definition:
Insertion at end means adding a new node after the
current last node of the linked list.

Steps:

1. Create a new node.
2. Store the value in the new node.
3. Set newNode->next = NULL.
4. If the list is empty, make newNode the head.
5. Otherwise, traverse to the last node.
6. Connect the last node to the new node.

Important Logic:

while (temp->next != NULL)
{
    temp = temp->next;
}

temp->next = newNode;

Example:

Before:
10 → 20 → 30 → NULL

Insert 40

After:
10 → 20 → 30 → 40 → NULL

Time Complexity:
O(n)

Space Complexity:
O(1) auxiliary space
(O(1) extra space for the newly created node)

*/