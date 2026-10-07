#include <stdio.h>
#include <stdlib.h>

struct Node
{
    struct Node *prev;
    int data;
    struct Node *next;
};

int main()
{
    struct Node *head = NULL;
    struct Node *newNode;
    struct Node *temp;
    struct Node *deleteNode;
    int n, i, value, pos;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    // Create the circular doubly linked list
    for (i = 1; i <= n; i++)
    {
        newNode = (struct Node *)malloc(sizeof(struct Node));

        printf("Enter value for node %d: ", i);
        scanf("%d", &value);

        newNode->data = value;

        if (head == NULL)
        {
            head = newNode;

            // Important step - First node points to itself
            newNode->prev = head;
            newNode->next = head;
        }
        else
        {
            temp = head;

            // Important step - Find the last node
            while (temp->next != head)
            {
                temp = temp->next;
            }

            // Important step - Connect new node with last and head
            newNode->prev = temp;
            newNode->next = head;

            temp->next = newNode;
            head->prev = newNode;
        }
    }

    // Important step - Check whether the list is empty
    if (head == NULL)
    {
        printf("List is empty. Deletion is not possible.\n");
        return 0;
    }

    printf("\nEnter position to delete: ");
    scanf("%d", &pos);

    // Important step - Check whether the position is valid
    if (pos < 1 || pos > n)
    {
        printf("Invalid position.\n");
        return 0;
    }

    // Important step - Delete the only node
    if (n == 1)
    {
        free(head);
        head = NULL;
    }
    // Important step - Delete the first node
    else if (pos == 1)
    {
        deleteNode = head;
        temp = head->prev;

        head = head->next;

        temp->next = head;
        head->prev = temp;

        free(deleteNode);
    }
    else
    {
        temp = head;

        // Important step - Move to the node at the required position
        for (i = 1; i < pos; i++)
        {
            temp = temp->next;
        }

        deleteNode = temp;

        // Important step - Connect previous and next nodes
        deleteNode->prev->next = deleteNode->next;
        deleteNode->next->prev = deleteNode->prev;

        free(deleteNode);
    }

    printf("\nCircular Doubly Linked List after deletion:\n");

    if (head != NULL)
    {
        temp = head;

        do
        {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        while (temp != head);
    }
    else
    {
        printf("List is empty.");
    }

    printf("\n");

    return 0;
}

/*
    Circular Doubly Linked List - Deletion from Position

    Definition:
    Deletion from position means removing a node from
    a specific position in a circular doubly linked list.

    Example:

    Before:

    10 <-> 20 <-> 30 <-> 40
    ^                       |
    |_______________________|

    Delete position 3.

    After:

    10 <-> 20 <-> 40
    ^                 |
    |_________________|

    Steps:
    1. Create the circular doubly linked list.
    2. Check whether the list is empty.
    3. Take the position from the user.
    4. Check whether the position is valid.
    5. If there is only one node, delete it.
    6. If position is 1, delete the first node.
    7. Otherwise, move to the required position.
    8. Connect the previous node with the next node.
    9. Connect the next node with the previous node.
    10. Free the deleted node.
    11. Display the updated list.

    Important:
    For a node to be deleted:

        deleteNode->prev->next = deleteNode->next;
        deleteNode->next->prev = deleteNode->prev;

    This reconnects both sides of the deleted node.

    Time Complexity:
        Best Case: O(1)
        Worst Case: O(n)

    Space Complexity:
        O(1) auxiliary space
*/