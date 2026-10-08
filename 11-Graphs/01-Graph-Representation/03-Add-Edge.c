#include <stdio.h>

int main()
{
    int graph[10][10];
    int n;
    int u, v;
    int i, j;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    // Important step - Initialize the graph
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            graph[i][j] = 0;
        }
    }

    printf("Enter an edge (u v) to add: ");
    scanf("%d %d", &u, &v);

    // Important step - Add the edge
    graph[u][v] = 1;
    graph[v][u] = 1;

    printf("\nGraph after adding edge:\n");

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
An edge connects two vertices in a graph.

For an undirected graph, adding an edge between u and v means:

graph[u][v] = 1
graph[v][u] = 1

ALGORITHM:
1. Create an adjacency matrix.
2. Initialize all values to 0.
3. Read the two vertices.
4. Set graph[u][v] to 1.
5. Set graph[v][u] to 1.
6. Display the graph.

TIME COMPLEXITY:
Adding an edge = O(1)
Displaying matrix = O(V^2)

SPACE COMPLEXITY:
O(V^2)

V = Number of vertices
*/