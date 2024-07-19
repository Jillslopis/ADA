#include<stdio.h>
#include<sys/resource.h>
#include<time.h>
#include<sys/types.h>
#include<stdlib.h>
void merge(int a[],int lb,int mid,int ub)
{
int i=lb;
int j=mid+1;
int k=lb;
int b[50];
while(i<=mid && j<=ub)
{
if(a[i]<=a[j])
{
b[k]=a[i];
i++;
k++;
}
else
{
b[k]=a[j];
j++;
k++;
}
}
if(i>mid)
{
while(j<=ub)
{
b[k]=a[j];
j++;
k++;
}
}
else
{
while(i<=mid)
{
b[k]=a[i];
i++;
k++;
}
}
for(k=lb;k<=ub;k++)
{
a[k]=b[k];
}
}

void mergesort(int a[],int lb,int ub)
{
if(lb<ub) {
    int mid=(lb+ub)/2;
    mergesort(a,lb,mid);
    mergesort(a,mid+1,ub);
    merge(a,lb,mid,ub);
    }
}

int main()
{
int i,n,temp;
int lb, ub;
struct timeval tv1,tv2;
struct rusage r_usage;
printf("Enter the number of elements:");
scanf("%d",&n);
int a[n];
printf("Enter the array elements:");
for(i=0;i<n;i++) {
    scanf("%d",&a[i]);
}
lb=0;
ub=n-1;
gettimeofday(&tv1,NULL);
mergesort(a,lb,ub);
gettimeofday(&tv2,NULL);
printf("Sorted Array elements are:");
for(i=0;i<n;i++) {
printf("%d ",a[i]);
}
printf("\n");
printf("Time of merge sort = %f microseconds\n",(double)(tv2.tv_usec-tv1.tv_usec));
printf("Total time = %f seconds\n",(double)(tv2.tv_usec-tv1.tv_usec)/1000000 + (double)(tv2.tv_usec-tv1.tv_usec));
getrusage(RUSAGE_SELF,&r_usage);
printf("Memory usage : %ld kilobytes\n",r_usage.ru_maxrss);
return 0;
}
