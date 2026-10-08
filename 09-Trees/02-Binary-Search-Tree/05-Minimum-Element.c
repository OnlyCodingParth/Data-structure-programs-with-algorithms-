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

// Important step - Insert value into BST
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

// Important step - Find minimum element
int findMinimum(struct Node *root)
{
    while (root->left != NULL)
    {
        root = root->left;
    }

    return root->data;
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

    printf("Minimum Element = %d\n", findMinimum(root));

    return 0;
}

/*
    Theory:

    In a Binary Search Tree, the minimum element is always
    located at the leftmost node.

    Example:

            50
           /  \
          30   70
         /  \
        20   40

    The leftmost node is 20.

    Therefore:

    Minimum Element = 20

    Algorithm:

    1. Start from the root.
    2. Check whether the left child exists.
    3. If the left child exists, move to the left child.
    4. Continue moving left.
    5. When the left child becomes NULL,
       the current node contains the minimum value.
    6. Return the value.

    Time Complexity:

    Average Case: O(log n)
    Worst Case: O(n)

    Space Complexity:

    O(1)

    An iterative approach is used, so no recursive
    call stack is required.
*/