#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
    int leftThread;
};

struct Node* createNode(int value)
{
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));

    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->leftThread = 0;

    return newNode;
}

struct Node* insert(struct Node *root, int value)
{
    struct Node *current = root;
    struct Node *parent = NULL;

    while (current != NULL)
    {
        parent = current;

        if (value == current->data)
        {
            printf("Duplicate value is not allowed.\n");
            return root;
        }

        if (value < current->data)
        {
            /*
                Important step - if left pointer is a thread,
                the new node must be inserted here.
            */
            if (current->leftThread == 1)
            {
                break;
            }

            current = current->left;
        }
        else
        {
            current = current->right;
        }
    }

    if (parent == NULL)
    {
        return createNode(value);
    }

    struct Node *newNode = createNode(value);

    if (value < parent->data)
    {
        /*
            Important step - new node takes the old
            inorder predecessor thread.
        */
        newNode->left = parent->left;
        newNode->leftThread = 1;

        parent->left = newNode;
        parent->leftThread = 0;
    }
    else
    {
        /*
            New node becomes the right child.

            Its left pointer becomes a thread to
            its inorder predecessor.
        */
        newNode->left = parent;
        newNode->leftThread = 1;

        parent->right = newNode;
    }

    return root;
}

void inorder(struct Node *root)
{
    struct Node *current = root;

    if (current == NULL)
    {
        return;
    }

    while (current->left != NULL && current->leftThread == 0)
    {
        current = current->left;
    }

    while (current != NULL)
    {
        printf("%d ", current->data);

        if (current->right == NULL)
        {
            break;
        }

        current = current->right;

        while (current->left != NULL &&
               current->leftThread == 0)
        {
            current = current->left;
        }
    }
}

int main()
{
    struct Node *root = NULL;
    int n;
    int value;
    int i;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    printf("Enter values:\n");

    for (i = 0; i < n; i++)
    {
        scanf("%d", &value);

        root = insert(root, value);
    }

    printf("\nInorder Traversal: ");

    inorder(root);

    printf("\n");

    return 0;
}

/*
========================================================
LEFT-THREADED BINARY TREE - INSERTION
========================================================

THEORY:
Insertion in a Left-Threaded Binary Tree must maintain
both:

1. The Binary Search Tree property.
2. The left-thread property.

For every node:

Left Subtree < Node < Right Subtree

A left thread points to the inorder predecessor.

When a new node is inserted as a left child, the new
node takes the parent's previous left thread.

Example:

Before insertion:

       50
      /
    30

Suppose 20 is inserted.

The new structure becomes:

       50
      /
    30
   /
 20

Node 20 has no inorder predecessor, so its left pointer
can point to NULL as a thread.

When a node is inserted as a right child, its inorder
predecessor is normally its parent or a suitable node
according to the BST structure.

ALGORITHM:
1. Start from the root.
2. Compare the new value with the current node.
3. If the value is equal, do not insert it.
4. If the value is smaller:
   - If leftThread is 1, stop searching.
   - Otherwise move to the left child.
5. If the value is greater:
   - Move to the right child.
6. Create the new node.
7. If the new node is inserted on the left:
   - Store the old left thread in the new node.
   - Set newNode->leftThread = 1.
   - Make the new node the parent's left child.
   - Set parent->leftThread = 0.
8. If the new node is inserted on the right:
   - Make it the parent's right child.
   - Set its left pointer to the inorder predecessor.
   - Set leftThread = 1.

TIME COMPLEXITY:
Average case: O(log n)
Worst case: O(n)

SPACE COMPLEXITY:
O(1) auxiliary space.

One new node requires O(1) memory.

IMPORTANT:
The leftThread flag must always correctly indicate
whether the left pointer is:

0 -> Actual left child
1 -> Inorder predecessor thread

========================================================
*/