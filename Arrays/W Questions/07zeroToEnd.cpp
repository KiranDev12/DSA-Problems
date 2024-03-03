#include <bits/stdc++.h>
using namespace std;

void brute(int arr[])
{
    vector<int> v;
    for (int i = 0; i < 10; i++)
    {
        if (arr[i] != 0)
        {
            v.push_back(arr[i]);
        }
    }
    int j = 0;
    for (int i = 0; i < 10; i++)
    {
        if (j < v.size())
        {
            arr[i] = v[j];
            j++;
        }
        else
        {
            arr[i] = 0;
        }
    }
}

void optimal(int a[], int n)
{
    int j = -1;
    // place the pointer j:
    for (int i = 0; i < n; i++)
    {
        if (a[i] == 0)
        {
            j = i;
            break;
        }
    }
    if (j == -1)
        return;

    for (int i = j + 1; i < n; i++)
    {
        if (a[i] != 0)
        {
            swap(a[i], a[j]);
            j++;
        }
    }
}
int main()
{
    int a[10] = {1, 0, 2, 3, 0, 0, 6, 7, 1, 10};

    // brute(arr);
    optimal(a, 10);
    for (int i = 0; i < 10; i++)
    {
        cout << a[i] << endl;
    }
}