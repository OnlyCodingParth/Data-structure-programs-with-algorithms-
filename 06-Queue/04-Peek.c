#include <stdio.h>

#define MAX 100

int main()
{
    // Peek Operation

    int queue[MAX];
    int front = -1;
    int rear = -1;
    int n, i;

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
    if (front == -1)
    {
        printf("Queue Underflow\n");
        return 0;
    }

    // Important step - Access the front element without removing it
    printf("Front element = %d\n", queue[front]);

    printf("Queue after Peek operation:\n");

    for (i = front; i <= rear; i++)
    {
        printf("%d ", queue[i]);
    }

    return 0;
}

/*

Peek Operation - Algorithm

1. Start
2. Check whether the queue is empty
3. If the queue is empty, display Queue Underflow
4. Otherwise, access queue[front]
5. Display the front element
6. Do not change front or rear
7. End

Important Formula:

queue[front]

Time Complexity:
O(1)

Space Complexity:
O(n)

Important Point:
Peek only views the FRONT element.
It does not remove the element.

Principle:
FIFO (First In, First Out)

*/