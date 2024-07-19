#include<stdio.h>
#include<sys/time.h>
#include<sys/resource.h>
#include<time.h>

int a[20][20], reach[20], n;
void dfs(int v) {
    int i;
    reach[v] = 1;
    for (i = 1; i <= n; i++)
        if (a[v][i] && !reach[i]) {
            printf("\n %d->%d", v, i);
            dfs(i);
        }
}

int main(int argc, char **argv) {
    struct timeval tv1,tv2;
    struct rusage r_usage;
    int i, j, count = 0;
    printf("\n Enter number of vertices:");
    scanf("%d", &n);
    for (i = 1; i <= n; i++) {
        reach[i] = 0;
        for (j = 1; j <= n; j++)
            a[i][j] = 0;
    }
    printf("\n Enter the adjacency matrix:\n");
    for (i = 1; i <= n; i++){
        for (j = 1; j <= n; j++){
            scanf("%d", &a[i][j]);
        }
    }

    gettimeofday(&tv1,NULL);
    dfs(1);
    gettimeofday(&tv2,NULL);    
    printf("\n");
    for (i = 1; i <= n; i++) {
        if (reach[i])
            count++;
    }
    if (count == n)
        printf("\n Graph is connected");
    else
        printf("\n Graph is not connected");
    
    printf("\n");
    printf("Time of selection sort= %f microsecond\n",(double)(tv2.tv_usec-tv1.tv_usec));
    getrusage(RUSAGE_SELF,&r_usage);
    printf("memory: %ld kilobytes\n", r_usage.ru_maxrss);
    return 0;
}
