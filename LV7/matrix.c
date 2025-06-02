#include <stdio.h>
#include <stdlib.h>
#include <time.h>

double** createMatrix(int rows, int cols) {
    double **mat = (double **)malloc(rows * sizeof(double *));
    for (int i = 0; i < rows; i++)
        *(mat + i) = (double *)malloc(cols * sizeof(double));
    return mat;
}

void fillMatrix(double **mat, int rows, int cols, double min, double max) {
    srand(time(NULL));
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            *(*(mat + i) + j) = ((double)rand() / RAND_MAX) * (max - min) + min;
}

void printMatrix(double **mat, int rows, int cols) {
    for (int i = 0; i < rows - 1; i++) {
        for (int j = 1; j < cols; j++)
            printf("%.2f\t\t", *(*(mat + i) + j));
        printf("\n");
    }
}

void writeMatrixToFile(double **mat, int rows, int cols, const char *filename) {
    FILE *out = fopen(filename, "w");
    for (int i = 0; i < rows - 1; i++) {
        for (int j = 1; j < cols; j++)
            fprintf(out, "%.2f\t\t", *(*(mat + i) + j));
        fprintf(out, "\n");
    }
    fclose(out);
}

void freeMatrix(double **mat, int rows) {
    for (int i = 0; i < rows; i++)
        free((mat + i));
    free(mat);
}
