#include <stdio.h>
#include <stdbool.h>

#define N 10 // Maximum value of n, change as per requirements

int board[N][N]; 


bool isSafe(int row, int col, int n);
bool solveNQueens(int col, int n);
void printBoard(int n);


int main() {
    int n;

    printf("Enter the number of patients/rooms (n <= %d): ", N);
    scanf("%d", &n);

    if (n <= 0 || n > N) {
        printf("Invalid input. Please enter a valid value of n.\n");
        return 1;
    }

    
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


bool isSafe(int row, int col, int n) {
    
    for (int i = 0; i < col; i++)
        if (board[row][i])
            return false;

    
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--)
        if (board[i][j])
            return false;

    
    for (int i = row, j = col; j >= 0 && i < n; i++, j--)
        if (board[i][j])
            return false;

    return true;
}


bool solveNQueens(int col, int n) {
    // Base case: If all queens are placed
    if (col >= n)
        return true;

    
    for (int i = 0; i < n; i++) {
        if (isSafe(i, col, n)) {
            
            board[i][col] = 1;

            
            if (solveNQueens(col + 1, n))
                return true;

            
            board[i][col] = 0; // Backtrack
        }
    }

    
    return false;
}


void printBoard(int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            printf("%d ", board[i][j]);
        printf("\n");
    }
}

