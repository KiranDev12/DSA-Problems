#include <bits/stdc++.h>
using namespace std;

int recursion(int day, int last, vector<vector<int>> &points)
{
    int maxi = INT_MIN;
    if (day == 0)
    {
        for (int i = 0; i < 3; i++)
        {
            maxi = max(maxi, points[0][i]);
        }
        return maxi;
    }

    for (int i = 0; i < 3; i++)
    {
        if (last != i)
        {
            int activity = points[day][i] + recursion(day - 1, i, points);
            maxi = max(maxi, activity);
        }
    }
    return maxi;
}

int memory(int day, int last, vector<vector<int>> &points, vector<vector<int>> &dp)
{
    int maxi = INT_MIN;
    if (dp[day][last] != -1)
        return dp[day][last];
    if (day == 0)
    {
        for (int i = 0; i < 3; i++)
        {
            maxi = max(maxi, points[0][i]);
        }
        return maxi;
    }

    for (int i = 0; i < 3; i++)
    {
        if (last != i)
        {
            int activity = points[day][i] + recursion(day - 1, i, points);
            maxi = max(maxi, activity);
        }
    }
    return dp[day][last] = maxi;
}
int tabulation(int n, vector<vector<int>> &points)
{
    vector<vector<int>> dp(n, vector<int>(4, 0));

    dp[0][0] = max(points[0][1], points[0][2]);
    dp[0][1] = max(points[0][0], points[0][2]);
    dp[0][2] = max(points[0][0], points[0][1]);
    dp[0][3] = max(points[0][0], max(points[0][1], points[0][2]));

    for (int day = 1; day < n; day++)
    {
        for (int last = 0; last < 4; last++)
        {
            dp[day][last] = 0;
            for (int task = 0; task <= 2; task++)
            {
                if (task != last)
                {
                    int activity = points[day][task] + dp[day - 1][task];
                    dp[day][last] = max(dp[day][last], activity);
                }
            }
        }
    }

    return dp[n - 1][3];
}
int ninjaTraining(int n, vector<vector<int>> &points)
{
    vector<int> prev(4, 0);
    prev[0] = max(points[0][1], points[0][2]);
    prev[1] = max(points[0][0], points[0][2]);
    prev[2] = max(points[0][0], points[0][1]);
    prev[3] = max(points[0][0], max(points[0][1], points[0][2]));

    for (int day = 1; day < n; day++)
    {
        vector<int> temp(4, 0);
        for (int last = 0; last < 4; last++)
        {
            temp[last] = 0;
            for (int task = 0; task <= 2; task++)
            {
                if (task != last)
                {
                    temp[last] = max(temp[last], points[day][task] + prev[task]);
                }
            }
        }
        prev = temp;
    }

    return prev[3];
}
int main()
{
    vector<vector<int>> points = {{10, 40, 70},
                                  {20, 50, 80},
                                  {30, 60, 90}};

    int n = points.size();
    cout << recursion(n - 1, 3, points) << endl;
    vector<vector<int>> dp(n, vector<int>(4, -1));
    cout << memory(n - 1, 3, points, dp) << endl;
    cout << tabulation(n, points) << endl;
    cout << ninjaTraining(n, points) << endl;
}