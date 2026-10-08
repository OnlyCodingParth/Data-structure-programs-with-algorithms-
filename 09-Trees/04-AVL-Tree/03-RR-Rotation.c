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

// Perform left rotation for RR case
struct Node *leftRotate(struct Node *root)
{
    struct Node *temp = root->right;
    struct Node *subtree = temp->left;

    // Important step - Move right child above root
    temp->left = root;

    // Important step - Connect the middle subtree
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
    struct Node *temp1;
    struct Node *temp2;

    // Create an RR-unbalanced tree
    root = createNode(10);
    temp1 = createNode(20);
    temp2 = createNode(30);

    root->right = temp1;
    temp1->right = temp2;

    printf("Before RR Rotation: ");
    preorder(root);

    // Important step - Apply left rotation
    root = leftRotate(root);

    printf("\nAfter RR Rotation: ");
    preorder(root);

    printf("\n");

    return 0;
}

/*
--------------------------------------------------
THEORY
--------------------------------------------------

RR Rotation:
RR means Right-Right imbalance.

It occurs when a new node is inserted into
the right subtree of the right child.

Example:

    10
      \
       20
         \
          30

Solution:

Perform a Left Rotation.

After rotation:

        20
       /  \
      10   30

--------------------------------------------------
ALGORITHM
--------------------------------------------------

1. Store the right child of the unbalanced node.
2. Store the left subtree of that right child.
3. Make the unbalanced node the left child.
4. Connect the stored subtree to the right of the old root.
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