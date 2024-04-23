#include <bits/stdc++.h>
using namespace std;
int n = 5;
int brute(int arr[])
{
    sort(arr, arr + n);
    return arr[n - 1];
}
int optimal(int arr[])
{
    int largest = arr[0];
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > largest)
        {
            largest = arr[i];
        }
    }
    return largest;
}
int main()
{
    int arr[5] = {2, 1, 5, 4, 2};
    cout << brute(arr) << endl;
    cout << optimal(arr) << endl;
}