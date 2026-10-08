#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    int height;
    struct Node *left;
    struct Node *right;
};

// Find height of a node
int height(struct Node *root)
{
    if (root == NULL)
        return 0;

    return root->height;
}

// Find maximum of two numbers
int max(int a, int b)
{
    return (a > b) ? a : b;
}

// Create a new node
struct Node *createNode(int value)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));

    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->height = 1;

    return newNode;
}

// Find balance factor
int getBalance(struct Node *root)
{
    if (root == NULL)
        return 0;

    return height(root->left) - height(root->right);
}

// Right rotation
struct Node *rightRotate(struct Node *root)
{
    struct Node *temp = root->left;
    struct Node *rightSubtree = temp->right;

    // Important step - Perform right rotation
    temp->right = root;
    root->left = rightSubtree;

    root->height = 1 + max(height(root->left), height(root->right));
    temp->height = 1 + max(height(temp->left), height(temp->right));

    return temp;
}

// Left rotation
struct Node *leftRotate(struct Node *root)
{
    struct Node *temp = root->right;
    struct Node *leftSubtree = temp->left;

    // Important step - Perform left rotation
    temp->left = root;
    root->right = leftSubtree;

    root->height = 1 + max(height(root->left), height(root->right));
    temp->height = 1 + max(height(temp->left), height(temp->right));

    return temp;
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

    // Important step - Update height after insertion
    root->height = 1 + max(height(root->left), height(root->right));

    int balance = getBalance(root);

    // LL Case
    if (balance > 1 && value < root->left->data)
        return rightRotate(root);

    // RR Case
    if (balance < -1 && value > root->right->data)
        return leftRotate(root);

    // LR Case
    if (balance > 1 && value > root->left->data)
    {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    // RL Case
    if (balance < -1 && value < root->right->data)
    {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}

// Inorder traversal
void inorder(struct Node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

// Preorder traversal
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
    int n, value, i;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    printf("Enter values:\n");

    for (i = 0; i < n; i++)
    {
        scanf("%d", &value);

        // Important step - Insert value and automatically balance AVL tree
        root = insert(root, value);
    }

    printf("\nInorder Traversal: ");
    inorder(root);

    printf("\nPreorder Traversal: ");
    preorder(root);

    printf("\n");

    return 0;
}

/*
--------------------------------------------------
THEORY
--------------------------------------------------

AVL Tree:
An AVL tree is a self-balancing Binary Search Tree.

For every node:

Balance Factor = Height of Left Subtree
                 - Height of Right Subtree

Allowed balance factors are:

-1, 0, +1

If the balance factor becomes less than -1
or greater than +1, the tree becomes unbalanced.

AVL insertion uses rotations to restore balance.

Four cases are possible:

1. LL - Left Left
2. RR - Right Right
3. LR - Left Right
4. RL - Right Left

--------------------------------------------------
ALGORITHM
--------------------------------------------------

1. Start with an empty AVL tree.
2. Insert the value according to BST rules.
3. Update the height of every affected node.
4. Calculate the balance factor.
5. If the tree becomes unbalanced:
   - LL -> Right Rotation
   - RR -> Left Rotation
   - LR -> Left Rotation followed by Right Rotation
   - RL -> Right Rotation followed by Left Rotation
6. Return the balanced tree.

--------------------------------------------------
TIME COMPLEXITY
--------------------------------------------------

Insertion: O(log n)

--------------------------------------------------
SPACE COMPLEXITY
--------------------------------------------------

O(log n) auxiliary space because of recursion.

--------------------------------------------------
*/