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
    // Singly Linked List - Creation

    struct Node *head = NULL;
    struct Node *newNode;
    struct Node *temp;

    int n, i, value;

    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    // Important step - Create nodes one by one
    for (i = 0; i < n; i++)
    {
        newNode = (struct Node *)malloc(sizeof(struct Node));

        printf("Enter the value: ");
        scanf("%d", &value);

        newNode->data = value;
        newNode->next = NULL;

        // Important step - Connect the new node to the list
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

    printf("Singly Linked List:\n");

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

Singly Linked List - Creation

Definition:
A Singly Linked List is a linear data structure in which
each node contains data and a pointer to the next node.

Node structure:

[data | next]

Steps:

1. Create a node using malloc().
2. Store data in the node.
3. Set next to NULL.
4. If the list is empty, make the node the head.
5. Otherwise, traverse to the last node.
6. Connect the last node to the new node.

Example:

head
 ↓
[10 | •] → [20 | •] → [30 | NULL]

Important Point:
head stores the address of the first node.

Time Complexity:
Creation = O(n²) in this simple implementation
because we traverse the list to find the last node
for every new node.

Space Complexity:
O(n)

*/