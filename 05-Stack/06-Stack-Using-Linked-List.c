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
    // Stack using Linked List

    struct Node *top = NULL;
    struct Node *newNode;
    struct Node *temp;
    int choice, value;

    do
    {
        printf("\n--- Stack Using Linked List ---\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Peek\n");
        printf("4. Display\n");
        printf("5. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                // Important step - Create a new node
                newNode = (struct Node *)malloc(sizeof(struct Node));

                if (newNode == NULL)
                {
                    printf("Stack Overflow\n");
                    break;
                }

                printf("Enter the value: ");
                scanf("%d", &value);

                newNode->data = value;
                newNode->next = top;

                // Important step - Make the new node the top
                top = newNode;

                printf("Element pushed successfully\n");
                break;

            case 2:
                // Important step - Check whether the stack is empty
                if (top == NULL)
                {
                    printf("Stack Underflow\n");
                    break;
                }

                temp = top;
                printf("Popped element = %d\n", top->data);

                top = top->next;
                free(temp);

                break;

            case 3:
                // Important step - Access the top element
                if (top == NULL)
                {
                    printf("Stack is empty\n");
                }
                else
                {
                    printf("Top element = %d\n", top->data);
                }

                break;

            case 4:
                // Important step - Display from top to bottom
                if (top == NULL)
                {
                    printf("Stack is empty\n");
                    break;
                }

                temp = top;

                printf("Stack elements:\n");

                while (temp != NULL)
                {
                    printf("%d\n", temp->data);
                    temp = temp->next;
                }

                break;

            case 5:
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid choice\n");
        }

    } while (choice != 5);

    return 0;
}

/*

Stack Using Linked List - Algorithm

Push:
1. Create a new node
2. Store the value in the node
3. Make newNode->next point to top
4. Make newNode the new top

Pop:
1. Check whether top is NULL
2. Store the top node in a temporary pointer
3. Move top to the next node
4. Free the old top node

Peek:
1. Check whether top is NULL
2. Access top->data

Display:
1. Start from top
2. Visit each node
3. Print the data
4. Move to the next node

Time Complexity:
Push   = O(1)
Pop    = O(1)
Peek   = O(1)
Display = O(n)

Space Complexity:
O(n)

Important Point:
Unlike an array-based stack, a linked-list stack
does not have a fixed size.

*/