#include "staticNN.h"
#include "util.h"

void initialiseWeights() {
    double x[2][1] = {{3}, {4}};
    double W1[2][2];
    double B1[2];
    double W2[2];
    double B2[2];
    
    printf("X values:\n");
    printArray(2, 1, (double *)x);
}

void staticNN() {
    printf("Static Memory Allocation  Neural Network\n");

    initialiseWeights();
}