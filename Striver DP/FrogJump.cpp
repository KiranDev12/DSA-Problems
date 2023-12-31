
#include <bits/stdc++.h>

using namespace std;

int recursion(int ind, vector<int> &height)
{
    if (ind == 0)
        return 0;
    int left = recursion(ind - 1, height) + abs(height[ind] - height[ind - 1]);
    int right = INT_MAX;
    if (ind > 1)
        right = recursion(ind - 2, height) + abs(height[ind] - height[ind - 2]);
    return min(left, right);
}
int memory(int ind, vector<int> &height, vector<int> &dp)
{
    if (ind == 0)
        return 0;
    if (dp[ind] != -1)
        return dp[ind];
    int left = memory(ind - 1, height, dp) + abs(height[ind] - height[ind - 1]);
    int right = INT_MAX;
    if (ind > 1)
        right = memory(ind - 2, height, dp) + abs(height[ind] - height[ind - 2]);
    return dp[ind] = min(left, right);
}
int main()
{
    vector<int> height{30, 10, 60, 10, 60, 50};
    int n = height.size();
    vector<int> dp(n, -1);
    cout << recursion(n - 1, height) << endl;
    cout << memory(n - 1, height, dp) << endl;

    // TABULATION (TOP DOWN APPROACH)
    vector<int> dpp(n, -1);
    dpp[0] = 0;
    for (int ind = 1; ind < n; ind++)
    {
        int jumpTwo = INT_MAX;
        int jumpOne = dpp[ind - 1] + abs(height[ind] - height[ind - 1]);
        if (ind > 1)
            jumpTwo = dpp[ind - 2] + abs(height[ind] - height[ind - 2]);

        dpp[ind] = min(jumpOne, jumpTwo);
    }
    cout << dpp[n - 1] << endl;

    // SPACE OPTIMIZED
    int prev = 0;
    int prev2 = 0;
    for (int i = 1; i < n; i++)
    {

        int jumpTwo = INT_MAX;
        int jumpOne = prev + abs(height[i] - height[i - 1]);
        if (i > 1)
            jumpTwo = prev2 + abs(height[i] - height[i - 2]);

        int cur_i = min(jumpOne, jumpTwo);
        prev2 = prev;
        prev = cur_i;
    }
    cout << prev << endl;
}