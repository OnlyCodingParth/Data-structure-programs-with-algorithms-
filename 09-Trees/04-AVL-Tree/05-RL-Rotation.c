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
    struct Node *rightChild;
    struct Node *middleNode;

    // Create an RL-unbalanced tree
    root = createNode(10);
    rightChild = createNode(30);
    middleNode = createNode(20);

    root->right = rightChild;
    rightChild->left = middleNode;

    printf("Before RL Rotation: ");
    preorder(root);

    // Important step - First perform right rotation
    root->right = rightRotate(root->right);

    // Important step - Then perform left rotation
    root = leftRotate(root);

    printf("\nAfter RL Rotation: ");
    preorder(root);

    printf("\n");

    return 0;
}

/*
--------------------------------------------------
THEORY
--------------------------------------------------

RL Rotation:
RL means Right-Left imbalance.

It occurs when a new node is inserted into
the left subtree of the right child.

Example:

    10
      \
       30
      /
     20

Two rotations are required.

Step 1:
Perform Right Rotation on the right child.

Step 2:
Perform Left Rotation on the root.

Final tree:

        20
       /  \
      10   30

--------------------------------------------------
ALGORITHM
--------------------------------------------------

1. Identify the RL imbalance.
2. Perform Right Rotation on the right child.
3. Perform Left Rotation on the unbalanced node.
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