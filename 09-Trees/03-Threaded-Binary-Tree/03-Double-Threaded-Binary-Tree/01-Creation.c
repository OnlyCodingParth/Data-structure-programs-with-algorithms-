#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
    int leftThread;
    int rightThread;
};

struct Node* createNode(int value)
{
    struct Node *newNode =
        (struct Node*)malloc(sizeof(struct Node));

    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->leftThread = 0;
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

    /*
              50
             /  \
           30    70
          /  \
        20    40
    */

    root->left = node30;
    root->right = node70;

    node30->left = node20;
    node30->right = node40;

    /*
        Inorder:

        20 30 40 50 70

        Threads:

        20:
        left  -> NULL
        right -> 30

        40:
        left  -> 30
        right -> 50

        70:
        left  -> 50
        right -> NULL
    */

    node20->left = NULL;
    node20->leftThread = 1;

    node20->right = node30;
    node20->rightThread = 1;

    node40->left = node30;
    node40->leftThread = 1;

    node40->right = root;
    node40->rightThread = 1;

    node70->left = root;
    node70->leftThread = 1;

    node70->right = NULL;
    node70->rightThread = 1;

    printf("Double-Threaded Binary Tree created successfully.\n");

    return 0;
}

/*
========================================================
DOUBLE-THREADED BINARY TREE - CREATION
========================================================

THEORY:

A Double-Threaded Binary Tree uses both NULL left
pointers and NULL right pointers as threads.

Left thread:
Points to the inorder predecessor.

Right thread:
Points to the inorder successor.

FLAGS:

leftThread = 0
Left pointer is an actual child.

leftThread = 1
Left pointer is an inorder predecessor thread.

rightThread = 0
Right pointer is an actual child.

rightThread = 1
Right pointer is an inorder successor thread.

EXAMPLE:

          50
        /    \
      30      70
     /  \
   20   40

Inorder:

20 30 40 50 70

Threads:

20:
left  -> NULL
right -> 30

40:
left  -> 30
right -> 50

70:
left  -> 50
right -> NULL

ALGORITHM:

1. Create all required nodes.
2. Connect actual child pointers.
3. Find nodes having NULL left pointers.
4. Connect them to their inorder predecessors.
5. Set leftThread = 1.
6. Find nodes having NULL right pointers.
7. Connect them to their inorder successors.
8. Set rightThread = 1.

TIME COMPLEXITY:

O(n)

SPACE COMPLEXITY:

O(n)

========================================================
*/