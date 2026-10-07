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
    struct Node *last;
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
        // Important step - Get the last node directly using head->prev
        last = head->prev;

        // Important step - Get the node before the last node
        temp = last->prev;

        // Important step - Connect previous node with head
        temp->next = head;
        head->prev = temp;

        // Important step - Delete the last node
        free(last);
    }

    printf("\nCircular Doubly Linked List after deletion from end:\n");

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
    Circular Doubly Linked List - Deletion from End

    Definition:
    Deletion from end means removing the last node
    of a circular doubly linked list.

    Example:

    Before:

    10 <-> 20 <-> 30
    ^             |
    |_____________|

    Delete the last node (30).

    After:

    10 <-> 20
    ^       |
    |_______|

    Steps:
    1. Create the circular doubly linked list.
    2. Check whether the list is empty.
    3. If there is only one node, delete it and make head NULL.
    4. Otherwise, get the last node using head->prev.
    5. Get the node before the last node using last->prev.
    6. Connect the previous node with head.
    7. Update head->prev.
    8. Free the last node.
    9. Display the updated list.

    Important:
    In a circular doubly linked list:
        - head->prev points directly to the last node.
        - last->prev points to the second-last node.
        - last->next points to head.

    Time Complexity:
        Best Case: O(1)
        Worst Case: O(1)

    Space Complexity:
        O(1) auxiliary space
*/