#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
    int leftThread;
};

struct Node* createNode(int value)
{
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));

    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->leftThread = 0;

    return newNode;
}

int main()
{
    struct Node *root;
    struct Node *node20;
    struct Node *node30;
    struct Node *node40;
    struct Node *node50;
    struct Node *node70;

    root = createNode(50);
    node30 = createNode(30);
    node70 = createNode(70);
    node20 = createNode(20);
    node40 = createNode(40);

    root->left = node30;
    root->right = node70;

    node30->left = node20;
    node30->right = node40;

    /*
        Left-threaded links:

              50
             /  \
           30    70
          /  \
        20    40

        Inorder:
        20 30 40 50 70

        Left threads:

        20 has no left child,
        so its left pointer points to NULL
        because 20 has no inorder predecessor.

        40 has no left child,
        so its left pointer points to 30.

        70 has no left child,
        so its left pointer points to 50.
    */

    node20->left = NULL;
    node20->leftThread = 1;

    node40->left = node30;
    node40->leftThread = 1;

    node70->left = root;
    node70->leftThread = 1;

    printf("Left-Threaded Binary Tree created successfully.\n");

    printf("\nRoot = %d\n", root->data);

    printf("Left child of root = %d\n", root->left->data);
    printf("Right child of root = %d\n", root->right->data);

    printf("\nLeft threads:\n");
    printf("Node 20 -> NULL\n");
    printf("Node 40 -> %d\n", node40->left->data);
    printf("Node 70 -> %d\n", node70->left->data);

    return 0;
}

/*
========================================================
LEFT-THREADED BINARY TREE - CREATION
========================================================

THEORY:
A Left-Threaded Binary Tree is a binary tree in which
NULL left pointers are replaced with threads pointing
to the inorder predecessor of the node.

A flag called leftThread is used to identify whether
the left pointer is:

0 -> Actual left child
1 -> Inorder predecessor thread

Example:

          50
        /    \
      30      70
     /  \
   20   40

Inorder sequence:

20 30 40 50 70

Therefore:

20 -> NULL
40 -> 30
70 -> 50

These are left threads.

ALGORITHM:
1. Create the required nodes.
2. Connect the nodes as a normal binary tree.
3. Find nodes having no left child.
4. Replace their NULL left pointer with their
   inorder predecessor.
5. Set leftThread = 1.
6. Keep leftThread = 0 for actual left children.

TIME COMPLEXITY:
Creating n nodes takes O(n) time.

SPACE COMPLEXITY:
O(n) space is required for n nodes.

IMPORTANT:
leftThread = 0 means left is an actual child.
leftThread = 1 means left is a thread.

========================================================
*/