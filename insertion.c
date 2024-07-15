#include <stdio.h>

// Function prototypes
void selectionSort(int arr[], int n, int ascending);
void swap(int *xp, int *yp);
void printArray(int arr[], int n);

int main() {
    int n, i, order;
    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter %d integers:\n", n);
    for(i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    printf("Enter sorting order (0 for ascending, 1 for descending): ");
    scanf("%d", &order);

    selectionSort(arr, n, order);

    printf("Sorted array is: ");
    printArray(arr, n);

    return 0;
}

// Selection sort function
void selectionSort(int arr[], int n, int ascending) {
    int i, j, min_idx;

    for (i = 0; i < n-1; i++) {
        min_idx = i;
        for (j = i+1; j < n; j++) {
            if (ascending ? (arr[j] < arr[min_idx]) : (arr[j] > arr[min_idx]))
                min_idx = j;
        }
        swap(&arr[min_idx], &arr[i]);
    }
}

// Function to swap two elements
void swap(int *xp, int *yp) {
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

// Function to print an array
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

