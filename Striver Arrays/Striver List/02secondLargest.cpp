#include <bits/stdc++.h>
using namespace std;
int n = 6;
int brute(int arr[])
{
    sort(arr, arr + n);
    int largest = arr[n - 1];
    int i;
    for (i = n - 2; i > 0; i--)
    {
        if (arr[i] == largest)
        {
            continue;
        }
        break;
    }
    return arr[i];
}

int better(int arr[])
{
    int largest = arr[0];
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > largest)
        {
            largest = arr[i];
        }
    }
    int second = -1;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > second && arr[i] != largest)
        {
            second = arr[i];
        }
    }
    return second;
}
int optimal(int arr[])
{
    int largest = arr[0];
    int second = -1;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > largest)
        {
            second = largest;
            largest = arr[i];
        }
        else if (arr[i] < largest && arr[i] > second)
        {
            second = arr[i];
        }
    }
    return second;
}
int main()
{
    int arr[6] = {1, 4, 6, 2, 19, 18};
    cout << brute(arr) << endl;
    cout << better(arr) << endl;
    cout << optimal(arr) << endl;
}