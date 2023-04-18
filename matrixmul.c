#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <math.h>
#include "header.h"
#include "seqMul.h"
#include "randmize.h"
#include "compare.h"

//
void* thread_mul(void *arg); 

int main()
{
    int n,m;
    double **A,**B,**C,**D;
    printf("Enter matrix size and number of threads");
    fflush(stdout);
    scanf("%d %d",&n,&m);
    if(m < 1){
        printf("number of threads cannot be less than 1\n");
        fflush(stdout);
        return 0;
        }
    else if(n < 1){
        printf("Matrix size cannot be less than 1\n");
        fflush(stdout);
        return 0;
        }
    pthread_t threads[m];
    srand(time(NULL));
    A = randmize(n);
    B = randmize(n);
    C = seqMul(A,B,n);
    D = (double**)malloc(n*sizeof(double*));
    int* visited = malloc(n*sizeof(int));
    for (int i = 0; i < n; i++)
    {
        D[i] = malloc(sizeof(double)*n);
        visited[i] = -1;
    }
    //print sequential result
     for (int i = 0; i < n; i++)
     {
         for (int j = 0; j < n; j++)
         {
             printf("%f ",C[i][j]);
         }
         printf("\n");
     }
    for (int i = 0; i < m; i++)
    {
        thread_info* t_info = malloc(sizeof(thread_info));
        t_info->id = i;
        t_info->visited = visited;
        t_info->A = A;
        t_info->B = B;
        t_info->C = D;
        t_info->n = n;
        t_info->m = m;
        t_info->rows = i%n;
        pthread_create(&threads[i],NULL,thread_mul,(void *)t_info);
    }
    for (int i = 0; i < m; i++)
    {
        pthread_join(threads[i],NULL);
    }
    //print threaded result
    printf("\n");
     for (int i = 0; i < n; i++)
     {
         for (int j = 0; j < n; j++)
         {
             printf("%f ",D[i][j]);
         }
         printf("\n");
     }
    compare(C,D,n);
    
}




void* thread_mul(void *arg)
{
    thread_info* args = (thread_info*)arg;
    int end_row = args->rows;
    int k = args->visited[args->rows];
    if(args->m < args->n && args->id+1 == args->m)
    {
        end_row = args->n-args->rows+1;
    }
    else if(args->m > args->n)
    {
        if(args->visited[args->rows]>-1)return 0; //this computation is already done
    }
    for (int i = args->rows; i <= end_row; i++)
    {
        for (int j = 0; j < args->n; j++)
        {
            args->C[i][j] = 0;
            for (int k = 0; k < args->n; k++)
            {
                args->C[i][j] += args->A[i][k]*args->B[k][j];
            }
            
        }
        args->visited[i] = i;
    }
    
}


//since two matrices are comprised of doubles we have to use fabs to calculate inequality
