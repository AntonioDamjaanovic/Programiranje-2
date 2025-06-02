#include "zad1_functions.h"
#include <stdio.h>
#include <stdlib.h>

int** allocateMatrix(int m, int n) {
    int i, ** mat = NULL;
    mat = (int**)malloc(m * sizeof(int*));
    if (mat == NULL)
        return NULL;
    for (i = 0; i < m; i++) {
        mat[i] = (int*)malloc(n * sizeof(int));
        if (mat[i] == NULL)
            return NULL;
    }
    return mat;
}
void inputMatrix(int** mat, int m, int n) {
    int i, j;
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            printf("Input mat[%d][%d]:", i, j);
            scanf("%d", (*(mat + i) + j));
        }
    }
}

void matrixTimesK(int **mat, int n, int m, int K) {
    int i, j;
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            mat[i][j] = mat[i][j] * K;
        }
    }
}

void printMatrix(int** mat, int m, int n) {
    int i, j;
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            printf("%d\t", mat[i][j]);
        }
        printf("\n");
    }
}
