#include<stdio.h> 
#include<stdlib.h>
#include<sys/resource.h>
#include<sys/types.h>
#include<time.h>
int main()
{
struct timeval tv1,tv2;
struct rusage r_usage;
int arr[]={};
int n;
printf("Enter the number of elements\n");
scanf("%d",&n);
printf("ENter the elements:\n");
for(int i=0;i<n;i++ )
{
scanf("%d",&arr[i]);
}
gettimeofday(&tv1,NULL);
selectionsort(arr,n);
gettimeofday(&tv2,NULL);
printf("Sorted array\n");
for(int i=0;i<n;i++)
{
printf("%d\n",arr[i]);
}
printf("Time of selection sort=%f microseconds",(double)(tv2.tv_usec-tv1.tv_usec));
getrusage(RUSAGE_SELF,&r_usage);
printf("Memory:%ld kilobytes\n",r_usage.ru_maxrss);
}
void selectionsort(int arr[100],int n)
{
int min,temp;
int j;
for(int i=0;i<=n-2;i++)
{
min=i;
for(j=i+1;j<=n-1;j++)
{
if(arr[j]<arr[min]) 
{
min=j;
}
}
temp=arr[min];
arr[min]=arr[i];
arr[i]=temp;
}
}
