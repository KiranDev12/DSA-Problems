/*
 * @lc app=leetcode id=915 lang=cpp
 *
 * [915] Partition Array into Disjoint Intervals
 */

// @lc code=start
class Solution
{
public:
    int partitionDisjoint(vector<int> &nums)
    {
        int maxLeft = nums[0];
        int max = nums[0];
        int p = 0;
        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i] < maxLeft)
            {
                maxLeft = max;
                p = i;
            }
            else if (max < nums[i])
            {
                max = nums[i];
            }
        }
        return p + 1;
    }
};
// @lc code=end
