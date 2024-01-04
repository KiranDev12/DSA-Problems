#include <bits/stdc++.h>
using namespace std;

int brute(vector<int> &a, long long k)
{
    int n = a.size(); // size of the array.

    int len = 0;
    for (int i = 0; i < n; i++)
    {
        long long s = 0; // Sum variable
        for (int j = i; j < n; j++)
        {
            s += a[j];
            if (s == k)
                len = max(len, j - i + 1);
        }
    }
    return len;
}
int optimal(vector<int>& a, int k) {
    int n = a.size(); // size of the array.

    map<int, int> preSumMap;
    int sum = 0;
    int maxLen = 0;
    for (int i = 0; i < n; i++) {
        //calculate the prefix sum till index i:
        sum += a[i];

        // if the sum = k, update the maxLen:
        if (sum == k) {
            maxLen = max(maxLen, i + 1);
        }

        // calculate the sum of remaining part i.e. x-k:
        int rem = sum - k;

        //Calculate the length and update maxLen:
        if (preSumMap.find(rem) != preSumMap.end()) {
            int len = i - preSumMap[rem];
            maxLen = max(maxLen, len);
        }

        //Finally, update the map checking the conditions:
        if (preSumMap.find(sum) == preSumMap.end()) {
            preSumMap[sum] = i;
        }
    }

    return maxLen;
}

int main()
{
    vector<int> arr = {2, 3, 5, 1, 9};
    long long k = 10;
    int len = brute(arr, k);
    cout << "The length of the longest subarray is: " << len << "\n";
    len = optimal(arr, k);
    cout << "The length of the longest subarray is: " << len << "\n";
    return 0;
}