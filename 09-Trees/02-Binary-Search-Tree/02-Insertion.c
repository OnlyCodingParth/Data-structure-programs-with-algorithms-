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

// Important step - Insert a value into the BST
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

    root = insert(root, 50);
    insert(root, 30);
    insert(root, 70);
    insert(root, 20);
    insert(root, 40);
    insert(root, 60);
    insert(root, 80);

    printf("BST after insertion:\n");

    inorder(root);

    return 0;
}

/*
    Theory:

    Insertion in a Binary Search Tree means adding a new
    value while maintaining the BST property.

    BST property:

        Left Subtree < Root < Right Subtree

    Example:

            50
           /  \
          30   70

    If we insert 40:

        40 < 50
        Go to left.

        40 > 30
        Go to right.

    Therefore, 40 is inserted as the right child of 30.

    Algorithm:

    1. Start from the root.
    2. If root is NULL, create a new node.
    3. If the value is smaller than the current node,
       move to the left subtree.
    4. If the value is greater than the current node,
       move to the right subtree.
    5. Repeat until an empty position is found.
    6. Create the new node at that position.
    7. Return the root.

    Time Complexity:

    Average Case: O(log n)
    Worst Case: O(n)

    Space Complexity:

    Average Case: O(log n)
    Worst Case: O(n)

    The space complexity is due to recursive function calls.
*/