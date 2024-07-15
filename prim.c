#include <stdio.h>
#include <limits.h>
#include <stdbool.h>

#define MAX_VERTICES 100 // Maximum number of vertices

// Function prototypes
void primMST(int graph[MAX_VERTICES][MAX_VERTICES], int n);

int main() {
    int n;
    int graph[MAX_VERTICES][MAX_VERTICES];

    printf("Enter the number of vertices (n <= %d): ", MAX_VERTICES);
    scanf("%d", &n);

    // Input the adjacency matrix
    printf("Enter the adjacency matrix (%d x %d):\n", n, n);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &graph[i][j]);

    primMST(graph, n);

    return 0;
}

// Function to find MST using Prim's algorithm
void primMST(int graph[MAX_VERTICES][MAX_VERTICES], int n) {
    int parent[MAX_VERTICES]; // Array to store constructed MST
    int key[MAX_VERTICES];    // Key values used to pick minimum weight edge

    bool mstSet[MAX_VERTICES]; // To represent set of vertices not yet included in MST

    // Initialize all keys as INFINITE
    for (int i = 0; i < n; i++) {
        key[i] = INT_MAX;
        mstSet[i] = false;
    }

    // Always include first vertex in MST
    key[0] = 0;     // Make key 0 so that this vertex is picked as first vertex
    parent[0] = -1; // First node is always root of MST

    // The MST will have n vertices
    for (int count = 0; count < n - 1; count++) {
        // Pick the minimum key vertex from the set of vertices not yet included in MST
        int u = -1;
        for (int v = 0; v < n; v++) {
            if (!mstSet[v] && (u == -1 || key[v] < key[u]))
                u = v;
        }

        // Add the picked vertex to the MST set
        mstSet[u] = true;

        // Update key and parent index of the adjacent vertices of the picked vertex.
        // Consider only those vertices which are not yet included in MST
        for (int v = 0; v < n; v++) {
            // graph[u][v] is non zero only for adjacent vertices of m
            // mstSet[v] is false for vertices not yet included in MST
            // Update the key only if graph[u][v] is smaller than key[v]
            if (graph[u][v] && !mstSet[v] && graph[u][v] < key[v]) {
                parent[v] = u;
                key[v] = graph[u][v];
            }
        }
    }

    // Print the constructed MST
    printf("Edges of Minimum Spanning Tree:\n");
    printf("Edge\tWeight\n");
    for (int i = 1; i < n; i++) {
        printf("%d - %d\t%d\n", parent[i], i, graph[i][parent[i]]);
    }
}

