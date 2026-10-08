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
            if (current->leftThread == 1)
            {
                break;
            }

            current = current->left;
        }
        else
        {
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
            Important step - new node becomes the
            left child.

            Its predecessor is the old left thread
            of the parent.

            Its successor is the parent.
        */

        newNode->left = parent->left;
        newNode->leftThread = 1;

        newNode->right = parent;
        newNode->rightThread = 1;

        parent->left = newNode;
        parent->leftThread = 0;
    }
    else
    {
        /*
            Important step - new node becomes the
            right child.

            Its predecessor is the parent.

            Its successor is the old right thread
            of the parent.
        */

        newNode->left = parent;
        newNode->leftThread = 1;

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

    while (current->left != NULL &&
           current->leftThread == 0)
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
DOUBLE-THREADED BINARY TREE - INSERTION
========================================================

THEORY:

Insertion must maintain both:

1. Binary Search Tree property.
2. Left and right thread relationships.

For a new LEFT child:

newNode->left
    = parent's old predecessor thread

newNode->right
    = parent

For a new RIGHT child:

newNode->left
    = parent

newNode->right
    = parent's old successor thread

The thread flags are then updated.

ALGORITHM:

1. Start from root.
2. Search for the correct insertion position.
3. Ignore left threads while moving left.
4. Ignore right threads while moving right.
5. Create a new node.
6. If inserting on the left:
   - Copy parent's predecessor thread.
   - Set new node's right thread to parent.
   - Connect new node as parent's left child.
   - Set parent->leftThread = 0.
7. If inserting on the right:
   - Set new node's left thread to parent.
   - Copy parent's successor thread.
   - Connect new node as parent's right child.
   - Set parent->rightThread = 0.

TIME COMPLEXITY:

Average case: O(log n)

Worst case: O(n)

SPACE COMPLEXITY:

O(1) auxiliary space.

One new node requires O(1) memory.

IMPORTANT:

Both thread flags must be updated correctly.

leftThread = 1
means predecessor thread.

rightThread = 1
means successor thread.

========================================================
*/