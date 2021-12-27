#include <stdio.h>
#include <pthread.h>
#include <bits/stdc++.h>
#include <omp.h>
using namespace std;
int main()
{
    int cores = omp_get_num_procs();
    cout << cores << endl;
}