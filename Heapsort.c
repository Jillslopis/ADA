#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}


void heapify(int arr[], int n, int i) {
    int largest = i;
    int left = 2*i + 1; 
    int right = 2*i + 2; 

    if (left < n && arr[left] > arr[largest])
        largest = left;


    if (right < n && arr[right] > arr[largest])
        largest = right;

  
    if (largest != i) {
        swap(&arr[i], &arr[largest]);
       
        heapify(arr, n, largest);
    }
}


void heapSort(int arr[], int n) {
  
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

  
    for (int i = n-1; i > 0; i--) {
       
        swap(&arr[0], &arr[i]);
     
        heapify(arr, i, 0);
    }
}


void printArray(int arr[], int n) {
    for (int i = 0; i < n; ++i)
        printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);


    int *arr = (int*)malloc(n * sizeof(int));

   
    printf("Enter the elements:\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    printf("Original array: \n");
    printArray(arr, n);


    clock_t start_time = clock();
    heapSort(arr, n);
    clock_t end_time = clock();
    double total_time = (double)(end_time - start_time) / CLOCKS_PER_SEC;
    printf("Sorted array: \n");
    printArray(arr, n);

    free(arr);

    printf("Time Complexity: %lf seconds\n", total_time);
    printf("Space Complexity: O(1) (in-place sorting)\n");

    return 0;
}
