#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
    int leftThread;
    int rightThread;
};

struct Node* createNode(int value)
{
    struct Node *newNode =
        (struct Node*)malloc(sizeof(struct Node));

    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->leftThread = 0;
    newNode->rightThread = 0;

    return newNode;
}

struct Node* search(struct Node *root, int value)
{
    struct Node *current = root;

    while (current != NULL)
    {
        if (current->data == value)
        {
            return current;
        }

        if (value < current->data)
        {
            if (current->leftThread == 1)
            {
                return NULL;
            }

            current = current->left;
        }
        else
        {
            if (current->rightThread == 1)
            {
                return NULL;
            }

            current = current->right;
        }
    }

    return NULL;
}

int main()
{
    struct Node *root;
    struct Node *node20;
    struct Node *node30;
    struct Node *node40;
    struct Node *node70;
    struct Node *result;

    int value;

    root = createNode(50);
    node30 = createNode(30);
    node70 = createNode(70);
    node20 = createNode(20);
    node40 = createNode(40);

    root->left = node30;
    root->right = node70;

    node30->left = node20;
    node30->right = node40;

    node20->left = NULL;
    node20->leftThread = 1;

    node20->right = node30;
    node20->rightThread = 1;

    node40->left = node30;
    node40->leftThread = 1;

    node40->right = root;
    node40->rightThread = 1;

    node70->left = root;
    node70->leftThread = 1;

    node70->right = NULL;
    node70->rightThread = 1;

    printf("Enter value to search: ");
    scanf("%d", &value);

    result = search(root, value);

    if (result != NULL)
    {
        printf("Value %d found in the tree.\n", value);
    }
    else
    {
        printf("Value %d not found in the tree.\n", value);
    }

    return 0;
}

/*
========================================================
DOUBLE-THREADED BINARY TREE - SEARCH
========================================================

THEORY:

Searching is performed according to the Binary Search
Tree property.

If:

value < current->data

we move left.

If:

value > current->data

we move right.

But thread pointers must not be treated as children.

Therefore:

leftThread = 1
means the left pointer is a thread.

rightThread = 1
means the right pointer is a thread.

ALGORITHM:

1. Start from root.
2. Compare value with current node.
3. If equal, value is found.
4. If value is smaller:
   - Check leftThread.
   - If leftThread is 1, value is not present.
   - Otherwise move left.
5. If value is greater:
   - Check rightThread.
   - If rightThread is 1, value is not present.
   - Otherwise move right.
6. Repeat until found or current becomes NULL.

TIME COMPLEXITY:

Average case: O(log n)

Worst case: O(n)

SPACE COMPLEXITY:

O(1)

========================================================
*/