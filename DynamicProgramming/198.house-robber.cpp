/*
 * @lc app=leetcode id=198 lang=cpp
 *
 * [198] House Robber
 */

// @lc code=start
class Solution
{
public:
    int rob(vector<int> &arr)
    {
        int curr = arr[0];
        int prev = 0;
        for (int i = 1; i < arr.size(); i++)
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
};
// @lc code=end
