#include <stdio.h>
#include <limits.h>
#include <stdbool.h>

#define MAX_N 100 // Maximum number of cities

// Function prototypes
void dijkstra(int graph[MAX_N][MAX_N], int n, int src);

int main() {
    int n, src;
    int graph[MAX_N][MAX_N];

    printf("Enter the number of cities (n <= %d): ", MAX_N);
    scanf("%d", &n);

    // Input the adjacency matrix
    printf("Enter the adjacency matrix (%d x %d):\n", n, n);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &graph[i][j]);

    printf("Enter the source city (0 to %d): ", n - 1);
    scanf("%d", &src);

    dijkstra(graph, n, src);

    return 0;
}

// Dijkstra's algorithm to find shortest paths from source to all vertices
void dijkstra(int graph[MAX_N][MAX_N], int n, int src) {
    int dist[MAX_N]; // Array to store the shortest distances from src to i
    bool visited[MAX_N] = {false}; // Array to track visited cities

    // Initialize distances, all set to infinity (INT_MAX)
    for (int i = 0; i < n; i++) {
        dist[i] = INT_MAX;
    }

    dist[src] = 0; // Distance from source to itself is 0

    // Find shortest path for all cities
    for (int count = 0; count < n - 1; count++) {
        // Pick the minimum distance city from the set of cities not yet processed
        int u = -1;
        for (int i = 0; i < n; i++) {
            if (!visited[i] && (u == -1 || dist[i] < dist[u]))
                u = i;
        }

        // Mark the picked city as visited
        visited[u] = true;

        // Update dist value of the adjacent cities of the picked city
        for (int v = 0; v < n; v++) {
            // Update dist[v] only if it's not visited, there is an edge from u to v,
            // and the total weight of path from src to v through u is smaller than current value of dist[v]
            if (!visited[v] && graph[u][v] && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }

    // Print the shortest distances from source city
    printf("Shortest distances from source city %d:\n", src);
    printf("City\tDistance\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%d\n", i, dist[i]);
    }
}

