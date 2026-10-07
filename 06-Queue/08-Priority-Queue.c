#include <stdio.h>

#define MAX 100

int main()
{
    // Priority Queue

    int queue[MAX];
    int priority[MAX];
    int n = 0;
    int choice, value, p;
    int i, j;
    int temp;

    do
    {
        printf("\n--- Priority Queue ---\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Display\n");
        printf("4. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                // Important step - Check whether the priority queue is full
                if (n == MAX)
                {
                    printf("Priority Queue Overflow\n");
                    break;
                }

                printf("Enter the value: ");
                scanf("%d", &value);

                printf("Enter the priority (smaller number = higher priority): ");
                scanf("%d", &p);

                queue[n] = value;
                priority[n] = p;
                n++;

                printf("Element inserted successfully\n");
                break;

            case 2:
                // Important step - Check whether the priority queue is empty
                if (n == 0)
                {
                    printf("Priority Queue Underflow\n");
                    break;
                }

                // Important step - Find the element with highest priority
                j = 0;

                for (i = 1; i < n; i++)
                {
                    if (priority[i] < priority[j])
                    {
                        j = i;
                    }
                }

                printf("Deleted element = %d\n", queue[j]);

                // Important step - Shift remaining elements to fill the gap
                for (i = j; i < n - 1; i++)
                {
                    queue[i] = queue[i + 1];
                    priority[i] = priority[i + 1];
                }

                n--;

                break;

            case 3:
                // Important step - Display all elements with their priorities
                if (n == 0)
                {
                    printf("Priority Queue is empty\n");
                    break;
                }

                printf("\nValue\tPriority\n");

                for (i = 0; i < n; i++)
                {
                    printf("%d\t%d\n", queue[i], priority[i]);
                }

                break;

            case 4:
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid choice\n");
        }

    } while (choice != 4);

    return 0;
}

/*

Priority Queue

Definition:
A Priority Queue is a queue in which each element
has a priority, and the element with higher priority
is served first.

In this program:
Smaller priority number = Higher priority

Example:

Value       Priority
10          3
20          1
30          2

Deletion order:

20 -> 30 -> 10

Operations:

1. Insert
2. Delete
3. Display

Important Step:
During deletion, find the element having the
highest priority.

Time Complexity:
Insertion = O(1)
Deletion  = O(n)
Display   = O(n)

Space Complexity:
O(n)

Important Point:
Priority Queue does not strictly follow FIFO.
Priority determines which element is removed first.

*/