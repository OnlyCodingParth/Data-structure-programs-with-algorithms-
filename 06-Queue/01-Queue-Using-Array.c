#include <stdio.h>

#define MAX 100

int main()
{
    // Queue using Array

    int queue[MAX];
    int front = -1;
    int rear = -1;
    int n, i;

    printf("Enter the number of elements to insert: ");
    scanf("%d", &n);

    if (n > MAX)
    {
        printf("Queue Overflow\n");
        return 0;
    }

    printf("Enter the elements:\n");

    // Important step - Insert elements at the rear
    for (i = 0; i < n; i++)
    {
        if (front == -1)
        {
            front = 0;
        }

        rear++;
        scanf("%d", &queue[rear]);
    }

    printf("Queue elements are:\n");

    // Important step - Display elements from front to rear
    for (i = front; i <= rear; i++)
    {
        printf("%d ", queue[i]);
    }

    return 0;
}

/*

Queue Using Array - Algorithm

1. Start
2. Create an array to store queue elements
3. Initialize front = -1 and rear = -1
4. Read the number of elements
5. Check whether the queue is full
6. If the queue is empty, set front = 0
7. Increment rear
8. Insert the element at queue[rear]
9. Repeat for all elements
10. Display elements from front to rear
11. End

Important Queue Operations:

Enqueue -> Insert an element
Dequeue -> Remove an element
Peek    -> View the front element
Display -> Display all elements

Initial Condition:

front = -1
rear = -1

When the first element is inserted:

front = 0
rear = 0

Principle:
FIFO (First In, First Out)

Time Complexity:
Insertion = O(1)
Display   = O(n)

Space Complexity:
O(n)

*/