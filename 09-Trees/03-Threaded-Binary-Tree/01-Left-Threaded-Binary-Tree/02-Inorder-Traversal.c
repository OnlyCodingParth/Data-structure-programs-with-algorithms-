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

void inorder(struct Node *root)
{
    struct Node *current = root;

    if (current == NULL)
    {
        return;
    }

    /* Important step - go to the leftmost node */
    while (current->left != NULL && current->leftThread == 0)
    {
        current = current->left;
    }

    while (current != NULL)
    {
        printf("%d ", current->data);

        /* Important step - follow left thread */
        if (current->leftThread == 1)
        {
            current = current->right;
        }
        else
        {
            current = current->right;

            while (current != NULL &&
                   current->left != NULL &&
                   current->leftThread == 0)
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
        Create left threads.

        20 -> NULL
        40 -> 30
        70 -> 50
    */

    node20->left = NULL;
    node20->leftThread = 1;

    node40->left = node30;
    node40->leftThread = 1;

    node70->left = root;
    node70->leftThread = 1;

    printf("Inorder Traversal: ");

    inorder(root);

    printf("\n");

    return 0;
}

/*
========================================================
LEFT-THREADED BINARY TREE - INORDER TRAVERSAL
========================================================

THEORY:
In a Left-Threaded Binary Tree, NULL left pointers
can contain threads pointing to the inorder predecessor.

The leftThread flag tells us whether the left pointer
is a real child or a thread.

leftThread = 0:
Left pointer is an actual child.

leftThread = 1:
Left pointer is an inorder predecessor thread.

For inorder traversal, we move to the leftmost node
and then process the tree while respecting the threads.

ALGORITHM:
1. Start from the root.
2. Move to the leftmost node.
3. Print the current node.
4. If leftThread is 1, the left pointer is a thread.
5. Move to the right subtree.
6. If the right subtree exists, move to its leftmost node.
7. Continue until the current node becomes NULL.

TIME COMPLEXITY:
O(n)

Every node is visited once.

SPACE COMPLEXITY:
O(1)

No recursive stack or additional traversal stack
is required.

IMPORTANT:
The main advantage of threading is that traversal can
be performed without using recursion or an explicit stack.

========================================================
*/