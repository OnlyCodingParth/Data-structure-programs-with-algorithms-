#include <stdio.h>

#define MAX 100

int main()
{
    // Deque (Double-Ended Queue)

    int deque[MAX];
    int front = -1;
    int rear = -1;
    int choice, value, i;

    do
    {
        printf("\n--- Deque ---\n");
        printf("1. Insert at Front\n");
        printf("2. Insert at Rear\n");
        printf("3. Delete from Front\n");
        printf("4. Delete from Rear\n");
        printf("5. Display\n");
        printf("6. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                // Important step - Insert at the front
                if ((front == 0 && rear == MAX - 1) || front == rear + 1)
                {
                    printf("Deque Overflow\n");
                    break;
                }

                printf("Enter the value: ");
                scanf("%d", &value);

                if (front == -1)
                {
                    front = 0;
                    rear = 0;
                }
                else if (front == 0)
                {
                    front = MAX - 1;
                }
                else
                {
                    front--;
                }

                deque[front] = value;

                printf("Element inserted at front\n");
                break;

            case 2:
                // Important step - Insert at the rear
                if ((front == 0 && rear == MAX - 1) || front == rear + 1)
                {
                    printf("Deque Overflow\n");
                    break;
                }

                printf("Enter the value: ");
                scanf("%d", &value);

                if (front == -1)
                {
                    front = 0;
                    rear = 0;
                }
                else if (rear == MAX - 1)
                {
                    rear = 0;
                }
                else
                {
                    rear++;
                }

                deque[rear] = value;

                printf("Element inserted at rear\n");
                break;

            case 3:
                // Important step - Delete from the front
                if (front == -1)
                {
                    printf("Deque Underflow\n");
                    break;
                }

                printf("Deleted element = %d\n", deque[front]);

                if (front == rear)
                {
                    front = -1;
                    rear = -1;
                }
                else if (front == MAX - 1)
                {
                    front = 0;
                }
                else
                {
                    front++;
                }

                break;

            case 4:
                // Important step - Delete from the rear
                if (front == -1)
                {
                    printf("Deque Underflow\n");
                    break;
                }

                printf("Deleted element = %d\n", deque[rear]);

                if (front == rear)
                {
                    front = -1;
                    rear = -1;
                }
                else if (rear == 0)
                {
                    rear = MAX - 1;
                }
                else
                {
                    rear--;
                }

                break;

            case 5:
                // Important step - Display from front to rear
                if (front == -1)
                {
                    printf("Deque is empty\n");
                    break;
                }

                printf("Deque elements:\n");

                i = front;

                while (1)
                {
                    printf("%d ", deque[i]);

                    if (i == rear)
                    {
                        break;
                    }

                    i = (i + 1) % MAX;
                }

                printf("\n");
                break;

            case 6:
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid choice\n");
        }

    } while (choice != 6);

    return 0;
}

/*

Deque - Double-Ended Queue

Definition:
A Deque is a linear data structure in which insertion
and deletion can be performed from both ends.

Operations:

1. Insert at Front
2. Insert at Rear
3. Delete from Front
4. Delete from Rear
5. Display

Important Points:

Front -> Beginning of Deque
Rear  -> End of Deque

Time Complexity:
Insert at Front = O(1)
Insert at Rear  = O(1)
Delete from Front = O(1)
Delete from Rear  = O(1)
Display = O(n)

Space Complexity:
O(n)

Important Point:
Deque can work like both a Stack and a Queue.

*/