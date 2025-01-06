#include <stdlib.h>

#include "matrix.h"


Matrix *createMatrix(double *givenValues, int givenRows, int givenCols) {

    double **ptrValues = malloc(givenRows * sizeof(double *));
    if (ptrValues == NULL) {
        printf("Memory allocation for pointer values failed\n");
        exit(1);
    }

    for (int i = 0; i < givenRows; i++) {
        ptrValues[i] = givenValues + i * givenCols;
    }

    Matrix *m = (Matrix *)malloc(sizeof(Matrix));

    if (m == NULL) {
        perror("Failed to allocate memory for matrix struct");
        exit(EXIT_FAILURE);
    }

    m->values = ptrValues;
    m->rows = givenRows;
    m->cols = givenCols;

    return m;
}