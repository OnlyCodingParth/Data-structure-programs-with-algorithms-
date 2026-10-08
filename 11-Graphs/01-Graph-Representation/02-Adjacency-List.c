#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int vertex;
    struct Node *next;
};

struct Node *createNode(int vertex)
{
    struct Node *newNode;

    newNode = (struct Node *)malloc(sizeof(struct Node));

    newNode->vertex = vertex;
    newNode->next = NULL;

    return newNode;
}

int main()
{
    struct Node *graph[10];
    struct Node *newNode;
    struct Node *temp;

    int n, edges;
    int u, v;
    int i;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    // Important step - Initialize all adjacency lists
    for (i = 0; i < n; i++)
    {
        graph[i] = NULL;
    }

    printf("Enter number of edges: ");
    scanf("%d", &edges);

    printf("Enter edges (u v):\n");

    for (i = 0; i < edges; i++)
    {
        scanf("%d %d", &u, &v);

        // Important step - Add v to the list of u
        newNode = createNode(v);
        newNode->next = graph[u];
        graph[u] = newNode;

        // Important step - Add u to the list of v
        newNode = createNode(u);
        newNode->next = graph[v];
        graph[v] = newNode;
    }

    printf("\nAdjacency List:\n");

    for (i = 0; i < n; i++)
    {
        printf("%d -> ", i);

        temp = graph[i];

        while (temp != NULL)
        {
            printf("%d -> ", temp->vertex);
            temp = temp->next;
        }

        printf("NULL\n");
    }

    return 0;
}

/*
THEORY:
An adjacency list represents a graph using an array of linked lists.

Each vertex has a linked list containing all vertices connected to it.

For an undirected graph:
u -> v
v -> u

ALGORITHM:
1. Create an array of linked-list pointers.
2. Initialize every pointer to NULL.
3. Read the number of vertices and edges.
4. For every edge (u, v):
   - Add v to the list of u.
   - Add u to the list of v.
5. Display every adjacency list.

TIME COMPLEXITY:
Creating lists = O(V)
Adding edges = O(E)
Displaying lists = O(V + E)

SPACE COMPLEXITY:
O(V + E)

V = Number of vertices
E = Number of edges
*/