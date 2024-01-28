class Solution
{
public:
    int recursion(int left, int ind, vector<int> &coins, vector<vector<int>> &dp)
    {
        if (dp[ind][left] != -1)
            return dp[ind][left];
        if (ind == 0)
        {
            if (left % coins[0] == 0)
            {
                return dp[ind][left] = left / coins[0];
            }
            else
            {
                return 1e9;
            }
        }
        int notTake = recursion(left, ind - 1, coins, dp);
        int take = 1e9;
        if (coins[ind] <= left)
        {
            take = 1 + recursion(left - coins[ind], ind, coins, dp);
        }
        return dp[ind][left] = min(take, notTake);
    }
    int tabulation(int left, int ind, vector<int> &coins, vector<vector<int>> &dp)
    {
        for (int i = 0; i < left; i++)
        {
            dp[0][left] = 1e9;
            if (left % coints[0] == 0)
                dp[0][left] = left / coins[0];
        }
        for (int i = 0; i < dp.size(); i++)
        {
            for (int j = 0; j < dp[0].size(); j++)
            {
                int notTake = dp[left, ind - 1];
                int take = 1e9;
                if (coins[ind] <= left)
                {
                    take = 1 + dp[left - coins[ind], ind - 1];
                }
                dp[ind][left] = min(take, notTake);
            }
        }
        return dp[left - 1][ind];
    }

    int optimal(vector<int> &coins, int amount)
    {
        vector<int> dp(amount + 1, amount + 1);
        dp[0] = 0;

        for (int i = 1; i <= amount; i++)
        {
            for (int j = 0; j < coins.size(); j++)
            {
                if (coins[j] <= i)
                {
                    dp[i] = min(dp[i], dp[i - coins[j]] + 1);
                }
            }
        }

        return dp[amount] > amount ? -1 : dp[amount];
    }

    int coinChange(vector<int> &coins, int amount)
    {
        vector<vector<int>> dp(coins.size() + 1, vector<int>(amount + 1, -1));
        int ans = recursion(amount, coins.size() - 1, coins, dp);
        if (ans >= 1e9)
            return -1;
        return ans;
    }
};