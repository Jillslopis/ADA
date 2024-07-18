#include <stdio.h>
#include<sys/time.h>
#include<sys/resource.h>

int n,c[20][20],i,j,visited[20];

void prim()
{
 int min,b,a,k,count=0,cost=0;
 min=999;
 visited[1]=1; 
 while(count<n-1)
 {
  min=999;
  for(i=1;i<=n;i++)
    for(j=1;j<=n;j++)
      if(visited[i] && !visited[j] && min>c[i][j]) 
      {
       min=c[i][j]; 
       a=i;
       b=j;
      }
   printf("%d--->%d = %d\n",a,b,c[a][b]);
   cost+=c[a][b];
   visited[b]=1;
   count++;
  } 
  printf("Total cost of Spanning tree is %d\n",cost); 
 }

void main()
{
    struct timeval tv1, tv2;
    struct rusage r_usage;
printf("Enter number of vertices \n");
 scanf("%d",&n);
 printf("Enter the cost matrix \n");
 for(i=1;i<=n;i++)
 {
  for(j=1;j<=n;j++)
	scanf("%d",&c[i][j]);
  visited[i]=0;
 }
 gettimeofday(&tv1, NULL);
 prim();
 gettimeofday(&tv2, NULL);
 printf("Total time = %f microseconds\n", (double)(tv2.tv_usec - tv1.tv_usec));
 getrusage(RUSAGE_SELF, &r_usage);
 printf("Memory usage: %ld kilobytes\n", r_usage.ru_maxrss);
 }
