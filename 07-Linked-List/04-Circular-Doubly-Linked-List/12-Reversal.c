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
    struct Node *current;
    struct Node *nextNode;
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
        printf("List is empty. Reversal is not possible.\n");
        return 0;
    }

    /*
        Reversal:
        Swap the prev and next pointers of every node.
    */

    current = head;

    do
    {
        // Important step - Store the original next node
        nextNode = current->next;

        // Important step - Swap prev and next pointers
        current->next = current->prev;
        current->prev = nextNode;

        current = nextNode;

    } while (current != head);

    // Important step - Move head to the old last node
    head = head->prev;

    printf("\nCircular Doubly Linked List after reversal:\n");

    temp = head;

    do
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    while (temp != head);

    printf("\n");

    return 0;
}

/*
    Circular Doubly Linked List - Reversal

    Definition:
    Reversal means reversing the direction of a circular
    doubly linked list.

    Example:

    Before:

    10 <-> 20 <-> 30
    ^             |
    |_____________|

    After reversal:

    30 <-> 20 <-> 10
    ^             |
    |_____________|

    Steps:
    1. Create the circular doubly linked list.
    2. Check whether the list is empty.
    3. Start from head.
    4. Store the original next node.
    5. Swap the prev and next pointers.
    6. Move to the original next node.
    7. Repeat until all nodes are processed.
    8. Move head to the old last node.
    9. Display the reversed list.

    Important:
    For every node:

        old next becomes new prev
        old prev becomes new next

    Example:

        Before:
        10 -> 20

        After:
        10 <- 20

    The head must also be changed to the old last node.

    Time Complexity:
        Best Case: O(n)
        Worst Case: O(n)

    Space Complexity:
        O(1) auxiliary space
*/