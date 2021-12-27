#include<stdio.h>
#include<omp.h>
#include<math.h>
#include <stdlib.h>
// long long N;
long long NUM_Threads = 8;
const long long SIZE = 15000;

long long arr[SIZE];

void swap(int* x, int* y)
{
	int t = *x;
	*x = *y;
	*y = t;
}

int partition (long long arr[], int low, int high)
{
	// int pivot = arr[high]; 
	// int i = (low - 1); // Index of smaller element
	// for (int j = low; j <= high- 1; j++)
	// {
	// 	if (arr[j] <= pivot)
	// 	{
	// 		i++; 
	// 		swap(&arr[i], &arr[j]);
	// 	}
	// }
	// swap(&arr[i + 1], &arr[high]);
	// return (i + 1);
    int low_index = low;
    int high_index = high;
    int i = low_index + 1;
    int j = high_index;
    long long key = arr[low_index];
    while(1){
        while(i < high_index && key >= arr[i]){
            i++;
        }
        while(key < arr[j]){
            j--;
        }
        if(i < j){
            long long temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
        else{
            long long temp = arr[low_index];
            arr[low_index] = arr[j];
            arr[j] = temp;
            return j;
        }
    }
}

void quickSort_using_serial(long long arr[], int low, int high)
{
	if (low < high)
	{
		//*here pi is the index of pivot element
		long long j = partition(arr, low, high);
        {
            {
                quickSort_using_serial(arr,low, j - 1);
            }
            {
                quickSort_using_serial(arr, j + 1, high);
            }
        }
	}
}

void quickSort_using_parallel(long long arr[], int low, int high)
{
	if (low < high)
	{
		//*here pi is the index of pivot element
		long long j = partition(arr, low, high);
        #pragma omp parallel sections
        {
            #pragma omp section
            {
                quickSort_using_parallel(arr,low, j - 1);
            }
            #pragma omp section
            {
                quickSort_using_parallel(arr, j + 1, high);
            }
        }
	}
}

int main()
{
    printf("\nNo of elements\t\t  Serial time  \t\t  Parallel Time  \t");
    printf("\n");
	double start_para, end_para, start_serial, end_serial;
	for( int i = 0; i < SIZE; i++)
    {
       arr[i] = rand() %10000;
       //printf("%d ", arr[i]);
    }
	int n = sizeof(arr)/sizeof(arr[0]);
    
    //*setting number of threads
    omp_set_num_threads(NUM_Threads);

    //!serial 
    start_serial = omp_get_wtime();
    {
    int id = omp_get_thread_num();
    int nthrds = omp_get_num_threads();
    //printf("Thread is %d\n",id);
        quickSort_using_serial(arr, 0, n-1);
    }
    end_serial = omp_get_wtime();


    //!parallel
    start_para = omp_get_wtime();

    #pragma omp parallel
    {
    int id = omp_get_thread_num();
    int nthrds = omp_get_num_threads();
    //printf("Thread is %d\n",id);
    #pragma omp single nowait
        quickSort_using_parallel(arr, 0, n-1);
    }
	end_para = omp_get_wtime();

	// printf("Sorted array: \n");
	// for (int i=0; i < SIZE; i++)
	// 	printf("%d ", arr[i]);
	// printf("\n");
    double serial_time = (end_serial-start_serial)*1000;
    double para_time = (end_para-start_para)*1000;
    int x = 0;
        if(serial_time>para_time){
             x = 1;
        }
    printf("\n  %lld  \t\t  %lf  \t\t  %lf  \t\t%d",SIZE,serial_time,para_time,x);
	return 0;
}

















//#pragma omp task firstprivate(arr, high,pi)