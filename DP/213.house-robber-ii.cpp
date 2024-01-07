/*
 * @lc app=leetcode id=213 lang=cpp
 *
 * [213] House Robber II
 */

// @lc code=start
class Solution
{
public:
    int space(vector<int> &nums, int start, int end)
    {
        int prevMax = 0;
        int currMax = 0;

        for (int i = start; i <= end; i++)
        {
            int temp = currMax;
            currMax = max(prevMax + nums[i], currMax);
            prevMax = temp;
        }

        return currMax;
    }

    int rob(vector<int> &nums)
    {
        if (nums.size() == 1)
        {
            return nums[0];
        }
        return max(space(nums, 0, nums.size() - 2), space(nums, 1, nums.size() - 1));
    }
};
// @lc code=end
