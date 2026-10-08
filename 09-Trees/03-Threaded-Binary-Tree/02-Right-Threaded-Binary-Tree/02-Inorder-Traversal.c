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

void inorder(struct Node *root)
{
    struct Node *current = root;

    if (current == NULL)
    {
        return;
    }

    /* Important step - move to the leftmost node */
    while (current->left != NULL)
    {
        current = current->left;
    }

    while (current != NULL)
    {
        printf("%d ", current->data);

        /*
            Important step - if rightThread is 1,
            right pointer is the inorder successor.
        */
        if (current->rightThread == 1)
        {
            current = current->right;
        }
        else
        {
            current = current->right;

            while (current != NULL &&
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

    /*
        Create right threads:

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

    printf("Inorder Traversal: ");

    inorder(root);

    printf("\n");

    return 0;
}

/*
========================================================
RIGHT-THREADED BINARY TREE - INORDER TRAVERSAL
========================================================

THEORY:

In a Right-Threaded Binary Tree, NULL right pointers
can contain threads pointing to the inorder successor.

The rightThread flag tells us whether the right pointer
is a real child or a thread.

rightThread = 0:
Right pointer is an actual child.

rightThread = 1:
Right pointer is an inorder successor thread.

ALGORITHM:

1. Start from the root.
2. Move to the leftmost node.
3. Print the current node.
4. If rightThread is 1, follow the right thread.
5. Otherwise move to the right child.
6. From the right child, move to its leftmost node.
7. Continue until current becomes NULL.

TIME COMPLEXITY:

O(n)

Every node is visited once.

SPACE COMPLEXITY:

O(1)

No recursion or additional stack is required.

IMPORTANT:

The main advantage of threading is that inorder
traversal can be performed without recursion or
an explicit stack.

========================================================
*/