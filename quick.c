#include <stdio.h>
#include <stdlib.h>
#include <sys/resource.h>
#include <sys/time.h>

int position(int arr[], int lb, int ub);
void quicksort(int arr[], int lb, int ub);

int main() {
    int n;
    int lb = 0;
    struct timeval tv1, tv2;
    struct rusage r_usage;

    printf("Enter the number of elements in an array\n");
    scanf("%d", &n);

    int arr[n]; // Dynamic allocation based on input size
    int ub = n - 1;

    printf("Enter the elements:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    gettimeofday(&tv1, NULL);
    quicksort(arr, lb, ub);
    gettimeofday(&tv2, NULL);

    printf("Sorted array is:\n");
    for (int i = 0; i < n; i++) {
        printf("%d\n", arr[i]);
    }

    double time_taken = (double)(tv2.tv_sec - tv1.tv_sec) * 1e6 + (double)(tv2.tv_usec - tv1.tv_usec);
    printf("Time of quicksort = %f microseconds\n", time_taken);

    getrusage(RUSAGE_SELF, &r_usage);
    printf("Memory usage: %ld kilobytes\n", r_usage.ru_maxrss / 1024);

    return 0;
}

int position(int arr[], int lb, int ub) {
    int pivot = arr[lb];
    int start = lb;
    int end = ub;
    int temp;

    while (start < end) {
        while (arr[start] <= pivot) {
            start++;
        }
        while (arr[end] > pivot) {
            end--;
        }
        if (start < end) {
            temp = arr[start];
            arr[start] = arr[end];
            arr[end] = temp;
        }
    }
    temp = arr[lb];
    arr[lb] = arr[end];
    arr[end] = temp;
    return end;
}

void quicksort(int arr[], int lb, int ub) {
    int loc;
    if (lb < ub) {
        loc = position(arr, lb, ub);
        quicksort(arr, lb, loc - 1);
        quicksort(arr, loc + 1, ub);
    }
}
