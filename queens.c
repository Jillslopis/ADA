#include<stdbool.h>
#include<stdlib.h>
#include<limits.h>
#include<time.h>
#include<sys/time.h>
#include<sys/resource.h>
#define MAX_N 100

void printBoard(int board[][MAX_N], int N) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
                printf("%c ", board[i][j] ? 'Q' : '.');
        }
        printf("\n");
    }
    printf("\n");
}

bool isSafe(int board[][MAX_N], int row, int col, int N) {
    for (int c = 0; c < col; c++) {
        if (board[row][c])
            return false;
    }

    for (int r = row, c = col; r >= 0 && c >= 0; r--, c--) {
        if (board[r][c])
            return false;
    }

    for (int r = row, c = col; r < N && c >= 0; r++, c--) {
        if (board[r][c])
            return false;
    }

    return true;
}

bool solveNQueens(int board[][MAX_N], int col, int N) {
    if (col >= N) {
        printBoard(board, N);
        return true;
    }

    bool res = false;
    for (int i = 0; i < N; i++) {
        if (isSafe(board, i, col, N)) {
            board[i][col] = 1;

            res = solveNQueens(board, col + 1, N) || res;

            board[i][col] = 0;
        }
    }

    return res;
}

int main() {
    int N;
    struct timeval tv1, tv2;
    struct rusage r_usage;

    printf("Enter the size of the chessboard (N x N): ");
    scanf("%d", &N);

    if (N <= 0 || N > MAX_N) {
        printf("Invalid size of the chessboard. Please enter a size between 1 and %d.\n", MAX_N);
        return 1;
    }

    int board[MAX_N][MAX_N];

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            board[i][j] = 0;
        }
    }
    gettimeofday(&tv1, NULL);
    if (!solveNQueens(board, 0, N)) {
        printf("Solution does not exist for the given size of the chessboard.\n");
    }
    gettimeofday(&tv2, NULL);
    printf("Total time = %f microseconds\n",(double)(tv2.tv_usec - tv1.tv_usec));
    getrusage(RUSAGE_SELF,&r_usage);
    printf("Memory usage: %ld kiloytes\n",r_usage.ru_maxrss);

    return 0;
}
