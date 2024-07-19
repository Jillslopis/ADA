#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/resource.h>
#include<time.h>
#define MAX 100

void printMatrix(int matrix[MAX][MAX], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
             printf("%d ", matrix[i][j]);
    }
    printf("\n");
    }
}

void warshallAlgorithm(int graph[MAX][MAX], int n) {
    int reach[MAX][MAX];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            reach[i][j] = graph[i][j];
        }
    }
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                reach[i][j] = reach[i][j] || (reach[i][k] && reach[k][j]);
            }
        }
    }
    printf("Transitive closure of the given graph:\n");
    printMatrix(reach, n);
}

    long getCurrentTime() {
    struct timeval time;
    gettimeofday(&time, NULL);
    return time.tv_sec * 1000000 + time.tv_usec;
    }

    long getMemoryUsage() {
    struct rusage usage;
    getrusage(RUSAGE_SELF, &usage);
    return usage.ru_maxrss;
}

int main() {
    int n;
    int graph[MAX][MAX];

    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    printf("Enter the adjacency matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    long startTime = getCurrentTime();
    long startMemory = getMemoryUsage();

    warshallAlgorithm(graph, n);

    long endTime = getCurrentTime();
    long endMemory = getMemoryUsage();

    printf("Execution time: %ld microseconds\n", (endTime - startTime));
    printf("Memory usage: %ld kilobytes\n", (endMemory - startMemory));

    return 0;
}
