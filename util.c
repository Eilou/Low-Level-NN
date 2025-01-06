#include "util.h"

void printArray(Matrix *m) {

    for (int i = 0; i < m->rows; i ++) {
        
        for (int j = 0; j < m->cols; j++) {
            printf("%f\t", m->values[i][j]); 
            // increments the pointer by the amount of memory that a double takes up
            // in dynamic memory allocation this must be done manually
        }
        printf("\n");
    }
}