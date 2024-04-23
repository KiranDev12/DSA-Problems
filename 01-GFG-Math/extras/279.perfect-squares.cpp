/*
 * @lc app=leetcode id=279 lang=cpp
 *
 * [279] Perfect Squares
 */

// @lc code=start
class Solution
{
public:
    int numSquares(int n)
    {
        vector<int> dp(n + 1, n);
        dp[0] = 0;

        for (int i = 1; i <= n; ++i)
        {
            for (int s = 1; s <= i; ++s)
            {
                int square = s * s;
                if (i - square < 0)
                {
                    break;
                }
                if (1 + dp[i - square] < dp[i])
                {
                    dp[i] = 1 + dp[i - square];
                }
            }
        }

        return dp[n];
    }
};
// @lc code=end
