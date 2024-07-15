#include <stdio.h>

#define MAX_N 100 // Maximum number of systems

// Function prototypes
void warshall(int graph[MAX_N][MAX_N], int n);

int main() {
    int n;
    int graph[MAX_N][MAX_N];

    printf("Enter the number of systems (n <= %d): ", MAX_N);
    scanf("%d", &n);

    // Input the adjacency matrix
    printf("Enter the adjacency matrix (%d x %d):\n", n, n);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &graph[i][j]);

    warshall(graph, n);

    return 0;
}

// Function to find transitive closure using Warshall's algorithm
void warshall(int graph[MAX_N][MAX_N], int n) {
    int reach[MAX_N][MAX_N]; // Result matrix where reach[i][j] will be true if there is a path from i to j

    // Initialize reach[][]
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            reach[i][j] = graph[i][j];

    // Compute transitive closure
    for (int k = 0; k < n; k++) {
        // Pick all vertices as source one by one
        for (int i = 0; i < n; i++) {
            // Pick all vertices as destination for the above picked source
            for (int j = 0; j < n; j++) {
                // If vertex k is on a path from i to j, then mark reach[i][j] as true
                if (reach[i][k] && reach[k][j])
                    reach[i][j] = 1;
            }
        }
    }

    // Print the transitive closure
    printf("Transitive closure (reachability matrix):\n");
    printf("   ");
    for (int i = 0; i < n; i++)
        printf("%3d ", i);
    printf("\n");
    for (int i = 0; i < n; i++) {
        printf("%3d", i);
        for (int j = 0; j < n; j++) {
            printf("%3d ", reach[i][j]);
        }
        printf("\n");
    }
}

