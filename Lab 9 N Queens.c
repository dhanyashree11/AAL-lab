#include <stdio.h>
#include <stdlib.h>
#define MAX 20
int board[MAX][MAX];

int isSafe(int row, int col, int n) {
    int i, j;
    for (i = 0; i < row; i++)
        if (board[i][col])
            return 0;
    for (i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--)
        if (board[i][j])
            return 0;
    for (i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++)
        if (board[i][j])
            return 0;

    return 1;
}
int solveNQueens(int row, int n) {
    if (row == n) {
        printf("\nSolution:\n");
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++)
                printf("%s ", board[i][j] ? "Q" : ".");
            printf("\n");
        }
        return 1;
    }
    int found = 0;
    for (int col = 0; col < n; col++) {
        if (isSafe(row, col, n)) {
            board[row][col] = 1;  
            found |= solveNQueens(row + 1, n); 
            board[row][col] = 0;
        }
    }

    return found;
}
int main() {
    int n;
    printf("Enter the value of N (max %d): ", MAX);
    scanf("%d", &n);

    if (n < 1 || n > MAX) {
        printf("Invalid input. N must be between 1 and %d.\n", MAX);
        return 1;
    }

    if (!solveNQueens(0, n))
        printf("No solution exists for N = %d\n", n);

    return 0;
}
