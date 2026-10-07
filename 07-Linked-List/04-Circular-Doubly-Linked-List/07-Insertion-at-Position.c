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

    printf("\nEnter value to insert: ");
    scanf("%d", &value);

    printf("Enter position: ");
    scanf("%d", &pos);

    // Important step - Check whether the position is valid
    if (pos < 1 || pos > n + 1)
    {
        printf("Invalid position.\n");
        return 0;
    }

    newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = value;

    // Important step - Insert at beginning
    if (pos == 1)
    {
        if (head == NULL)
        {
            newNode->prev = newNode;
            newNode->next = newNode;
            head = newNode;
        }
        else
        {
            temp = head->prev;

            newNode->next = head;
            newNode->prev = temp;

            temp->next = newNode;
            head->prev = newNode;

            head = newNode;
        }
    }
    else
    {
        temp = head;

        // Important step - Move to the node before the required position
        for (i = 1; i < pos - 1; i++)
        {
            temp = temp->next;
        }

        // Important step - Insert new node between temp and temp->next
        newNode->next = temp->next;
        newNode->prev = temp;

        temp->next->prev = newNode;
        temp->next = newNode;
    }

    printf("\nCircular Doubly Linked List after insertion:\n");

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

    printf("\n");

    return 0;
}

/*
    Circular Doubly Linked List - Insertion at Position

    Definition:
    Insertion at position means adding a new node at a
    specific position in a circular doubly linked list.

    Example:

    Before:
    NULL <- 10 <-> 20 <-> 30 -> back to 10

    Insert 25 at position 3.

    After:
    10 <-> 20 <-> 25 <-> 30
    ^                       |
    |_______________________|

    Steps:
    1. Create the circular doubly linked list.
    2. Take the value and position from the user.
    3. Check whether the position is valid.
    4. If position is 1, insert the node at the beginning.
    5. Otherwise, move to the node just before the required position.
    6. Connect the new node using both prev and next pointers.
    7. Display the updated list.

    Important:
    In a circular doubly linked list:
        - head->prev points to the last node.
        - last->next points to head.

    Time Complexity:
        Best Case: O(1)
        Worst Case: O(n)

    Space Complexity:
        O(1) auxiliary space
*/