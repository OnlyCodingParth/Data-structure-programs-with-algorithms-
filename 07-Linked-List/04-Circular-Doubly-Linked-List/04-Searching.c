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
    // Circular Doubly Linked List - Searching

    struct Node *head = NULL;
    struct Node *newNode;
    struct Node *temp;

    int n, i, value;
    int searchValue;
    int position = 1;
    int found = 0;

    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    // Important step - Create the circular doubly linked list
    for (i = 0; i < n; i++)
    {
        newNode = (struct Node *)malloc(sizeof(struct Node));

        printf("Enter the value: ");
        scanf("%d", &value);

        newNode->data = value;

        if (head == NULL)
        {
            head = newNode;

            newNode->prev = head;
            newNode->next = head;
        }
        else
        {
            temp = head;

            // Move to the last node
            while (temp->next != head)
            {
                temp = temp->next;
            }

            newNode->prev = temp;
            newNode->next = head;

            temp->next = newNode;
            head->prev = newNode;
        }
    }

    // Important step - Check if the list is empty
    if (head == NULL)
    {
        printf("\nList is empty.\n");
        return 0;
    }

    printf("\nEnter the value to search: ");
    scanf("%d", &searchValue);

    temp = head;

    // Important step - Search until we reach head again
    do
    {
        if (temp->data == searchValue)
        {
            found = 1;
            break;
        }

        temp = temp->next;
        position++;
    }
    while (temp != head);

    if (found == 1)
    {
        printf("\n%d found at position %d.\n", searchValue, position);
    }
    else
    {
        printf("\n%d not found in the list.\n", searchValue);
    }

    return 0;
}

/*

Circular Doubly Linked List - Searching

Definition:
Searching means finding whether a particular value
exists in the linked list.

Steps:

1. Start from head.
2. Compare the current node's data with the search value.
3. If the value matches, the search is successful.
4. Otherwise move to the next node.
5. Stop when head is reached again.

Important Logic:

temp = head;

do
{
    if (temp->data == searchValue)
    {
        found = 1;
        break;
    }

    temp = temp->next;
}
while (temp != head);

Example:

10 ⇄ 20 ⇄ 30 ⇄ 40

Search for 30:

10 → 20 → 30

30 is found at position 3.

Time Complexity:
Best Case: O(1)
Average Case: O(n)
Worst Case: O(n)

Space Complexity:
O(1)

*/