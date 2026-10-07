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
    int n, i, value, pos, newValue;

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
        printf("List is empty. Updation is not possible.\n");
        return 0;
    }

    printf("\nEnter position to update: ");
    scanf("%d", &pos);

    // Important step - Check whether the position is valid
    if (pos < 1 || pos > n)
    {
        printf("Invalid position.\n");
        return 0;
    }

    printf("Enter new value: ");
    scanf("%d", &newValue);

    temp = head;

    // Important step - Move to the required position
    for (i = 1; i < pos; i++)
    {
        temp = temp->next;
    }

    // Important step - Update the data of the selected node
    temp->data = newValue;

    printf("\nCircular Doubly Linked List after updation:\n");

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
    Circular Doubly Linked List - Updation

    Definition:
    Updation means changing the data stored in an existing
    node of a circular doubly linked list.

    Example:

    Before:

    10 <-> 20 <-> 30
    ^             |
    |_____________|

    Update position 2 with 50.

    After:

    10 <-> 50 <-> 30
    ^             |
    |_____________|

    Steps:
    1. Create the circular doubly linked list.
    2. Check whether the list is empty.
    3. Take the position from the user.
    4. Check whether the position is valid.
    5. Move temp to the required position.
    6. Change the data of that node.
    7. Display the updated list.

    Important:
    Updation only changes the data.
    The prev and next links are not changed.

    Time Complexity:
        Best Case: O(1)
        Worst Case: O(n)

    Space Complexity:
        O(1) auxiliary space
*/