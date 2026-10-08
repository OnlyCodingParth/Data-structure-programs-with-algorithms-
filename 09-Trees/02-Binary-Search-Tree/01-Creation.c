#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};

int main()
{
    struct Node *root;
    struct Node *leftNode;
    struct Node *rightNode;

    // Important step - Create the root node
    root = (struct Node *)malloc(sizeof(struct Node));

    root->data = 50;
    root->left = NULL;
    root->right = NULL;

    // Important step - Create the left child
    leftNode = (struct Node *)malloc(sizeof(struct Node));

    leftNode->data = 30;
    leftNode->left = NULL;
    leftNode->right = NULL;

    // Important step - Create the right child
    rightNode = (struct Node *)malloc(sizeof(struct Node));

    rightNode->data = 70;
    rightNode->left = NULL;
    rightNode->right = NULL;

    // Important step - Connect children with root
    root->left = leftNode;
    root->right = rightNode;

    printf("Root = %d\n", root->data);
    printf("Left Child = %d\n", root->left->data);
    printf("Right Child = %d\n", root->right->data);

    return 0;
}

/*
    Theory:

    A Binary Search Tree (BST) is a binary tree in which
    elements follow a specific ordering rule.

    For every node:

        Left Subtree < Root < Right Subtree

    Example:

            50
           /  \
          30   70

    Here:

        30 < 50
        70 > 50

    Therefore, the tree follows the BST property.

    Algorithm:

    1. Define the Node structure.
    2. Create memory for the root node.
    3. Store 50 in the root.
    4. Set the left and right pointers of root to NULL.
    5. Create memory for the left child.
    6. Store 30 in the left child.
    7. Create memory for the right child.
    8. Store 70 in the right child.
    9. Connect the left and right children with the root.
    10. Display the nodes.

    Time Complexity:

    O(1)

    Space Complexity:

    O(1)
*/