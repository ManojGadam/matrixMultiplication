typedef struct
{
    double **A;
    double **B;
    double **C;
    int rows;
    int id;
    int *visited;
    int n;
    int m;
}thread_info;