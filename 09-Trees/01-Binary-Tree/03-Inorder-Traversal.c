#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};

// Important step - Inorder traversal
// Order: Left -> Root -> Right
void inorder(struct Node *root)
{
    if (root != NULL)
    {
        inorder(root->left);

        printf("%d ", root->data);

        inorder(root->right);
    }
}

int main()
{
    struct Node *root;
    struct Node *leftNode;
    struct Node *rightNode;

    // Important step - Create root node
    root = (struct Node *)malloc(sizeof(struct Node));

    root->data = 10;
    root->left = NULL;
    root->right = NULL;

    // Important step - Create left child
    leftNode = (struct Node *)malloc(sizeof(struct Node));

    leftNode->data = 20;
    leftNode->left = NULL;
    leftNode->right = NULL;

    // Important step - Create right child
    rightNode = (struct Node *)malloc(sizeof(struct Node));

    rightNode->data = 30;
    rightNode->left = NULL;
    rightNode->right = NULL;

    // Important step - Connect children
    root->left = leftNode;
    root->right = rightNode;

    printf("Inorder Traversal: ");

    inorder(root);

    return 0;
}

/*
    Theory:

    Inorder traversal visits nodes in the following order:

    Left -> Root -> Right

    For the tree:

            10
           /  \
          20   30

    Inorder:
    20 10 30

    Algorithm:

    1. Start from the root node.
    2. Recursively traverse the left subtree.
    3. Visit and print the root node.
    4. Recursively traverse the right subtree.
    5. Stop when the current node becomes NULL.

    Time Complexity:

    O(n)

    Space Complexity:

    O(h)

    Where h is the height of the tree.
*/