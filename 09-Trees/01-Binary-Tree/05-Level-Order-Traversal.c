#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};

// Important step - Level Order Traversal using a queue
void levelOrder(struct Node *root)
{
    struct Node *queue[100];
    int front = 0;
    int rear = 0;

    if (root == NULL)
    {
        return;
    }

    // Important step - Insert root into queue
    queue[rear] = root;
    rear++;

    while (front < rear)
    {
        // Important step - Remove node from queue
        struct Node *current = queue[front];
        front++;

        printf("%d ", current->data);

        // Important step - Add left child to queue
        if (current->left != NULL)
        {
            queue[rear] = current->left;
            rear++;
        }

        // Important step - Add right child to queue
        if (current->right != NULL)
        {
            queue[rear] = current->right;
            rear++;
        }
    }
}

int main()
{
    struct Node *root;
    struct Node *leftNode;
    struct Node *rightNode;

    // Create root
    root = (struct Node *)malloc(sizeof(struct Node));

    root->data = 10;
    root->left = NULL;
    root->right = NULL;

    // Create left child
    leftNode = (struct Node *)malloc(sizeof(struct Node));

    leftNode->data = 20;
    leftNode->left = NULL;
    leftNode->right = NULL;

    // Create right child
    rightNode = (struct Node *)malloc(sizeof(struct Node));

    rightNode->data = 30;
    rightNode->left = NULL;
    rightNode->right = NULL;

    // Connect children
    root->left = leftNode;
    root->right = rightNode;

    printf("Level Order Traversal: ");

    levelOrder(root);

    return 0;
}

/*
    Theory:

    Level Order Traversal visits nodes level by level.

    It starts from the root and then visits its children
    from left to right.

    For the tree:

            10
           /  \
          20   30

    Level Order:
    10 20 30

    A queue is used to perform level order traversal.

    Algorithm:

    1. Create an empty queue.
    2. Insert the root node into the queue.
    3. Remove a node from the front of the queue.
    4. Visit and print the node.
    5. Insert its left child into the queue if it exists.
    6. Insert its right child into the queue if it exists.
    7. Repeat until the queue becomes empty.

    Time Complexity:

    O(n)

    Space Complexity:

    O(n)
*/