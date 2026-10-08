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

int getBalance(struct Node *root)
{
    if (root == NULL)
        return 0;

    return height(root->left) - height(root->right);
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

// Find the node with minimum value
struct Node *minimumNode(struct Node *root)
{
    struct Node *temp = root;

    while (temp->left != NULL)
        temp = temp->left;

    return temp;
}

// Delete a value from AVL tree
struct Node *deleteNode(struct Node *root, int value)
{
    if (root == NULL)
        return root;

    // Search for the node
    if (value < root->data)
    {
        root->left = deleteNode(root->left, value);
    }
    else if (value > root->data)
    {
        root->right = deleteNode(root->right, value);
    }
    else
    {
        // Node with no child
        if (root->left == NULL && root->right == NULL)
        {
            free(root);
            return NULL;
        }

        // Node with only right child
        if (root->left == NULL)
        {
            struct Node *temp = root->right;
            free(root);
            return temp;
        }

        // Node with only left child
        if (root->right == NULL)
        {
            struct Node *temp = root->left;
            free(root);
            return temp;
        }

        // Node with two children
        struct Node *temp = minimumNode(root->right);

        // Important step - Replace with inorder successor
        root->data = temp->data;

        root->right = deleteNode(root->right, temp->data);
    }

    // Important step - Update height after deletion
    root->height = 1 + max(height(root->left), height(root->right));

    int balance = getBalance(root);

    // LL Case
    if (balance > 1 && getBalance(root->left) >= 0)
        return rightRotate(root);

    // LR Case
    if (balance > 1 && getBalance(root->left) < 0)
    {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    // RR Case
    if (balance < -1 && getBalance(root->right) <= 0)
        return leftRotate(root);

    // RL Case
    if (balance < -1 && getBalance(root->right) > 0)
    {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}

// Insert a value into AVL tree
struct Node *insert(struct Node *root, int value)
{
    if (root == NULL)
        return createNode(value);

    if (value < root->data)
        root->left = insert(root->left, value);
    else if (value > root->data)
        root->right = insert(root->right, value);
    else
        return root;

    root->height = 1 + max(height(root->left), height(root->right));

    int balance = getBalance(root);

    if (balance > 1 && value < root->left->data)
        return rightRotate(root);

    if (balance < -1 && value > root->right->data)
        return leftRotate(root);

    if (balance > 1 && value > root->left->data)
    {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    if (balance < -1 && value < root->right->data)
    {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}

void inorder(struct Node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
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
    struct Node *root = NULL;
    int n, value, deleteValue, i;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    printf("Enter values:\n");

    for (i = 0; i < n; i++)
    {
        scanf("%d", &value);

        root = insert(root, value);
    }

    printf("\nBefore Deletion - Inorder: ");
    inorder(root);

    printf("\nBefore Deletion - Preorder: ");
    preorder(root);

    printf("\n\nEnter value to delete: ");
    scanf("%d", &deleteValue);

    // Important step - Delete value and rebalance AVL tree
    root = deleteNode(root, deleteValue);

    printf("\nAfter Deletion - Inorder: ");
    inorder(root);

    printf("\nAfter Deletion - Preorder: ");
    preorder(root);

    printf("\n");

    return 0;
}

/*
--------------------------------------------------
THEORY
--------------------------------------------------

AVL Deletion:
Deletion in an AVL tree follows the normal BST
deletion process and then restores the AVL balance.

Three deletion cases exist:

1. Node with no child
2. Node with one child
3. Node with two children

For a node with two children, the inorder
successor is used.

After deletion:

1. Update height.
2. Calculate balance factor.
3. Perform required rotation.

Possible cases:

LL -> Right Rotation
RR -> Left Rotation
LR -> Left Rotation + Right Rotation
RL -> Right Rotation + Left Rotation

--------------------------------------------------
ALGORITHM
--------------------------------------------------

1. Search for the node to delete.
2. Delete it using BST deletion.
3. Update the height of affected nodes.
4. Calculate the balance factor.
5. If the node becomes unbalanced:
   - LL -> Right Rotation
   - RR -> Left Rotation
   - LR -> Left + Right Rotation
   - RL -> Right + Left Rotation
6. Return the balanced AVL tree.

--------------------------------------------------
TIME COMPLEXITY
--------------------------------------------------

Deletion: O(log n)

--------------------------------------------------
SPACE COMPLEXITY
--------------------------------------------------

O(log n) auxiliary space because of recursion.

--------------------------------------------------
*/