#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};

// Important step - Count all nodes recursively
int countNodes(struct Node *root)
{
    if (root == NULL)
    {
        return 0;
    }

    return 1 + countNodes(root->left) + countNodes(root->right);
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

    printf("Number of Nodes = %d\n", countNodes(root));

    return 0;
}

/*
    Theory:

    Counting nodes means finding the total number of nodes
    present in a binary tree.

    For every non-NULL node:

    Total Nodes =
    1 + Nodes in Left Subtree + Nodes in Right Subtree

    Algorithm:

    1. Start from the root.
    2. If the root is NULL, return 0.
    3. Count the current node as 1.
    4. Recursively count nodes in the left subtree.
    5. Recursively count nodes in the right subtree.
    6. Add all three results.
    7. Return the total count.

    Time Complexity:

    O(n)

    Space Complexity:

    O(h)

    Where h is the height of the tree.
*/