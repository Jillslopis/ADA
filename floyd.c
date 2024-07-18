#include<stdio.h>
#include<sys/resource.h>
#include<sys/time.h>

int min(int a, int b ,int c){
    return (a<(b+c))? a : b+c;
}

void floyd(int W[100][100], int D[100][100], int n){
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            D[i][j]=W[i][j];
        }
    }
    
    for(int k=0; k<n; k++){
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                D[i][j] = min(D[i][j],D[i][k],D[k][j]);
            }
        }
    }
}

int main() {
    struct timeval tv1, tv2;
    struct rusage r_usage;
    
    int W[100][100], D[100][100], n;
    
    printf("Enter the number of nodes: ");
    scanf("%d",&n);
    
    printf("Enter the adjacency matrix: \n");
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            scanf("%d", &W[i][j]);
        }
    }

    gettimeofday(&tv1, NULL);
    floyd(W,D,n);
    gettimeofday(&tv2, NULL);
    
    printf("The distance matrix: \n");
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            printf(" %d ", D[i][j]);
        }
        printf("\n");
    }
    
    double elapsedTime = (tv2.tv_sec - tv1.tv_sec) * 1000000.0 + (tv2.tv_usec - tv1.tv_usec);
    printf("\nTime of Floyd's algorithm = %f microseconds\n", elapsedTime);
    
    getrusage(RUSAGE_SELF, &r_usage);
    printf("Memory usage = %ld kilobytes\n", r_usage.ru_maxrss);

    return 0;
}
