#include <bits/stdc++.h>
using namespace std;
bool comp(int a, int b)
{
    return (a < b);
}
int recursion(int i, int j, int n, vector<vector<int>> &matrix)
{
    if (i == n - 1)
        return matrix[i][j];
    if (i < 0 || j < 0 || i > n - 1 || j > n - 1)
        return -1e9;
    int down = matrix[i][j] + recursion(i + 1, j, n, matrix);
    int left = matrix[i][j] + recursion(i + 1, j - 1, n, matrix);
    int right = matrix[i][j] + recursion(i + 1, j + 1, n, matrix);
    return max({down, left, right}, comp);
}

int getMaxUtil(int i, int j, int m, vector<vector<int>> &matrix, vector<vector<int>> &dp)
{
    // Base Conditions
    if (j < 0 || j >= m)
        return -1e9; // A very large negative value to represent an invalid path
    if (i == 0)
        return matrix[0][j]; // The maximum path sum for the top row is the value itself

    if (dp[i][j] != -1)
        return dp[i][j]; // If the result for this cell is already calculated, return it

    // Calculate the maximum path sum by considering three possible directions: up, left diagonal, and right diagonal
    int up = matrix[i][j] + getMaxUtil(i - 1, j, m, matrix, dp);
    int leftDiagonal = matrix[i][j] + getMaxUtil(i - 1, j - 1, m, matrix, dp);
    int rightDiagonal = matrix[i][j] + getMaxUtil(i - 1, j + 1, m, matrix, dp);

    return dp[i][j] = max(up, max(leftDiagonal, rightDiagonal));
}
int main()
{
    // Define the matrix as a 2D vector
    vector<vector<int>> matrix{{1, 2, 10, 4},
                               {100, 3, 2, 1},
                               {1, 1, 20, 2},
                               {1, 2, 2, 1}};
    int maxi = INT_MIN;
    int n = matrix.size();
    int ans;
    for (int i = 0; i < matrix.size(); i++)
    {
        ans = max(maxi, recursion(0, i, n, matrix));
    }
    cout << ans << endl;
    return 0;
}