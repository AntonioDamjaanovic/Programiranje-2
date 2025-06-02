#include <stdio.h>
#include "matrix.c"

int main() {
    int rows, cols;
    double **mat;

    const char *putanja = "C:\\Users\\Antonio\\Desktop\\Demos\\Prog 2 Labosi\\LV7\\in.txt";
    FILE *in = fopen(putanja, "r");
    fscanf(in, "%d %d", &rows, &cols);
    fclose(in);

    mat = createMatrix(rows, cols);
    fillMatrix(mat, rows, cols, -125.5, 65.8);

    printMatrix(mat, rows, cols);
    writeMatrixToFile(mat, rows, cols, "out.txt");

    freeMatrix(mat, rows);

    return 0;
}