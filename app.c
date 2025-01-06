#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#include "util.h"

void initialiseWeights() {

    double xValues[2][1] = {{3}, {4}};
    
    Matrix *x = createMatrix((double *)xValues, 2, 1);

    double w1[2][2] = {{0.7, 0.8}, {-0.2, 0.5}};
    double b1[2] = {{0.5}, {0.7}};
    double w2[2] = {{0.1}, {0.1}};
    double b2[1] = {0.3};
    double learningRate = 0.1;
    

    printArray(x);

}

int main() {
   
    printf("Low Level Neural Network Program\n");

    initialiseWeights();

    return 0;
}