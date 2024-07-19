#include <stdio.h>
#include <stdlib.h>
#include <sys/resource.h>
#include <time.h>
#include <sys/types.h>

// Function prototypes
int position(int arr[], int lb, int ub);
int quicksort(int arr[], int lb, int ub);

int main() {
    int n;
    int lb = 0;
    struct timeval tv1, tv2;
    struct rusage r_usage;

    printf("Enter the number of elements in an array: ");
    scanf("%d", &n);

    int *arr = (int *)malloc(n * sizeof(int)); // Allocate memory for the array

    printf("Enter the elements:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    gettimeofday(&tv1, NULL);
    quicksort(arr, lb, n - 1);
    gettimeofday(&tv2, NULL);

    printf("Sorted array:\n");
    for (int i = 0; i < n; i++) {
        printf("%d\n", arr[i]);
    }

    printf("Time of quicksort = %f microseconds\n", (double)(tv2.tv_usec - tv1.tv_usec));
    getrusage(RUSAGE_SELF, &r_usage);
    printf("Memory: %ld kilobytes\n", r_usage.ru_maxrss);

    free(arr); // Free dynamically allocated memory

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

int quicksort(int arr[], int lb, int ub) {
    int loc;
    if (lb < ub) {
        loc = position(arr, lb, ub);
        quicksort(arr, lb, loc - 1);
        quicksort(arr, loc + 1, ub);
    }
    return 0;
}
