#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};

// Important step - Count leaf nodes recursively
int countLeafNodes(struct Node *root)
{
    if (root == NULL)
    {
        return 0;
    }

    // Important step - Check whether current node is a leaf
    if (root->left == NULL && root->right == NULL)
    {
        return 1;
    }

    return countLeafNodes(root->left) +
           countLeafNodes(root->right);
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

    printf("Number of Leaf Nodes = %d\n",
           countLeafNodes(root));

    return 0;
}

/*
    Theory:

    A leaf node is a node that has no children.

    In other words:

    left == NULL
    AND
    right == NULL

    For the tree:

            10
           /  \
          20   30

    Leaf nodes are:

    20 and 30

    Therefore:

    Number of Leaf Nodes = 2

    Algorithm:

    1. Start from the root.
    2. If the root is NULL, return 0.
    3. Check whether the current node has no left
       and right child.
    4. If it is a leaf node, return 1.
    5. Otherwise, recursively count leaf nodes
       in the left subtree.
    6. Recursively count leaf nodes in the right subtree.
    7. Add both results.
    8. Return the total count.

    Time Complexity:

    O(n)

    Space Complexity:

    O(h)

    Where h is the height of the tree.
*/