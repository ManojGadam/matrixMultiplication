#include <stdio.h>
#include <math.h>
#include "compare.h"
void compare(double **C,double **D,int size)
{
    double epsilon = 0.00001; 
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if(fabs(C[i][j]-D[i][j])>epsilon)printf("Error: Matrices are not equal\n");
        }
        
    }
    printf("Success:Matrices are equal\n");
}