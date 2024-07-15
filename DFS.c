#include<stdio.h>
#include<sys/time.h>
#include<time.h>
#include<sys/resource.h>
int n,a[20][20],reach[20];

void dfs(int i);

void main(){
struct timeval tv1,tv2;
struct rusage r_usage;

int i, j;
int v;
printf("Enter the number of vertex: ");
scanf("%d",&n);

printf("Enter the matrix:\n");
for(i=1;i<=n;++i){
for(j=1;j<=n;++j){
scanf("%d",&a[i][j]);
}
}

gettimeofday(&tv1,NULL);
printf("Nodes that are reachable are:-\n");
dfs(1);
gettimeofday(&tv2,NULL);

printf("\nTime of DFS= %f microseconds\n",(double)(tv2.tv_usec-tv1.tv_usec));
getrusage(RUSAGE_SELF,&r_usage);
printf("Memory usage = %ld kilobyts\n",r_usage.ru_maxrss);
}

void dfs(int i){
printf("\n%d",i);
reach[i]=1;
for(int  j=1;j<=n;++j){
    if(a[i][j]==1&&!reach[j]){
    dfs(j);
}
}
}

