#include <bits/stdc++.h>
using namespace std;

int recursion(int m, int n)
{
    if (m == 0 && n == 0)
        return 1;
    if (m < 0 || n < 0)
        return 0;
    int up = recursion(m - 1, n);
    int left = recursion(m, n - 1);
    return up + left;
}
int memory(int m, int n, vector<vector<int>> &dp)
{
    if (dp[m][n] != -1)
        return dp[m][n];
    if (m == 0 && n == 0)
        return 1;
    if (m < 0 || n < 0)
        return 0;
    int up = recursion(m - 1, n);
    int left = recursion(m, n - 1);
    return dp[m][n] = up + left;
}
int tabulation(int m, int n, vector<vector<int>> &dp)
{
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
         
            if (i == 0 && j == 0) {
                dp[i][j] = 1;
                continue; 
            }

            int up = 0;
            int left = 0;

            if (i > 0)
                up = dp[i - 1][j];

            if (j > 0)
                left = dp[i][j - 1];
            dp[i][j] = up + left;
        }
    }
    return dp[m - 1][n - 1];
}
int main()
{
    int m = 3;
    int n = 2;

    cout << recursion(m - 1, n - 1) << endl;
    vector<vector<int>> dp(m, vector<int>(n, -1));
    cout << memory(m - 1, n - 1, dp) << endl;
    cout << tabulation(m, n, dp) << endl;
    return 0;
}