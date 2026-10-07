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
    int n, i, value;

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

    // Important step - Delete the only node
    if (head->next == head)
    {
        free(head);
        head = NULL;
    }
    else
    {
        // Important step - Store the last node
        temp = head->prev;

        // Important step - Move head to the second node
        head = head->next;

        // Important step - Connect last node with new head
        temp->next = head;
        head->prev = temp;
    }

    printf("\nCircular Doubly Linked List after deletion from beginning:\n");

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
    Circular Doubly Linked List - Deletion from Beginning

    Definition:
    Deletion from beginning means removing the first node
    of a circular doubly linked list.

    Example:

    Before:

    10 <-> 20 <-> 30
    ^             |
    |_____________|

    Delete the first node (10).

    After:

    20 <-> 30
    ^       |
    |_______|

    Steps:
    1. Create the circular doubly linked list.
    2. Check whether the list is empty.
    3. If there is only one node, delete it and make head NULL.
    4. Otherwise, store the last node using head->prev.
    5. Move head to the second node.
    6. Make the last node point to the new head.
    7. Make the new head's prev point to the last node.
    8. Display the updated list.

    Important:
    In a circular doubly linked list:
        - head->prev points to the last node.
        - last->next points to head.

    Time Complexity:
        Best Case: O(1)
        Worst Case: O(1)

    Space Complexity:
        O(1) auxiliary space
*/