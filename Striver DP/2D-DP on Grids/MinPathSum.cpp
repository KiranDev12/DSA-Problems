#include <bits/stdc++.h>
using namespace std;

int recursion(int i, int j, vector<vector<int>> &matrix)
{
    if (i == 0 && j == 0)
        return matrix[i][j];
    if (i < 0 || j < 0)
        return 1e9;
    int up = matrix[i][j] + recursion(i - 1, j, matrix);
    int left = matrix[i][j] + recursion(i, j - 1, matrix);
    return min(up, left);
}
int memory(int i, int j, vector<vector<int>> &matrix, vector<vector<int>> &dp)
{
    if (i == 0 && j == 0)
        return matrix[i][j];
    if (i < 0 || j < 0)
        return 1e9;
    if (dp[i][j] != -1)
        return dp[i][j];
    int up = matrix[i][j] + memory(i - 1, j, matrix, dp);
    int left = matrix[i][j] + memory(i, j - 1, matrix, dp);
    return dp[i][j] = min(up, left);
}
int tabulation(int m, int n, vector<vector<int>> &matrix, vector<vector<int>> &dp)
{
    int ans;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == 0 && j == 0)
            {
                ans = dp[0][0];
                continue;
            }
            int up = dp[i][j];
            if (i > 0)
            {
                up += dp[i - 1][j];
            }
            else
            {
                up += 1e9;
            }
            int left = dp[i][j];
            if (j > 0)
            {
                left += dp[i][j - 1];
            }
            else
            {
                left += 1e9;
            }
            dp[i][j] = min(up, left);
        }
    }
    return dp[m - 1][n - 1];
}
`
int main()
{
    vector<vector<int>> matrix{
        {5, 9, 6},
        {11, 5, 2}};

    int n = matrix.size();
    int m = matrix[0].size();

    cout << "Minimum sum path: " << recursion(n - 1, m - 1, matrix) << endl;
    // cout << "Minimum sum path: " << minPathSum(n - 1, m - 1, matrix) << endl;
    // Correcting dimensions of dp array
    vector<vector<int>> dp(n, vector<int>(m, -1));
    cout << "Minimum sum path: " << memory(n - 1, m - 1, matrix, dp) << endl;
    cout << "Minimum sum path: " << tabulation(n, m, matrix, dp) << endl;
    return 0;
}
