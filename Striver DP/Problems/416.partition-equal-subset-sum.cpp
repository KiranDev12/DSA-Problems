/*
 * @lc app=leetcode id=416 lang=cpp
 *
 * [416] Partition Equal Subset Sum
 */

// @lc code=start
class Solution
{
public:
    bool canPartition(vector<int> &nums)
    {
        if(nums.size()%2!=0) return false;
        int k = nums.size()/2;
        int ind = nums.size();
        vector<bool> prev(k + 1, 0), curr(k + 1, 0);
        prev[0] = curr[0] = true;
        prev[nums[0]] = true;
        for (int index = 1; index < ind; index++)
        {
            for (int target = 1; target <= k; target++)
            {
                bool notTake = prev[target];
                bool take = false;
                if (nums[index] >= target)
                {
                    take = prev[target - nums[index]];
                }
                curr[target] = notTake | take;
            }
            prev = curr;
        }
        return prev[k];
    }
};
// @lc code=end
