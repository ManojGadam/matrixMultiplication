#include <stdio.h>
#include <stdlib.h>
#include "seqMul.h"
double** seqMul(double **A,double **B,int size)
{
    double **C = (double**)malloc(size * sizeof(double*));
    for (int i = 0; i < size; i++)
    {
        (C)[i] = malloc(sizeof(double) * size);
        for (int j = 0; j < size; j++)
        {
            C[i][j] = 0;
            for (int k = 0; k < size; k++)
            {
                C[i][j] += A[i][k]*B[k][j];
            }
            
        }
        
    }
    return C;
    
}