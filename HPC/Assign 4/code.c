//Name : Aniruddha Shende
//Roll no : PE04
//Batch : E1
//Panel : E

#include <omp.h>
#include <stdio.h>
#include <stdlib.h>

long long SIZE = 10;
long long N;
long long NUM_Threads = 8;

double serial_mul(double *a, double *b, double *c){
    double start,end;
    start=omp_get_wtime();
    for(int i = 0; i < N ; i++){
        c[i] = a[i] * b[i];
    }
    end=omp_get_wtime();
    return (end-start)*1000;
}
double serial_sub(double *a, double *b, double *c){
    double start,end;
    start=omp_get_wtime();
    for(int i = 0; i < N ; i++){
        c[i] = a[i] - b[i];
    }
    end=omp_get_wtime();
    return (end-start)*1000;
}
double serial_add(double *a, double *b, double *c){
    double start,end;
    start=omp_get_wtime();
    for(int i = 0; i < N ; i++){
        c[i] = a[i] + b[i];
    }
    end=omp_get_wtime();
    return (end-start)*1000;
}

double parallel_mul(double *a, double *b, double *c){
    double start,end;
    start=omp_get_wtime();
    #pragma omp parallel for 
    for(int i = 0; i < N ; i++){
        c[i] = a[i] * b[i];
    }
    end=omp_get_wtime();
    return (end-start)*1000;
}

double parallel_sub(double *a, double *b, double *c){
    double start,end;
    start=omp_get_wtime();
    #pragma omp parallel for 
    for(int i = 0; i < N ; i++){
        c[i] = a[i] - b[i];
    }
    end=omp_get_wtime();
    return (end-start)*1000;
}

double parallel_add(double *a, double *b, double *c){
    double start,end;
    start=omp_get_wtime();
    #pragma omp parallel for 
    for(int i = 0; i < N ; i++){
        c[i] = a[i] + b[i];
    }
    end=omp_get_wtime();
    return (end-start)*1000;
}

int main () {
    omp_set_num_threads(NUM_Threads);
    printf("\n----------------------------Addition----------------------------\n");
    printf("\nNo of elements\t\t  Serial time  \t\t  Parallel Time  \t");
    printf("\n");
    for(int i = 1000 ; i < 50000 ; i+=1000)
    {
        SIZE = i;
        double *a, *b, *c;
        N = SIZE;
        long long elements_per_thread;
        long long all_threads = NUM_Threads;

        a = (double*)malloc(sizeof(double)*N);
        b = (double*)malloc(sizeof(double)*N);
        c = (double*)malloc(sizeof(double)*N);

        for(int i=0;i<SIZE;i++)
        {
            a[i]=rand()%SIZE;
        }
        for(int i=0;i<SIZE;i++)
        {
            b[i]=rand()%SIZE;
        }
        double serial_time_add = serial_add(a,b,c);
        double parallel_time_add = parallel_add(a,b,c);
        int x = 0;
        if(serial_time_add>parallel_time_add){
             x = 1;
        }
        printf("\n  %lld  \t\t  %lf  \t\t  %lf  \t\t%d",SIZE,serial_time_add,parallel_time_add,x);
        free(a);
        free(b);
        free(c);
    }
    printf("\n\n\n\n");
    printf("\n---------------------Multiplication--------------------------\n");
    printf("\nNo of elements\t\t  Serial time  \t\t  Parallel Time  \t");
    printf("\n");
    for(int i = 1000 ; i < 50000 ; i+=1000)
    {
        SIZE = i;
        double *a, *b, *c;
        N = SIZE;
        long long elements_per_thread;
        long long all_threads = NUM_Threads;

        a = (double*)malloc(sizeof(double)*N);
        b = (double*)malloc(sizeof(double)*N);
        c = (double*)malloc(sizeof(double)*N);

        for(int i=0;i<SIZE;i++)
        {
            a[i]=rand()%SIZE;
        }
        for(int i=0;i<SIZE;i++)
        {
            b[i]=rand()%SIZE;
        }
        double serial_time_mul = serial_mul(a,b,c);
        double parallel_time_mul = parallel_mul(a,b,c);
        int x = 0;
        if(serial_time_mul>parallel_time_mul){
             x = 1;
        }
        printf("\n  %lld  \t\t  %lf  \t\t  %lf  \t\t %d",SIZE,serial_time_mul,parallel_time_mul,x);
        free(a);
        free(b);
        free(c);
    }
    printf("\n\n\n\n");
    printf("\n--------------------------Subtraction---------------------------\n");
    printf("\nNo of elements\t\t  Serial time  \t\t  Parallel Time  \t");
    printf("\n");
    for(int i = 1000 ; i < 50000 ; i+=1000)
    {
        SIZE = i;
        double *a, *b, *c;
        N = SIZE;
        long long elements_per_thread;
        long long all_threads = NUM_Threads;

        a = (double*)malloc(sizeof(double)*N);
        b = (double*)malloc(sizeof(double)*N);
        c = (double*)malloc(sizeof(double)*N);

        for(int i=0;i<SIZE;i++)
        {
            a[i]=rand()%SIZE;
        }
        for(int i=0;i<SIZE;i++)
        {
            b[i]=rand()%SIZE;
        }
        double serial_time_sub = serial_sub(a,b,c);
        double parallel_time_sub = parallel_sub(a,b,c);
        int x = 0;
        if(serial_time_sub>parallel_time_sub){
             x = 1;
        }
        printf("\n  %lld  \t\t  %lf  \t\t  %lf  \t\t%d",SIZE,serial_time_sub,parallel_time_sub,x);
        free(a);
        free(b);
        free(c);
    }
}
