#include <bits/stdc++.h>
using namespace std;
int memory(int i, vector<int> &wt, vector<int> &val, int n, int target, vector<vector<int>> &dp)
{
    if (i == 0)
    {
        if (wt[0] <= target)
            return val[0];
        return 0;
    }
    if (dp[i][target] != -1)
        return dp[i][target];
    int notTake = memory(i - 1, wt, val, n, target, dp);
    int take = INT_MIN;
    if (target >= wt[i])
        take = val[i] + memory(i - 1, wt, val, n, target - wt[i], dp);
    return dp[i][target] = max(notTake, take);
}
int tabulation(vector<int> &wt, vector<int> &val, int n, int target, vector<vector<int>> &dp)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < target + 1; j++)
        {
            if (i == 0)
            {
                if (wt[0] <= j)
                    return dp[0][j];
                return 0;
            }
            if (dp[i][j] != -1)
                return dp[i][j];
            int notTake = dp[i - 1][j];
            int take = INT_MIN;
            if (j >= wt[i])
                take = val[i] + dp[i - 1][j - wt[i]];
            dp[i][j] = max(notTake, take);
            cout<<dp[i][j];
        }
        cout<<" "<<endl;
    }
    return dp[n-1][target];
}

int main()
{
    vector<int> wt = {1, 2, 4, 5};
    vector<int> val = {5, 4, 8, 6};
    int W = 5;
    int n = wt.size();
    vector<vector<int>> dp(n, vector<int>(W + 1, -1));
    cout << "The Maximum value of items the thief can steal is " << memory(n - 1, wt, val, n, W, dp);
    cout << "The Maximum value of items the thief can steal is " << tabulation(wt, val, n, W, dp);
    return 0;
}