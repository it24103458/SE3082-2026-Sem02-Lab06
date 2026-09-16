#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

#define N 1000000
#define STRIP_SIZE 1024

int main()
{
    double *A, *B, *C;

    A = malloc(sizeof(double) * N);
    B = malloc(sizeof(double) * N);
    C = malloc(sizeof(double) * N);


    // Initialize arrays
    for(int i = 0; i < N; i++)
    {
        A[i] = i * 1.5;
        B[i] = i * 2.5;
    }


    double start = omp_get_wtime();


    #pragma omp parallel for
    for(int strip = 0; strip < N; strip += STRIP_SIZE)
    {
        int end = strip + STRIP_SIZE;

        if(end > N)
            end = N;


        for(int i = strip; i < end; i++)
        {
            C[i] = A[i] * B[i];
        }
    }


    double end = omp_get_wtime();


    printf("C[100] = %f\n", C[100]);
    printf("Execution time = %f seconds\n", end-start);


    free(A);
    free(B);
    free(C);

    return 0;
}
