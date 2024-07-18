#include<stdio.h>
#include<stdlib.h>
#include<sys/resource.h>
#include<sys/types.h>
#include<time.h>
int n, i, j, visited[100], queue[100], front = -1, rear = -1;
int adj[100][100];

void bfs(int v) {
    queue[++rear] = v; 
    visited[v] = 1; 

    while (front < rear) {
        int current = queue[++front]; 

    for (i = 1; i <= n; i++) {
    if (adj[current][i] && !visited[i]) {
        queue[++rear] = i;
        visited[i] = 1;
    }
    }
    }
}

int main() { 
int v;
printf("Enter the number of vertices: ");
scanf("%d", &n);
if (n <= 0 || n > 100) { 
    printf("Invalid number of vertices.\n");
return 1;
}

printf("Enter graph data in matrix form:\n");
for (i = 1; i <= n; i++) {
    for (j = 1; j <= n; j++) {
        scanf("%d", &adj[i][j]);
    }
}

printf("Enter the starting vertex: ");
scanf("%d", &v);
if (v <= 0 || v > n)
{
    printf("Invalid starting vertex.\n");
    return 1;
}

bfs(v);

printf("The nodes which are reachable are:\n");
int reachable = 0;
for (i = 1; i <= n; i++) {
if (visited[i]) {
printf("%d\t", i);
reachable = 1;
}
}
if (!reachable) {
printf("BFS is not possible. Not all nodes are reachable.\n");
}
printf("\n");


struct timeval tv1,tv2;
struct rusage r_usage;
gettimeofday(&tv1,NULL);
gettimeofday(&tv2,NULL);
printf("\n");
printf("Time of merge sort = %f microseconds\n",(double)(tv2.tv_usec-tv1.tv_usec));
printf("Total time = %f seconds\n",(double)(tv2.tv_usec-tv1.tv_usec)/1000000 + (double)(tv2.tv_usec-tv1.tv_usec));
getrusage(RUSAGE_SELF,&r_usage);
printf("Memory usage : %ld kilobytes\n",r_usage.ru_maxrss);
return 0;
}

