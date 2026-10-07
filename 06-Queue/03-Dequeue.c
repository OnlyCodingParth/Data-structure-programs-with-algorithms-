#include <stdio.h>

#define MAX 100

int main()
{
    // Dequeue Operation

    int queue[MAX];
    int front = -1;
    int rear = -1;
    int n, i, value;

    printf("Enter the number of elements in the queue: ");
    scanf("%d", &n);

    if (n > MAX)
    {
        printf("Queue Overflow\n");
        return 0;
    }

    printf("Enter the elements:\n");

    // Important step - Insert elements into the queue
    for (i = 0; i < n; i++)
    {
        rear++;
        scanf("%d", &queue[rear]);

        if (front == -1)
        {
            front = 0;
        }
    }

    // Important step - Check whether the queue is empty
    if (front == -1 || front > rear)
    {
        printf("Queue Underflow\n");
        return 0;
    }

    // Important step - Remove the element from the front
    value = queue[front];
    front++;

    printf("Dequeued element = %d\n", value);

    // Reset queue when it becomes empty
    if (front > rear)
    {
        front = -1;
        rear = -1;
    }

    printf("Queue after Dequeue operation:\n");

    if (front == -1)
    {
        printf("Queue is empty\n");
    }
    else
    {
        for (i = front; i <= rear; i++)
        {
            printf("%d ", queue[i]);
        }
    }

    return 0;
}

/*

Dequeue Operation - Algorithm

1. Start
2. Check whether the queue is empty
3. If the queue is empty, display Queue Underflow
4. Store the element at queue[front]
5. Increment front
6. Display the removed element
7. If the queue becomes empty, reset front and rear
8. Display the remaining queue
9. End

Important Formula:

value = queue[front]
front = front + 1

Time Complexity:
O(1)

Space Complexity:
O(n)

Principle:
FIFO (First In, First Out)

Important Point:
Dequeue always removes the element from the FRONT.

*/