#include<stdio.h>
#include<stdlib.h>
#include<sys/resource.h>
#include<sys/time.h>
#include<time.h>
int main(){
struct timeval tv1,tv2;
struct rusage r_usage;
int arr[]={};
int n;
printf("Enter the number of elements\n");
scanf("%d",&n);
printf("ENter the elements:\n");
for(int i=0;i<n;i++)
{
    scanf("%d",&arr[i]);
}
gettimeofday(&tv1,NULL);
insertionsort(arr,n);
gettimeofday(&tv2,NULL);
for(int i=0;i<n;i++)
{
    printf("%d\n",arr[i]);
}
printf("Time of insertion sort=%f microseconds",(double)(tv2.tv_usec-tv1.tv_usec));
getrusage(RUSAGE_SELF,&r_usage);
printf("Memory:%ld kilobytes\n",r_usage.ru_maxrss);
}
void insertionsort(int arr[100],int n)
{
int temp;
int j;
for(int i=1;i<n;i++){
temp=arr[i];
j=i-1;
while(j>=0 && arr[j]>temp){
arr[j+1]=arr[j];
j--;
}
arr[j+1]=temp;
}
}
