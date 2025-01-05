#include "util.h"

void printArray(int rows, int cols, double *arr) {
    for (int i = 0; i < rows; i ++) {
        for (int j = 0; j < cols; j++) {
            printf("%f\t", *(arr + i * cols + j)); 
            // increments the pointer by the amount of memory that a double takes up
            // in dynamic memory allocation this must be done manually
        }
        printf("\n");
    }
}

// double[] dotProduct(int r1, int c1, double *arr1, int r2, int c2, double *arr2) {
// 
// }