
#include <bits/stdc++.h>
using namespace std;

bool subsetSumUtil(int ind, int target, vector<int> &arr, vector<vector<int>> &dp)
{
    if (target == 0)
        return dp[ind][target] = true;

    if (ind == 0)
        return dp[ind][target] = (arr[0] == target);
    if (dp[ind][target] != -1)
        return dp[ind][target];
    bool notTaken = subsetSumUtil(ind - 1, target, arr, dp);

    bool taken = false;
    if (arr[ind] <= target)
        taken = subsetSumUtil(ind - 1, target - arr[ind], arr, dp);
    return dp[ind][target] = notTaken || taken;
}

int minSubsetSumDifference(vector<int> &arr, int n)
{
    int totSum = 0;
    for (int i = 0; i < n; i++)
    {
        totSum += arr[i];
    }
    vector<vector<int>> dp(n, vector<int>(totSum + 1, -1));
    for (int i = 0; i <= totSum; i++)
    {
        bool dummy = subsetSumUtil(n - 1, i, arr, dp);
    }
    // bool ans = subsetSumUtil(n - 1, totSum, arr, dp);
    for (int i = 0; i < dp.size(); i++)
    {
        for (int j = 0; j < dp[0].size(); j++)
        {
            cout << dp[i][j] << " ";
        }
        cout << "" << endl;
    }

    int mini = 1e9;
    for (int i = 0; i <= totSum; i++)
    {
        if (dp[n - 1][i] == true)
        {
            int diff = abs(i - (totSum - i));
            mini = min(mini, diff);
        }
    }
    return mini;
}

int main()
{
    vector<int> arr = {1, 2, 3, 5};
    int n = arr.size();
    // int ans = minSubsetSumDifference(arr, n);
    cout << "The minimum absolute difference is: " << minSubsetSumDifference(arr, n) << endl;

    return 0;
}
