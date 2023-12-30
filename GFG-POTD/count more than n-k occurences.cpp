
//{ Driver Code Starts
// A C++ program to print elements with count more than n/k

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // Function to find all elements in array that appear more than n/k times.
    int countOccurence(int arr[], int n, int k)
    {
        unordered_map<int, int> mpp;
        for (int i = 0; i < n; i++)
        {
            mpp[arr[i]]++;
        }
        int cnt = 0;
        int freq = n / k;
        for (auto &it : mpp)
        {
            if (it.second > freq)
                cnt++;
        }
        return cnt;
    }
};

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, i;
        cin >> n;

        int arr[n];

        for (i = 0; i < n; i++)
            cin >> arr[i];
        int k;
        cin >> k;
        Solution obj;
        cout << obj.countOccurence(arr, n, k) << endl;
    }
    return 0;
}
