#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a structure for students
typedef struct {
    int student_id;
    char name[50];
} Student;

// Function to swap two students
void swap(Student *a, Student *b) {
    Student temp = *a;
    *a = *b;
    *b = temp;
}

// Function to heapify a subtree with root at index i
void heapify(Student arr[], int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left].student_id > arr[largest].student_id)
        largest = left;

    if (right < n && arr[right].student_id > arr[largest].student_id)
        largest = right;

    if (largest != i) {
        swap(&arr[i], &arr[largest]);
        heapify(arr, n, largest);
    }
}

// Function to perform heapsort
void heapsort(Student arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    for (int i = n - 1; i > 0; i--) {
        swap(&arr[0], &arr[i]);
        heapify(arr, i, 0);
    }
}

// Function to print the array of students
void printStudents(Student arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("Student(ID: %d, Name: %s)\n", arr[i].student_id, arr[i].name);
    }
}

int main() {
    Student students[] = {
        {3, "Alice"},
        {1, "Bob"},
        {2, "Charlie"},
        {5, "Dave"},
        {4, "Eve"}
    };

    int n = sizeof(students) / sizeof(students[0]);

    printf("Before sorting:\n");
    printStudents(students, n);

    heapsort(students, n);

    printf("\nAfter sorting:\n");
    printStudents(students, n);

    return 0;
}

