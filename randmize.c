#include <stdio.h>
#include <stdlib.h>
#include "randmize.h"
double** randmize(int size)
{
    double **matrix = (double**)malloc(size * sizeof(double*));
    for (int i = 0; i < size; i++) {
        (matrix)[i] = malloc(sizeof(double) * size);
        for (int j = 0; j < size; j++) {
            matrix[i][j] = (double)(rand() % 10000 + 1) / 100;
            //printf("%f ",matrix[i][j]);
        }
        //printf("\n");
    }
    return matrix;
}
