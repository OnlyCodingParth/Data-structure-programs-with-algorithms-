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

void inorder(struct Node *root)
{
    struct Node *current = root;

    if (current == NULL)
    {
        return;
    }

    /* Important step - move to the leftmost node */
    while (current->left != NULL &&
           current->leftThread == 0)
    {
        current = current->left;
    }

    while (current != NULL)
    {
        printf("%d ", current->data);

        /* Important step - follow inorder successor */
        if (current->rightThread == 1)
        {
            current = current->right;
        }
        else
        {
            current = current->right;

            while (current != NULL &&
                   current->leftThread == 0 &&
                   current->left != NULL)
            {
                current = current->left;
            }
        }
    }
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

    printf("Inorder Traversal: ");

    inorder(root);

    printf("\n");

    return 0;
}

/*
========================================================
DOUBLE-THREADED BINARY TREE - INORDER TRAVERSAL
========================================================

THEORY:

Inorder traversal follows:

Left -> Root -> Right

A double-threaded tree allows inorder traversal without
recursion and without an explicit stack.

ALGORITHM:

1. Start from root.
2. Move to the leftmost node.
3. Print the current node.
4. If rightThread is 1:
   - Follow the right pointer directly.
5. Otherwise:
   - Move to the right child.
   - Move to its leftmost node.
6. Repeat until current becomes NULL.

TIME COMPLEXITY:

O(n)

SPACE COMPLEXITY:

O(1)

No stack or recursion is required.

========================================================
*/