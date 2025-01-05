#include "staticNN.h"
#include "util.h"

void initialiseWeights() {
    double x[2][1] = {{3}, {4}};
    double w1[2][2] = {{0.7, 0.8}, {-0.2, 0.5}};
    double b1[2] = {{0.5}, {0.7}};
    double w2[2] = {{0.1}, {0.1}};
    double b2[1] = {0.3};
    double learningRate = 0.1;
    
    printf("X values:\n");
    printArray(2, 1, (double *)x);
    printf("W1 values:\n");
    printArray(2, 2, (double *)w1);

}

void staticNN() {
    printf("Static Memory Allocation  Neural Network\n");

    initialiseWeights();
}