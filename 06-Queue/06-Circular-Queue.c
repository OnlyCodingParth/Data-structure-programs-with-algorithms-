#include <stdio.h>

#define MAX 5

int main()
{
    // Circular Queue

    int queue[MAX];
    int front = -1;
    int rear = -1;
    int choice, value, i;

    do
    {
        printf("\n--- Circular Queue ---\n");
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
                // Important step - Check whether the circular queue is full
                if ((rear + 1) % MAX == front)
                {
                    printf("Queue Overflow\n");
                    break;
                }

                printf("Enter the value: ");
                scanf("%d", &value);

                // Important step - Move rear circularly
                if (front == -1)
                {
                    front = 0;
                    rear = 0;
                }
                else
                {
                    rear = (rear + 1) % MAX;
                }

                queue[rear] = value;

                printf("Element inserted successfully\n");
                break;

            case 2:
                // Important step - Check whether the queue is empty
                if (front == -1)
                {
                    printf("Queue Underflow\n");
                    break;
                }

                printf("Dequeued element = %d\n", queue[front]);

                // If only one element is present
                if (front == rear)
                {
                    front = -1;
                    rear = -1;
                }
                else
                {
                    // Important step - Move front circularly
                    front = (front + 1) % MAX;
                }

                break;

            case 3:
                // Important step - Access the front element
                if (front == -1)
                {
                    printf("Queue is empty\n");
                }
                else
                {
                    printf("Front element = %d\n", queue[front]);
                }

                break;

            case 4:
                // Important step - Display circularly from front to rear
                if (front == -1)
                {
                    printf("Queue is empty\n");
                    break;
                }

                printf("Queue elements:\n");

                i = front;

                while (1)
                {
                    printf("%d ", queue[i]);

                    if (i == rear)
                    {
                        break;
                    }

                    i = (i + 1) % MAX;
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

Circular Queue - Algorithm

Enqueue:

1. Check whether the queue is full
2. If full, display Queue Overflow
3. If the queue is empty, set front = rear = 0
4. Otherwise, move rear circularly
5. Insert the element at queue[rear]

Dequeue:

1. Check whether the queue is empty
2. If empty, display Queue Underflow
3. Remove queue[front]
4. If front == rear, reset both to -1
5. Otherwise, move front circularly

Important Formula:

rear = (rear + 1) % MAX
front = (front + 1) % MAX

Full Condition:

(rear + 1) % MAX == front

Empty Condition:

front == -1

Time Complexity:
Enqueue = O(1)
Dequeue = O(1)
Peek    = O(1)
Display = O(n)

Space Complexity:
O(n)

Important Point:
Circular Queue reuses the empty spaces created by Dequeue.
*/