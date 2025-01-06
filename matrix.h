#ifndef MATRIX_H
#define MATRIX_H

typedef struct {
    double **values;   // pointer to dynamic 2d array memory allocation
    int rows;       // number of rows
    int cols;       // number of columnss
} Matrix;

Matrix *createMatrix(double **values, int rows, int cols);

#endif