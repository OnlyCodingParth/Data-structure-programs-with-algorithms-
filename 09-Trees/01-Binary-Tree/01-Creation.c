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

    // Important step - Store data in root node
    root->data = 10;

    // Important step - Initially set child pointers to NULL
    root->left = NULL;
    root->right = NULL;

    // Important step - Create the left child
    leftNode = (struct Node *)malloc(sizeof(struct Node));

    leftNode->data = 20;
    leftNode->left = NULL;
    leftNode->right = NULL;

    // Important step - Create the right child
    rightNode = (struct Node *)malloc(sizeof(struct Node));

    rightNode->data = 30;
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

    A binary tree is a non-linear data structure in which
    each node can have at most two children.

    The two children are called:
    1. Left Child
    2. Right Child

    Each node contains:
    1. Data
    2. Pointer to the left child
    3. Pointer to the right child

    In this program, a binary tree with one root node
    and two child nodes is created.

    Tree Structure:

             10
            /  \
           20   30

    Algorithm:

    1. Define a Node structure containing data,
       left pointer and right pointer.
    2. Create memory for the root node.
    3. Store data in the root node.
    4. Set the left and right pointers of root to NULL.
    5. Create memory for the left child.
    6. Store data in the left child.
    7. Set its left and right pointers to NULL.
    8. Create memory for the right child.
    9. Store data in the right child.
    10. Set its left and right pointers to NULL.
    11. Connect the left and right children with the root.
    12. Display the tree nodes.

    Time Complexity:

    O(1)

    Space Complexity:

    O(n)

    Here, n represents the number of nodes created.
*/