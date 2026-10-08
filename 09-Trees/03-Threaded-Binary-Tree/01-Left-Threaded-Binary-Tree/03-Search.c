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

struct Node* search(struct Node *root, int value)
{
    struct Node *current = root;

    while (current != NULL)
    {
        if (current->data == value)
        {
            return current;
        }

        if (value < current->data)
        {
            /*
                Important step - move left only if
                left is an actual child.
            */
            if (current->leftThread == 1)
            {
                return NULL;
            }

            current = current->left;
        }
        else
        {
            current = current->right;
        }
    }

    return NULL;
}

int main()
{
    struct Node *root;
    struct Node *node20;
    struct Node *node30;
    struct Node *node40;
    struct Node *node70;
    struct Node *result;

    int value;

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

    printf("Enter value to search: ");
    scanf("%d", &value);

    result = search(root, value);

    if (result != NULL)
    {
        printf("Value %d found in the tree.\n", value);
    }
    else
    {
        printf("Value %d not found in the tree.\n", value);
    }

    return 0;
}

/*
========================================================
LEFT-THREADED BINARY TREE - SEARCH
========================================================

THEORY:
Searching in a Left-Threaded Binary Tree is similar
to searching in a Binary Search Tree when the tree
maintains BST ordering.

The important difference is that a left pointer may
contain an inorder predecessor thread instead of an
actual child.

Therefore, before moving to the left, we must check
leftThread.

leftThread = 0:
The left pointer is a real child.

leftThread = 1:
The left pointer is a thread, so we must not follow it
as a child.

ALGORITHM:
1. Start from the root.
2. Compare the required value with current node.
3. If both values are equal, return the node.
4. If the required value is smaller:
   - Check leftThread.
   - If leftThread is 1, the value is not present
     in the left subtree.
   - Otherwise move to the left child.
5. If the required value is greater, move to the
   right child.
6. Continue until the value is found or current
   becomes NULL.

TIME COMPLEXITY:
Average case: O(log n)
Worst case: O(n)

SPACE COMPLEXITY:
O(1)

The search is iterative, so no recursive stack is used.

========================================================
*/