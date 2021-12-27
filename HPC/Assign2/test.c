#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <sys/time.h>
#include <omp.h>
int main()
{
    int r1, c1, r2, c2, i, j, k;
    printf("Data Point\tSerial\t\tParallel\n");
    for(int loop = 5 ; loop < 700 ; loop+=50){
    r1 = c1 = r2 = c2 = loop;
    int cores = omp_get_num_procs();
    int a[r1][c1],b[r2][r2],final_multiplication[r1][c2];
    //printf("Enter the elements of First matrix\n");
    for (i = 0; i < r1; i++)
    {
        for (j = 0; j < c1; j++)
        {
            a[i][j] = 3000000;
            // scanf("%d", &a[i][j]);
        }
    }
    printf("\n");
    for (i = 0; i < r2; i++)
    {
        for (j = 0; j < c2; j++)
        {
            b[i][j] = 3000000;
            // scanf("%d", &a[i][j]);
        }
    }
    if (c1 != r2 || r1 < 0 || c1 < 0 || r2 < 0 || c2 < 0)
    {
        printf("\nMatrix multiplication not possible\n");
    }
    // for serial
    double start = omp_get_wtime();
    #pragma omp parallel for
    for (i = 0; i < r1; i++)
    {
        for (j = 0; j < c2; j++)
        {
            final_multiplication[i][j] = 0;
            for (k = 0; k < r2; k++)
            {
                final_multiplication[i][j] += a[i][k] * b[k][j];
            }
           // printf("%d ", final_multiplication[i][j]);
        }
       // printf("\n");
    }
    double end = omp_get_wtime();
    //for parallel
    double start1 = omp_get_wtime();
    #pragma omp parallel for
    for (i = 0; i < r1; i++)
    {
        for (j = 0; j < c2; j++)
        {
            final_multiplication[i][j] = 0;
            for (k = 0; k < r2; k++)
            {
                final_multiplication[i][j] += a[i][k] * b[k][j];
            }
           // printf("%d ", final_multiplication[i][j]);
        }
       // printf("\n");
    }
    double end1 = omp_get_wtime();
    printf("%d\t\t%lf\t%lf\n",loop*loop,( end-start)*1000,(end1-start1)*1000);
    // for (i = 0; i < r1; i++)
    // {
    //     for (j = 0; j < c2; j++)
    //     {
    //         printf("%d\t", final_multiplication[i][j]);
    //     }
    //     printf("\n");
    // }
    // return 0;
    }
}
