#include <iostream>
#include <bits/stdc++.h>
#include <omp.h>
#include <sys/time.h>
using namespace std;

vector<vector<int>> take_input(int row, int col)
{

    vector<vector<int>> res(row, vector<int>(col, 0));

    for (int r = 0; r < row; r++)
    {

        for (int c = 0; c < col; c++)
        {

            int var = 0;

            // cin>> var;

            res[r][c] = var;
        }
    }

    return res;
}

vector<vector<int>> mul_parallel(vector<vector<int>> &mat1, vector<vector<int>> &mat2)
{

    vector<vector<int>> res(mat1.size(), vector<int>(mat2[0].size(), 0));

    int col = 0;

    int c1 = mat1[0].size();

    double start = omp_get_wtime();

#pragma omp parallel for

    for (int row = 0; row < mat1.size(); row++)
    {

        int prod = 0;

        for (int c = 0; c < c1; c++)
        {

            prod += mat1[row][c] * mat2[c][col];
        }

        // cout<<" value of thread "<<omp_get_thread_num()<<endl;

        res[row][col] = prod;

        col++;

        if (col == mat2[0].size())
        {
            col = 0;
            row++;
        }
        else
            row--;
    }

    double end = omp_get_wtime();

    cout << "Time" << end - start << endl;

    return res;
}
vector<vector<int>> mul_series(vector<vector<int>> &mat1, vector<vector<int>> &mat2)
{

    vector<vector<int>> res(mat1.size(), vector<int>(mat2[0].size(), 0));

    int col = 0;

    int c1 = mat1[0].size();

    double start = omp_get_wtime();

    // pragma omp parallel for

    for (int row = 0; row < mat1.size(); row++)
    {

        int prod = 0;

        for (int c = 0; c < c1; c++)
        {

            prod += mat1[row][c] * mat2[c][col];
        }

        // cout<<" value of thread "<<omp_get_thread_num()<<endl;

        res[row][col] = prod;

        col++;

        if (col == mat2[0].size())
        {
            col = 0;
            row++;
        }
        else
            row--;
    }

    double end = omp_get_wtime();

    cout << "Time" << end - start << endl;

    return res;
}

int main()
{

    int r1, c1, r2, c2;

    cout << "Enter rows and colums of first matrix" << endl;

    cin >> r1 >> c1;

    cout << "Enter rows and columns of second matrix" << endl;

    cin >> r2 >> c2;

    if (c1 != r2 || r1 < 0 || c1 < 0 || r2 < 0 || c2 < 0)
    {

        cout << "Multiplication invalid" << endl;

        main();

        return 0;
    }

    cout << "Enter data of matrix1" << endl;
    auto matrix1 = take_input(r1, c1);

    cout << "Enter data of matrix2" << endl;
    auto matrix2 = take_input(r2, c2);

    vector<vector<int>> res_s = mul_series(matrix1, matrix2);
    vector<vector<int>> res_p = mul_parallel(matrix1, matrix2);

    //  cout<<"Resultant matrix"<<endl;

    //  for(int t=0;t<r1;t++)
    //  {
    //    for(int p=0;p<c2;p++)
    //    {
    //      cout<<res[t][p]<<" ";

    //    }

    //    cout<<endl;
    //  }
}