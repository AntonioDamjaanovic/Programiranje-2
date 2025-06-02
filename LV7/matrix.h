#ifndef LV7_MATRIX_H
#define LV7_MATRIX_H

double** createMatrix(int, int);
void fillMatrix(double**, int, int, double, double);
void printMatrix(double**, int, int);
void writeMatrixToFile(double**, int, int, char*);
void freeMatrix(double**, int );

#endif
