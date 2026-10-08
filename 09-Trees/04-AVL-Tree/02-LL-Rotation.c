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

// Perform right rotation for LL case
struct Node *rightRotate(struct Node *root)
{
    struct Node *temp = root->left;
    struct Node *subtree = temp->right;

    // Important step - Move left child above root
    temp->right = root;

    // Important step - Connect the middle subtree
    root->left = subtree;

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
    struct Node *temp1;
    struct Node *temp2;

    // Create an LL-unbalanced tree
    root = createNode(30);
    temp1 = createNode(20);
    temp2 = createNode(10);

    root->left = temp1;
    temp1->left = temp2;

    printf("Before LL Rotation: ");
    preorder(root);

    // Important step - Apply right rotation
    root = rightRotate(root);

    printf("\nAfter LL Rotation: ");
    preorder(root);

    printf("\n");

    return 0;
}

/*
--------------------------------------------------
THEORY
--------------------------------------------------

LL Rotation:
LL means Left-Left imbalance.

It occurs when a new node is inserted into
the left subtree of the left child.

Example:

        30
       /
      20
     /
    10

This tree is unbalanced.

Solution:

Perform a Right Rotation.

After rotation:

        20
       /  \
      10   30

--------------------------------------------------
ALGORITHM
--------------------------------------------------

1. Store the left child of the unbalanced node.
2. Store the right subtree of that left child.
3. Make the unbalanced node the right child.
4. Connect the stored subtree to the left of the old root.
5. Update heights.
6. Return the new root.

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