#include <bits/stdc++.h>
using namespace std;

#include <bits/stdc++.h>
using namespace std;

bool subsetSumUtil(int ind, int target, vector<int> &arr, vector<vector<int>> &dp)
{
    if (target == 0)
        return dp[ind][target] = true;

    if (ind == 0)
    {
        if (target == 0 && arr[0] == 0)
            return 2;
        if (target == 0 || target == arr[0])
            return 1;
        return 0;
    }
    if (dp[ind][target] != -1)
        return dp[ind][target];
    bool notTaken = subsetSumUtil(ind - 1, target, arr, dp);

    bool taken = false;
    if (arr[ind] <= target)
        taken = subsetSumUtil(ind - 1, target - arr[ind], arr, dp);
    return dp[ind][target] = notTaken + taken;
}

int minSubsetSumDifference(vector<int> &arr, int n, int givenDiff)
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
    int count = 0;
    for (int i = 0; i <= totSum; i++)
    {
        if (dp[n - 1][i] == true)
        {
            int diff = abs(i - (totSum - i));
            if (diff == givenDiff)
                count++;
        }
    }
    return count;
}

int main()
{
    vector<int> arr = {0, 0, 1};
    int k = 1;
    cout << "The minimum absolute difference is: " << minSubsetSumDifference(arr, arr.size(), k) << endl;

    return 0;
}

int findWaysUtil(int ind, int target, vector<int>& arr, vector<vector<int>>& dp) {
    if (target == 0)
        return 1;
    if (ind == 0)
        return (arr[0] == target) ? 1 : 0;
    if (dp[ind][target] != -1)
        return dp[ind][target];

    int notTaken = findWaysUtil(ind - 1, target, arr, dp);

    int taken = 0;
    if (arr[ind] <= target)
        taken = findWaysUtil(ind - 1, target - arr[ind], arr, dp);

    return dp[ind][target] = notTaken + taken;
}

int findWays(vector<int> &num, int k)
{
    int n = num.size();
    vector<vector<int>> dp(n, vector<int>(k + 1, -1));
    return findWaysUtil(n - 1, k, num, dp);
}

int main()
{
    vector<int> arr = {1, 2, 2, 3};
    int k = 3;

    cout << "The number of subsets found are " << findWays(arr, k);

    return 0;
}