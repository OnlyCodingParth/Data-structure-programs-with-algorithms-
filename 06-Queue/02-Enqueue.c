#include <stdio.h>

#define MAX 100

int main()
{
    // Enqueue Operation

    int queue[MAX];
    int front = -1;
    int rear = -1;
    int n, i, value;

    printf("Enter the number of elements to enqueue: ");
    scanf("%d", &n);

    // Important step - Check whether the queue is full
    if (n > MAX)
    {
        printf("Queue Overflow\n");
        return 0;
    }

    // Important step - Enqueue elements at the rear
    for (i = 0; i < n; i++)
    {
        printf("Enter element: ");
        scanf("%d", &value);

        if (front == -1)
        {
            front = 0;
        }

        rear++;
        queue[rear] = value;
    }

    printf("\nQueue after Enqueue operation:\n");

    // Important step - Display from front to rear
    for (i = front; i <= rear; i++)
    {
        printf("%d ", queue[i]);
    }

    return 0;
}

/*

Enqueue Operation - Algorithm

1. Start
2. Check whether the queue is full
3. If the queue is full, display Queue Overflow
4. If the queue is empty, set front = 0
5. Increment rear
6. Insert the new element at queue[rear]
7. Repeat for required elements
8. Display the queue
9. End

Important Formula:

rear = rear + 1
queue[rear] = value

Time Complexity:
O(1) for one Enqueue operation

Space Complexity:
O(n)

Principle:
FIFO (First In, First Out)

Important Point:
Enqueue always inserts the element at the REAR.
*/