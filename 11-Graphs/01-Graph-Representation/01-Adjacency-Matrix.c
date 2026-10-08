#include <stdio.h>

int main()
{
    int graph[10][10];
    int n, edges;
    int u, v;
    int i, j;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    // Important step - Initialize the matrix with 0
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            graph[i][j] = 0;
        }
    }

    printf("Enter number of edges: ");
    scanf("%d", &edges);

    printf("Enter edges (u v):\n");

    for (i = 0; i < edges; i++)
    {
        scanf("%d %d", &u, &v);

        // Important step - Mark the edge between u and v
        graph[u][v] = 1;
        graph[v][u] = 1;
    }

    printf("\nAdjacency Matrix:\n");

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            printf("%d ", graph[i][j]);
        }

        printf("\n");
    }

    return 0;
}

/*
THEORY:
An adjacency matrix is a 2D array used to represent a graph.

If there is an edge between vertex u and vertex v:
graph[u][v] = 1

For an undirected graph:
graph[u][v] = 1
graph[v][u] = 1

ALGORITHM:
1. Read the number of vertices.
2. Initialize the matrix with 0.
3. Read the number of edges.
4. Read each edge.
5. Mark the corresponding matrix positions as 1.
6. Display the matrix.

TIME COMPLEXITY:
Initialization = O(V^2)
Adding edges = O(E)
Displaying matrix = O(V^2)

SPACE COMPLEXITY:
O(V^2)

V = Number of vertices
E = Number of edges
*/