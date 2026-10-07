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
    // Queue using Linked List

    struct Node *front = NULL;
    struct Node *rear = NULL;
    struct Node *newNode;
    struct Node *temp;

    int choice, value;

    do
    {
        printf("\n--- Queue Using Linked List ---\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
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

                printf("Enter the value: ");
                scanf("%d", &value);

                newNode->data = value;
                newNode->next = NULL;

                // Important step - Insert the first node
                if (rear == NULL)
                {
                    front = newNode;
                    rear = newNode;
                }
                else
                {
                    // Important step - Insert the new node at rear
                    rear->next = newNode;
                    rear = newNode;
                }

                printf("Element inserted successfully\n");
                break;

            case 2:
                // Important step - Check whether the queue is empty
                if (front == NULL)
                {
                    printf("Queue Underflow\n");
                    break;
                }

                temp = front;

                // Important step - Move front to the next node
                front = front->next;

                printf("Dequeued element = %d\n", temp->data);

                free(temp);

                // If queue becomes empty
                if (front == NULL)
                {
                    rear = NULL;
                }

                break;

            case 3:
                // Important step - Access the front element
                if (front == NULL)
                {
                    printf("Queue is empty\n");
                }
                else
                {
                    printf("Front element = %d\n", front->data);
                }

                break;

            case 4:
                // Important step - Display from front to rear
                if (front == NULL)
                {
                    printf("Queue is empty\n");
                    break;
                }

                temp = front;

                printf("Queue elements:\n");

                while (temp != NULL)
                {
                    printf("%d ", temp->data);
                    temp = temp->next;
                }

                printf("\n");
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

Queue Using Linked List

Definition:
A queue can be implemented using a linked list.
Two pointers are used:

front -> Points to the first node
rear  -> Points to the last node

Enqueue:
Insert a new node at the rear.

Dequeue:
Delete a node from the front.

Peek:
Access the data of the front node.

Display:
Traverse the linked list from front to rear.

Important Conditions:

Empty Queue:
front == NULL

First Node:
front = newNode
rear = newNode

Enqueue:
rear->next = newNode
rear = newNode

Dequeue:
front = front->next

Time Complexity:
Enqueue = O(1)
Dequeue = O(1)
Peek    = O(1)
Display = O(n)

Space Complexity:
O(n)

Advantages:
1. Dynamic size
2. No fixed array size
3. No wasted array space

Disadvantages:
1. Extra memory is required for pointers
2. Dynamic memory allocation is required

*/