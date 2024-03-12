#include <bits/stdc++.h>
using namespace std;

void brute(int arr[], int d, int n) // SIMPLE BY TAKING EXTRA SPACE TO STORE TEMP[K] elements
    {
        temp[i] = arr[i];
    }
    for (int i = d; i < n; i++)
    {
        arr[i - d] = arr[i];
    }
    // int j = 0;
    for (int i = n - d; i < n; i++)
    {
        // arr[i]=temp[j];
        arr[i] = temp[i - (n - d)];
        // j++;
    }
}

void optimal(int arr[], int d, int n) // in O(1) space
{
    // triple reversals
    d = d % n;
    reverse(arr, arr + d);
    reverse(arr + d, arr + n);
    reverse(arr, arr + n);
}
int main()
{

    int arr[7] = {1, 2, 3, 4, 5, 6, 7};

    // brute(arr, 3, 7);
    optimal(arr, 3, 7);
    for (int i = 0; i < 7; i++)
    {
        cout << arr[i] << endl;
    }

    return 0;
}