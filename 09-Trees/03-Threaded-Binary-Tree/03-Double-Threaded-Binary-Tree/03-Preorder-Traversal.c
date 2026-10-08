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

void preorder(struct Node *root)
{
    struct Node *current = root;

    while (current != NULL)
    {
        printf("%d ", current->data);

        if (current->leftThread == 0 &&
            current->left != NULL)
        {
            current = current->left;
        }
        else if (current->rightThread == 0 &&
                 current->right != NULL)
        {
            current = current->right;
        }
        else
        {
            /*
                Important step - move through ancestors
                using inorder successor threads until a
                node having a real right child is found.
            */
            while (current != NULL &&
                   current->rightThread == 1)
            {
                current = current->right;
            }

            if (current != NULL)
            {
                current = current->right;
            }
            else
            {
                break;
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

    printf("Preorder Traversal: ");

    preorder(root);

    printf("\n");

    return 0;
}

/*
========================================================
DOUBLE-THREADED BINARY TREE - PREORDER TRAVERSAL
========================================================

THEORY:

Preorder traversal follows:

Root -> Left -> Right

In a threaded tree, thread pointers must never be
treated as actual children.

ALGORITHM:

1. Start from the root.
2. Visit the current node.
3. If it has a real left child:
   - Move to the left child.
4. Otherwise, if it has a real right child:
   - Move to the right child.
5. Otherwise follow right threads until a node with
   a real right child is found.
6. Move to that real right child.
7. Continue until traversal is complete.

TIME COMPLEXITY:

O(n)

SPACE COMPLEXITY:

O(1)

========================================================
*/