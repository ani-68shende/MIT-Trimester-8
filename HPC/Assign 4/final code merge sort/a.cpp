#include <bits/stdc++.h>
using namespace std;

void merge(vector<int> &nums, int l, int r)
{

    int mid = (l + r) / 2;

    int lo = l;

    int hi = mid + 1;

    vector<int> temp(r - l + 1);

    int c = 0;

    while (lo <= mid && hi <= r)
    {

        if (nums[lo] < nums[hi])
        {

            temp[c++] = nums[lo++];
        }
        else
        {
            temp[c++] = nums[hi++];
        }
    }

    while (lo <= mid)
        temp[c++] = nums[lo++];

    while (hi <= r)
        temp[c++] = nums[hi++];

    c = 0;

    for (int e = l; e <= r; e++)
    {
        nums[e] = temp[c++];
    }
}

// 65 70 75 80 85 60 55 50 45

void merge_sort(vector<int> &nums, int l, int r, int level)
{

    if (r > l)
    {

        int mid = (l + r) / 2;

        merge_sort(nums, l, mid, level + 1);

        cout << "Left half of the array"
             << " in level:" << level << endl;

        for (int p = l; p <= mid; p++)
        {
            cout << nums[p] << " ";
        }

        cout << endl;

        merge_sort(nums, mid + 1, r, level + 1);

        cout << "Right half of the array"
             << " in level:" << level << endl;

        for (int p = mid + 1; p <= r; p++)
        {
            cout << nums[p] << " ";
        }
        cout << endl;

        merge(nums, l, r);
    }
}

int main()
{

    while (true)
    {

        cout << "Do you want to continue" << endl;
        int input;
        cin >> input;

        if (!input)
            return 0;

        cout << "Enter length of the array" << endl;

        int n;
        cin >> n;

        vector<int> nums(n);

        for (int r = 0; r < n; r++)
        {
            cout << "Enter element " << endl;

            int temp;
            cin >> temp;

            nums[r] = temp;
        }

        merge_sort(nums, 0, n - 1, 1);

        cout << "Sorted array" << endl;

        for (int r = 0; r < n; r++)
        {
            cout << nums[r] << " ";
        }

        cout << endl;
    }

    return 0;
}