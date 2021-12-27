
// Name : Aniruddha Shende
// Roll no : PE04
// Batch : E1
// Panel : E
#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <sys/time.h>
#include <omp.h>
int main()
{
    int r1, c1, r2, c2, i, j, k;
    printf("Enter 1st matrix rows : ");
    scanf("%d", &r1);
    printf("Enter 1st matrix columns : ");
    scanf("%d", &c1);
    int a[r1][c1];
    //printf("Enter the elements of First matrix\n");

    for (i = 0; i < r1; i++)
    {
        for (j = 0; j < c1; j++)
        {
            //assigning a random value
            a[i][j] = 3000;
            // scanf("%d", &a[i][j]);
        }
    }
    printf("\n");

    printf("Enter 2nd matrix rows : ");
    scanf("%d", &r2);
    printf("Enter 2nd matrix columns : ");
    scanf("%d", &c2);
    int b[r2][c2];
    int final_multiplication[r1][c2];
    printf("Enter the elements of Second matrix\n");
    for (i = 0; i < r2; i++)
    {
        for (j = 0; j < c2; j++)
        {
            //assigning a random value
            b[i][j] = 3000;
            // scanf("%d", &a[i][j]);
        }
    }
    printf("\n");
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
    printf("\nTime taken for Serial: %lf\n", (end-start)*1000);


    //for parallel
    start = omp_get_wtime();
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
    end = omp_get_wtime();
    printf("\nTime taken for Parallel: %lf\n", (end-start)*1000);
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

