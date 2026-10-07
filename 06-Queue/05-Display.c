#include <stdio.h>

#define MAX 100

int main()
{
    // Display Operation

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
        printf("Queue is empty\n");
        return 0;
    }

    printf("Queue elements from front to rear:\n");

    // Important step - Display elements from front to rear
    for (i = front; i <= rear; i++)
    {
        printf("%d ", queue[i]);
    }

    return 0;
}

/*

Display Operation - Algorithm

1. Start
2. Check whether the queue is empty
3. If the queue is empty, display "Queue is empty"
4. Otherwise, start from front
5. Display queue[i]
6. Increase i
7. Repeat until i reaches rear
8. End

Important Point:

Queue is displayed from FRONT to REAR.

Time Complexity:
O(n)

Space Complexity:
O(n)

Principle:
FIFO (First In, First Out)

*/