#include<stdio.h>
#include<sys/time.h>
#include<sys/resource.h>
#include<time.h>
#define N 4
int arr[N];



int insertionsort(){

int i,j;
int temp;

printf("Enter the array ");

for(i = 0; i < N; i++){
scanf("%d", &arr[i]);
}

for(i = 1; i < N; i++){
temp = arr[i];
j = i - 1;

while(j >= 0 && arr[j] > temp){
arr[j + 1] = arr[j];
j--;
}
arr[j + 1] = temp;
}

printf("The sorted array is");
for(i = 0; i < N; i++){
printf("%d ", arr[i]);
}
return 0;
}

int main(){


struct timeval tv1,tv2;

struct rusage r1,r2;
getrusage(RUSAGE_SELF, &r2);

gettimeofday(&tv1,NULL);


insertionsort();

gettimeofday(&tv2,NULL);


long timetaken=tv2.tv_sec-tv1.tv_sec;
printf("time taken is = %ld ms ", timetaken);

printf(" space complexity= %ld Kb",r2.ru_maxrss);


return 0;
}

