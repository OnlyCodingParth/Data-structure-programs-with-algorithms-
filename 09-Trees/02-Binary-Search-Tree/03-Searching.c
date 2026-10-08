#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};

// Important step - Search for a value in BST
struct Node *search(struct Node *root, int value)
{
    if (root == NULL || root->data == value)
    {
        return root;
    }

    if (value < root->data)
    {
        return search(root->left, value);
    }

    return search(root->right, value);
}

// Important step - Insert nodes into BST
struct Node *insert(struct Node *root, int value)
{
    if (root == NULL)
    {
        struct Node *newNode;

        newNode = (struct Node *)malloc(sizeof(struct Node));

        newNode->data = value;
        newNode->left = NULL;
        newNode->right = NULL;

        return newNode;
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

int main()
{
    struct Node *root = NULL;
    struct Node *result;
    int value;

    root = insert(root, 50);
    insert(root, 30);
    insert(root, 70);
    insert(root, 20);
    insert(root, 40);
    insert(root, 60);
    insert(root, 80);

    printf("Enter value to search: ");
    scanf("%d", &value);

    result = search(root, value);

    if (result != NULL)
    {
        printf("Value %d is found in the BST.\n", value);
    }
    else
    {
        printf("Value %d is not found in the BST.\n", value);
    }

    return 0;
}

/*
    Theory:

    Searching in a Binary Search Tree uses the BST property
    to find a value efficiently.

    BST property:

        Left Subtree < Root < Right Subtree

    Therefore, at each node we can decide whether to search
    in the left subtree or the right subtree.

    Algorithm:

    1. Start from the root.
    2. If root is NULL, the value is not found.
    3. If root data is equal to the required value,
       the value is found.
    4. If the required value is smaller than root data,
       search in the left subtree.
    5. If the required value is greater than root data,
       search in the right subtree.
    6. Repeat until the value is found or NULL is reached.

    Time Complexity:

    Average Case: O(log n)
    Worst Case: O(n)

    Space Complexity:

    Average Case: O(log n)
    Worst Case: O(n)

    The space complexity is due to recursive function calls.
*/