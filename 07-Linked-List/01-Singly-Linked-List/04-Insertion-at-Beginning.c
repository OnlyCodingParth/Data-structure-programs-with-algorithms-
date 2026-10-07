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
    // Singly Linked List - Insertion at Beginning

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

    printf("Enter the value to insert at beginning: ");
    scanf("%d", &value);

    // Create a new node
    newNode = (struct Node *)malloc(sizeof(struct Node));

    newNode->data = value;

    // Important step - Connect new node to the current first node
    newNode->next = head;

    // Important step - Make the new node the new head
    head = newNode;

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

Singly Linked List - Insertion at Beginning

Definition:
Insertion at beginning means adding a new node before
the current first node of the linked list.

Steps:

1. Create a new node.
2. Store the value in the new node.
3. Make newNode->next point to head.
4. Make newNode the new head.

Important Logic:

newNode->next = head;
head = newNode;

Example:

Before:
head
 ↓
10 → 20 → 30 → NULL

Insert 5

After:
head
 ↓
5 → 10 → 20 → 30 → NULL

Time Complexity:
O(1)

Space Complexity:
O(1) auxiliary space
(O(1) extra space for the newly created node)

*/