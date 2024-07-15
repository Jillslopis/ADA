#include <stdio.h>
#include <limits.h>

#define MAX_N 100 // Maximum number of cities

// Function prototype
void floydWarshall(int graph[MAX_N][MAX_N], int n);

int main() {
    int n;
    int graph[MAX_N][MAX_N];

    printf("Enter the number of cities (n <= %d): ", MAX_N);
    scanf("%d", &n);

    // Input the adjacency matrix
    printf("Enter the adjacency matrix (%d x %d):\n", n, n);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &graph[i][j]);

    floydWarshall(graph, n);

    return 0;
}

// Function to find shortest paths between all pairs of vertices
void floydWarshall(int graph[MAX_N][MAX_N], int n) {
    int dist[MAX_N][MAX_N]; // Output matrix where dist[i][j] will be the shortest distance from i to j

    // Initialize dist[][]
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            dist[i][j] = graph[i][j];

    // Compute shortest paths
    for (int k = 0; k < n; k++) {
        // Pick all vertices as source one by one
        for (int i = 0; i < n; i++) {
            // Pick all vertices as destination for the above picked source
            for (int j = 0; j < n; j++) {
                // If vertex k is on the shortest path from i to j, then update dist[i][j]
                if (dist[i][k] != INT_MAX && dist[k][j] != INT_MAX && dist[i][k] + dist[k][j] < dist[i][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }

    // Print the shortest distances between every pair of vertices
    printf("Shortest distances between all pairs of vertices:\n");
    printf("   ");
    for (int i = 0; i < n; i++)
        printf("%3d ", i);
    printf("\n");
    for (int i = 0; i < n; i++) {
        printf("%3d", i);
        for (int j = 0; j < n; j++) {
            if (dist[i][j] == INT_MAX)
                printf(" INF");
            else
                printf("%4d", dist[i][j]);
        }
        printf("\n");
    }
}

