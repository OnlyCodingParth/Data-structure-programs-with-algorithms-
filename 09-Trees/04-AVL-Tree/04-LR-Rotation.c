#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    int height;
    struct Node *left;
    struct Node *right;
};

int height(struct Node *root)
{
    if (root == NULL)
        return 0;

    return root->height;
}

int max(int a, int b)
{
    return (a > b) ? a : b;
}

struct Node *createNode(int value)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));

    newNode->data = value;
    newNode->height = 1;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}

struct Node *rightRotate(struct Node *root)
{
    struct Node *temp = root->left;
    struct Node *subtree = temp->right;

    // Important step - Perform right rotation
    temp->right = root;
    root->left = subtree;

    root->height = 1 + max(height(root->left), height(root->right));
    temp->height = 1 + max(height(temp->left), height(temp->right));

    return temp;
}

struct Node *leftRotate(struct Node *root)
{
    struct Node *temp = root->right;
    struct Node *subtree = temp->left;

    // Important step - Perform left rotation
    temp->left = root;
    root->right = subtree;

    root->height = 1 + max(height(root->left), height(root->right));
    temp->height = 1 + max(height(temp->left), height(temp->right));

    return temp;
}

void preorder(struct Node *root)
{
    if (root != NULL)
    {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

int main()
{
    struct Node *root;
    struct Node *leftChild;
    struct Node *middleNode;

    // Create an LR-unbalanced tree
    root = createNode(30);
    leftChild = createNode(10);
    middleNode = createNode(20);

    root->left = leftChild;
    leftChild->right = middleNode;

    printf("Before LR Rotation: ");
    preorder(root);

    // Important step - First perform left rotation
    root->left = leftRotate(root->left);

    // Important step - Then perform right rotation
    root = rightRotate(root);

    printf("\nAfter LR Rotation: ");
    preorder(root);

    printf("\n");

    return 0;
}

/*
--------------------------------------------------
THEORY
--------------------------------------------------

LR Rotation:
LR means Left-Right imbalance.

It occurs when a new node is inserted into
the right subtree of the left child.

Example:

        30
       /
      10
        \
         20

Two rotations are required.

Step 1:
Perform Left Rotation on the left child.

Step 2:
Perform Right Rotation on the root.

Final tree:

        20
       /  \
      10   30

--------------------------------------------------
ALGORITHM
--------------------------------------------------

1. Identify the LR imbalance.
2. Perform Left Rotation on the left child.
3. Perform Right Rotation on the unbalanced node.
4. Return the new root.

--------------------------------------------------
TIME COMPLEXITY
--------------------------------------------------

O(1)

--------------------------------------------------
SPACE COMPLEXITY
--------------------------------------------------

O(1)

--------------------------------------------------
*/