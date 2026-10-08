#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
    int rightThread;
};

struct Node* createNode(int value)
{
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));

    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->rightThread = 0;

    return newNode;
}

int main()
{
    struct Node *root;
    struct Node *node20;
    struct Node *node30;
    struct Node *node40;
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
        Tree:

              50
             /  \
           30    70
          /  \
        20    40

        Inorder:
        20 30 40 50 70

        Right threads:

        20 -> 30
        40 -> 50
        70 -> NULL
    */

    node20->right = node30;
    node20->rightThread = 1;

    node40->right = root;
    node40->rightThread = 1;

    node70->right = NULL;
    node70->rightThread = 1;

    printf("Right-Threaded Binary Tree created successfully.\n");

    printf("\nRoot = %d\n", root->data);

    printf("Left child of root = %d\n", root->left->data);
    printf("Right child of root = %d\n", root->right->data);

    printf("\nRight threads:\n");
    printf("Node 20 -> %d\n", node20->right->data);
    printf("Node 40 -> %d\n", node40->right->data);
    printf("Node 70 -> NULL\n");

    return 0;
}

/*
========================================================
RIGHT-THREADED BINARY TREE - CREATION
========================================================

THEORY:

A Right-Threaded Binary Tree is a binary tree in which
NULL right pointers are replaced with threads pointing
to the inorder successor of the node.

A flag called rightThread is used to identify whether
the right pointer is:

0 -> Actual right child
1 -> Inorder successor thread

Example:

          50
        /    \
      30      70
     /  \
   20   40

Inorder sequence:

20 30 40 50 70

Therefore:

20 -> 30
40 -> 50
70 -> NULL

These are right threads.

ALGORITHM:

1. Create the required nodes.
2. Connect the nodes as a normal binary tree.
3. Find nodes having no right child.
4. Replace their NULL right pointer with their
   inorder successor.
5. Set rightThread = 1.
6. Keep rightThread = 0 for actual right children.

TIME COMPLEXITY:

Creating n nodes takes O(n) time.

SPACE COMPLEXITY:

O(n) space is required for n nodes.

IMPORTANT:

rightThread = 0 means right is an actual child.

rightThread = 1 means right is an inorder successor
thread.

========================================================
*/