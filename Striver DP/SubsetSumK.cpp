#include <bits/stdc++.h>
using namespace std;

bool recursion(int index, int target, vector<int> &arr)
{
    if (target == 0)
        return true;
    if (index == 0)
        return (arr[index] == target);
    bool notTake = recursion(index - 1, target, arr);
    bool take = false;
    if (arr[index] >= target)
    {
        take = recursion(index - 1, target - arr[index], arr);
    }
    return notTake || take;
}

bool memory(int index, int target, vector<int> &arr, vector<vector<int>> &dp)
{
    if (target == 0)
        return true;
    if (index == 0)
        return (arr[index] == target);
    if (dp[index][target] != -1)
        return dp[index][target];
    bool notTake = recursion(index - 1, target, arr);
    bool take = false;
    if (arr[index] >= target)
    {
        take = recursion(index - 1, target - arr[index], arr);
    }
    return dp[index][target] = notTake | take;
}

bool tabulation(int ind, int k, vector<int> &arr, vector<vector<bool>> &dp)
{
    for (int i = 0; i < dp.size(); i++)
    {
        dp[i][0] = true;
    }
    dp[0][arr[0]] = true;
    for (int index = 1; index < ind; index++)
    {
        for (int target = 1; target <= k; target++)
        {
            bool notTake = dp[index - 1][target];
            bool take = false;
            if (arr[index] >= target)
            {
                take = dp[index - 1][target - arr[index]];
            }
            dp[index][target] = notTake | take;
        }
    }
    return dp[ind - 1][k];
}

bool space(int ind, int k, vector<int> &arr)
{
    vector<bool> prev(k + 1, 0), curr(k + 1, 0);
    prev[0] = curr[0] = true;
    prev[arr[0]] = true;
    for (int index = 1; index < ind; index++)
    {
        for (int target = 1; target <= k; target++)
        {
            bool notTake = prev[target];
            bool take = false;
            if (arr[index] >= target)
            {
                take = prev[target - arr[index]];
            }
            curr[target] = notTake | take;
        }
        prev = curr;
    }
    return prev[k];
}
int main()
{
    vector<int> arr = {1, 2, 3, 4};
    int k = 4;
    int n = arr.size();

    if (recursion(n, k, arr))
        cout << "Subset with the given target found" << endl;
    else
        cout << "Subset with the given target not found" << endl;

    vector<vector<int>> dp(n + 1, vector<int>(k + 1, -1));
    if (memory(n, k, arr, dp))
        cout << "Subset with the given target found" << endl;
    else
        cout << "Subset with the given target not found" << endl;
    vector<vector<bool>> dp1(n, vector<bool>(k + 1, 0));
    if (tabulation(n, k, arr, dp1))
        cout << "Subset with the given target found" << endl;
    else
        cout << "Subset with the given target not found" << endl;
    if (space(n, k, arr))
        cout << "Subset with the given target found" << endl;
    else
        cout << "Subset with the given target not found" << endl;

    return 0;
}