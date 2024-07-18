#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/resource.h>
#include<sys/times.h> 
#include<limits.h>
#include<stdbool.h>
#define MAX_V 100

int minDistance(int dist[], bool sptSet[], int V)
{
int min = INT_MAX, min_index;

for (int v = 0; v < V; v++) {
if (sptSet[v] == false && dist[v] <= min) {
min = dist[v];
min_index = v;
}
}

return min_index;
}

void printSolution(int dist[], int V)
{
printf("Vertex \t\t Distance from Source\n");
for (int i = 0; i < V; i++) {
printf("%d \t\t\t\t %d\n", i, dist[i]);
}
}

void dijkstra(int graph[][MAX_V], int src, int V)
{
int dist[V];
bool sptSet[V];

for (int i = 0; i < V; i++) {
dist[i] = INT_MAX;
sptSet[i] = false;
}

dist[src] = 0;

for (int count = 0; count < V - 1; count++) {
int u = minDistance(dist, sptSet, V);

sptSet[u] = true;

for (int v = 0; v < V; v++) {
if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX
&& dist[u] + graph[u][v] < dist[v]) {
dist[v] = dist[u] + graph[u][v];
}
}
}

printSolution(dist, V);
}

int main()
{
int V;
int src;
struct timeval tv1, tv2;
struct rusage r_usage;

printf("Enter the number of vertices: ");
scanf("%d", &V);

int graph[MAX_V][MAX_V];

printf("Enter the adjacency matrix (%d x %d):\n", V, V);
for (int i = 0; i < V; i++) {
for (int j = 0; j < V; j++) {
scanf("%d", &graph[i][j]);
}
}

printf("Enter the starting node (between 0 and %d): ", V - 1);
scanf("%d", &src);

gettimeofday(&tv1, NULL);
dijkstra(graph, src, V);
gettimeofday(&tv2, NULL);

double time_taken = (double)(tv2.tv_usec - tv1.tv_usec);
printf("Total time = %f microseconds\n", time_taken);

getrusage(RUSAGE_SELF, &r_usage);
printf("Memory usage: %ld kilobytes\n", r_usage.ru_maxrss);

return 0;
}
