#include <stdio.h>
#include <stdbool.h>

#define N 10 // Maximum value of n, change as per requirements

int board[N][N]; // Board to represent rooms

// Function prototypes
bool isSafe(int row, int col, int n);
bool solveNQueens(int col, int n);
void printBoard(int n);

// Main function
int main() {
    int n;

    printf("Enter the number of patients/rooms (n <= %d): ", N);
    scanf("%d", &n);

    if (n <= 0 || n > N) {
        printf("Invalid input. Please enter a valid value of n.\n");
        return 1;
    }

    // Initialize the board to 0
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            board[i][j] = 0;

    if (solveNQueens(0, n)) {
        printf("Patient allocation to rooms (using N-Queens method):\n");
        printBoard(n);
    } else {
        printf("Solution does not exist.\n");
    }

    return 0;
}

// Function to check if a queen can be placed safely
bool isSafe(int row, int col, int n) {
    // Check this row on left side
    for (int i = 0; i < col; i++)
        if (board[row][i])
            return false;

    // Check upper diagonal on left side
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--)
        if (board[i][j])
            return false;

    // Check lower diagonal on left side
    for (int i = row, j = col; j >= 0 && i < n; i++, j--)
        if (board[i][j])
            return false;

    return true;
}

// Recursive function to solve N-Queens problem
bool solveNQueens(int col, int n) {
    // Base case: If all queens are placed
    if (col >= n)
        return true;

    // Try placing this queen in all rows one by one
    for (int i = 0; i < n; i++) {
        if (isSafe(i, col, n)) {
            // Place queen (patient) on board[i][col]
            board[i][col] = 1;

            // Recur to place rest of the queens
            if (solveNQueens(col + 1, n))
                return true;

            // If placing queen in board[i][col] doesn't lead to a solution, backtrack
            board[i][col] = 0; // Backtrack
        }
    }

    // If queen cannot be placed in any row in this column, return false
    return false;
}

// Function to print the board configuration
void printBoard(int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            printf("%d ", board[i][j]);
        printf("\n");
    }
}

