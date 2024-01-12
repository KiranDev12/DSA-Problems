#include <bits/stdc++.h>
using namespace std;

int recursion(int i, int j, int n, vector<vector<int>> &triangle)
{
    if (i == n - 1)
        return triangle[i][j];
    int down = triangle[i][j] + recursion(i + 1, j, n, triangle);
    int diagonal = triangle[i][j] + recursion(i + 1, j + 1, n, triangle);
    return min(down, diagonal);
}

int memory(int i, int j, int n, vector<vector<int>> &triangle, vector<vector<int>> &dp)
{
    if (i == n - 1)
        return triangle[i][j];
    if (dp[i][j] != -1)
        return dp[i][j];
    int down = triangle[i][j] + recursion(i + 1, j, n, triangle);
    int diagonal = triangle[i][j] + recursion(i + 1, j + 1, n, triangle);
    return dp[i][j] = min(down, diagonal);
}

int tablulation(vector<vector<int>> &triangle, vector<vector<int>> &dp, int n)
{
    for (int i = 0; i < n; i++)
    {
        dp[n - 1][i] = triangle[n - 1][i];
    }
    for (int i = n - 2; i >= 0; i--)
    {
        for (int j = i; j >= 0; j--)
        {
            int down = triangle[i][j] + dp[i + 1][j];
            int diagonal = triangle[i][j] + dp[i + 1][j + 1];
            dp[i][j] = min(down, diagonal);
        }
    }
    return dp[0][0];
}

int noExtraSpace(vector<vector<int>> &triangle)
{
    int n = triangle.size();
    for (int i = n - 1; i > 0; i--)
    {
        int m = triangle[i].size();
        for (int j = 0; j < m - 1; j++)
        {
            triangle[i - 1][j] += min(triangle[i][j], triangle[i][j + 1]);
        }
    }
    return triangle[0][0];
}

int spaceOpti(vector<vector<int>> &triangle, int n)
{
    vector<int> front(n, 0);
    vector<int> cur(n, 0);

    for (int j = 0; j < n; j++)
    {
        front[j] = triangle[n - 1][j];
    }
    for (int i = n - 2; i >= 0; i--)
    {
        for (int j = i; j >= 0; j--)
        {
            int down = triangle[i][j] + front[j];
            int diagonal = triangle[i][j] + front[j + 1];
            cur[j] = min(down, diagonal);
        }
        front = cur;
    }
    return front[0];    
}
int main()
{
    // Define the triangle as a 2D vector
    vector<vector<int>> triangle{{1},
                                 {2, 3},
                                 {3, 6, 7},
                                 {8, 9, 6, 10}};

    // Get the number of rows in the triangle
    int n = triangle.size();
    cout << recursion(0, 0, n, triangle) << endl;
    vector<vector<int>> dp(n, vector<int>(n, -1));
    cout << memory(0, 0, n, triangle, dp) << endl;
    vector<vector<int>> dp1(n, vector<int>(n, -1));
    cout << tablulation(triangle, dp1, n) << endl;
    cout << spaceOpti(triangle, n) << endl;
    return 0;
}
