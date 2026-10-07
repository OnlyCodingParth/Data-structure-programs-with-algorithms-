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
    // Doubly Linked List - Deletion from End

    struct Node *head = NULL;
    struct Node *newNode;
    struct Node *temp;

    int n, i, value;

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

    // Important step - Move to the last node
    temp = head;

    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    // Important step - Handle the case of only one node
    if (temp->prev == NULL)
    {
        head = NULL;
    }
    else
    {
        // Important step - Remove the last node's connection
        temp->prev->next = NULL;
    }

    // Important step - Free the deleted node
    free(temp);

    printf("\nDoubly Linked List after deletion:\n");

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

Doubly Linked List - Deletion from End

Definition:
Deletion from end means removing the last node
of the doubly linked list.

Steps:

1. Check whether the list is empty.
2. Move to the last node.
3. Check whether the list contains only one node.
4. If there is only one node, make head NULL.
5. Otherwise, use the prev pointer to reach the
   previous node.
6. Set the previous node's next to NULL.
7. Free the last node.

Important Logic:

temp = head;

while (temp->next != NULL)
{
    temp = temp->next;
}

if (temp->prev == NULL)
{
    head = NULL;
}
else
{
    temp->prev->next = NULL;
}

free(temp);

Example:

Before:
NULL ← 10 ⇄ 20 ⇄ 30 → NULL

Delete last node (30)

After:
NULL ← 10 ⇄ 20 → NULL

Time Complexity:
O(n)

Space Complexity:
O(1) auxiliary space

Note:
If a tail pointer is maintained, deletion from end
can be performed in O(1) time.

*/