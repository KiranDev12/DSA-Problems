#include <bits/stdc++.h>
using namespace std;

int recursion(int ind, vector<int> &arr)
{
    if (ind == 0)
        return arr[0];
    if (ind < 0)
        return 0;
    int pick = arr[ind] + recursion(ind - 2, arr);
    int notpick = recursion(ind - 1, arr);
    return max(pick, notpick);
}

int memory(vector<int> &arr, vector<int> &dp, int ind)
{
    if (dp[ind] != -1)
        return dp[ind];
    if (ind == 0)
        return arr[0];
    if (ind < 0)
        return 0;
    int pick = arr[ind] + memory(arr, dp, ind - 2);
    int notpick = memory(arr, dp, ind - 1);
    return dp[ind] = max(pick, notpick);
}

int tabulation(vector<int> &arr, vector<int> &dp, int ind)
{
    dp[0] = 0;
    for (int i = 1; i < arr.size(); i++)
    {
        int take = arr[ind];
        if (i > 1)
            take += dp[i - 2];
        int notTake = dp[i - 1];
        dp[ind] = max(take, notTake);
    }
    return dp[arr.size() - 1];
}
int space(vector<int> &arr, int ind)
{
    int curr = arr[0];
    int prev = 0;
    for (int i = 1; i < ind; i++)
    {
        int pick = arr[i];
        if (i > 1)
            pick += prev;

        int nonPick = curr;

        int cur_i = max(pick, nonPick);
        prev = curr;
        curr = cur_i;
    }
    return curr;
}
int main()
{
    vector<int> arr{2, 1, 4, 9};
    int n = arr.size();
    cout << recursion(n, arr) << endl;
    vector<int> dp(n, -1);
    cout << memory(arr, dp, n - 1) << endl;
    cout << tabulation(arr, dp, n) << endl;
    cout << space(arr, n) << endl;
    return 0;
}