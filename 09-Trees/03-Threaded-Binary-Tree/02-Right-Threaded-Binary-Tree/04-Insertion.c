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

struct Node* insert(struct Node *root, int value)
{
    struct Node *current = root;
    struct Node *parent = NULL;

    while (current != NULL)
    {
        parent = current;

        if (value == current->data)
        {
            printf("Duplicate value is not allowed.\n");
            return root;
        }

        if (value < current->data)
        {
            current = current->left;
        }
        else
        {
            /*
                Important step - if right pointer is
                a thread, the new node must be inserted here.
            */
            if (current->rightThread == 1)
            {
                break;
            }

            current = current->right;
        }
    }

    if (parent == NULL)
    {
        return createNode(value);
    }

    struct Node *newNode = createNode(value);

    if (value < parent->data)
    {
        /*
            New node becomes the left child.

            Its inorder successor is the parent,
            so its right pointer becomes a thread
            to the parent.
        */
        newNode->right = parent;
        newNode->rightThread = 1;

        parent->left = newNode;
    }
    else
    {
        /*
            New node becomes the right child.

            The new node takes the old right thread
            of the parent.
        */
        newNode->right = parent->right;
        newNode->rightThread = 1;

        parent->right = newNode;
        parent->rightThread = 0;
    }

    return root;
}

void inorder(struct Node *root)
{
    struct Node *current = root;

    if (current == NULL)
    {
        return;
    }

    while (current->left != NULL)
    {
        current = current->left;
    }

    while (current != NULL)
    {
        printf("%d ", current->data);

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
    struct Node *root = NULL;

    int n;
    int value;
    int i;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    printf("Enter values:\n");

    for (i = 0; i < n; i++)
    {
        scanf("%d", &value);

        root = insert(root, value);
    }

    printf("\nInorder Traversal: ");

    inorder(root);

    printf("\n");

    return 0;
}

/*
========================================================
RIGHT-THREADED BINARY TREE - INSERTION
========================================================

THEORY:

Insertion in a Right-Threaded Binary Tree must maintain:

1. The Binary Search Tree property.
2. The right-thread property.

For every node:

Left Subtree < Node < Right Subtree

A right thread points to the inorder successor.

When a new node is inserted as a left child, the
new node's inorder successor is normally its parent.

Therefore:

newNode->right = parent

and:

newNode->rightThread = 1

When a new node is inserted as a right child, it takes
the parent's previous right thread.

ALGORITHM:

1. Start from the root.
2. Compare the new value with the current node.
3. If the value is equal, do not insert it.
4. If the value is smaller:
   - Move to the left child.
5. If the value is greater:
   - If rightThread is 1, stop searching.
   - Otherwise move to the right child.
6. Create the new node.
7. If the new node is inserted on the left:
   - Set newNode->right to parent.
   - Set newNode->rightThread = 1.
   - Make the new node the parent's left child.
8. If the new node is inserted on the right:
   - Copy the parent's old right thread into
     newNode->right.
   - Set newNode->rightThread = 1.
   - Make the new node the parent's right child.
   - Set parent->rightThread = 0.

TIME COMPLEXITY:

Average case: O(log n)

Worst case: O(n)

SPACE COMPLEXITY:

O(1) auxiliary space.

One new node requires O(1) memory.

IMPORTANT:

rightThread must always correctly indicate whether
the right pointer is:

0 -> Actual right child
1 -> Inorder successor thread

========================================================
*/