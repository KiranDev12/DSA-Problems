
#include <bits/stdc++.h>
using namespace std;
int recursive(int arr[], int l, int r, int x)
{
    if (r >= l)
    {
        int mid = l + (r - l) / 2;
        if (arr[mid] == x)
            return mid;
        if (arr[mid] > x)
            return recursive(arr, l, mid - 1, x);
        return recursive(arr, mid + 1, r, x);
    }
    return -1;
}

int iterative(int arr[], int l, int r, int x)
{

    while (l <= r)
    {
        int mid = l + (r - l) / 2;
        if (arr[mid] == x)
            return mid;
        else if (arr[mid] > x)
        {
            r = mid - 1;
        }
        else
        {
            l = mid + 1;
        }
    }
    return -1;
}

int main(void)
{
    int arr[] = {2, 3, 4, 10, 40};
    int x = 40;
    int n = sizeof(arr) / sizeof(arr[0]);
    int result1 = recursive(arr, 0, n - 1, x);
    int result2 = recursive(arr, 0, n - 1, x);
    (result1 == -1)
        ? cout << "Element is not present in array"
        : cout << "Element is present at index " << result1 << endl;
    cout << "Element is present at index " << result2;
    return 0;
}
