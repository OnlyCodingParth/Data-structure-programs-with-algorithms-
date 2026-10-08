#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};

// Important step - Create a new node
struct Node *createNode(int value)
{
    struct Node *newNode;

    newNode = (struct Node *)malloc(sizeof(struct Node));

    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}

// Important step - Insert a value into BST
struct Node *insert(struct Node *root, int value)
{
    if (root == NULL)
    {
        return createNode(value);
    }

    if (value < root->data)
    {
        root->left = insert(root->left, value);
    }
    else if (value > root->data)
    {
        root->right = insert(root->right, value);
    }

    return root;
}

// Important step - Find the minimum node
struct Node *findMin(struct Node *root)
{
    while (root->left != NULL)
    {
        root = root->left;
    }

    return root;
}

// Important step - Delete a value from BST
struct Node *deleteNode(struct Node *root, int value)
{
    struct Node *temp;

    if (root == NULL)
    {
        return root;
    }

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
        // Case 1 and Case 2 - Node has zero or one child
        if (root->left == NULL)
        {
            temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL)
        {
            temp = root->left;
            free(root);
            return temp;
        }

        // Case 3 - Node has two children
        temp = findMin(root->right);

        root->data = temp->data;

        root->right = deleteNode(root->right, temp->data);
    }

    return root;
}

// Important step - Display BST using inorder traversal
void inorder(struct Node *root)
{
    if (root != NULL)
    {
        inorder(root->left);

        printf("%d ", root->data);

        inorder(root->right);
    }
}

int main()
{
    struct Node *root = NULL;
    int value;

    root = insert(root, 50);
    insert(root, 30);
    insert(root, 70);
    insert(root, 20);
    insert(root, 40);
    insert(root, 60);
    insert(root, 80);

    printf("BST before deletion:\n");
    inorder(root);

    printf("\n\nEnter value to delete: ");
    scanf("%d", &value);

    root = deleteNode(root, value);

    printf("\nBST after deletion:\n");
    inorder(root);

    return 0;
}

/*
    Theory:

    Deletion in a Binary Search Tree removes a node while
    maintaining the BST property.

    There are three main cases:

    Case 1:
    Node has no children.

    The node is simply deleted.

    Case 2:
    Node has one child.

    The node is replaced by its child.

    Case 3:
    Node has two children.

    The node is replaced by its inorder successor,
    which is the minimum value in the right subtree.

    Algorithm:

    1. Start from the root.
    2. If root is NULL, return NULL.
    3. If the value is smaller than root data,
       recursively delete from the left subtree.
    4. If the value is greater than root data,
       recursively delete from the right subtree.
    5. If the value is found:
       a. If the node has no left child,
          replace it with its right child.
       b. If the node has no right child,
          replace it with its left child.
       c. If the node has two children,
          find the minimum node in the right subtree.
       d. Copy its value into the current node.
       e. Delete the duplicate node from the right subtree.
    6. Return the root.

    Time Complexity:

    Average Case: O(log n)
    Worst Case: O(n)

    Space Complexity:

    Average Case: O(log n)
    Worst Case: O(n)

    The space complexity is due to recursive function calls.
*/