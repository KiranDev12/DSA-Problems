/*
 * @lc app=leetcode id=1413 lang=cpp
 *
 * [1413] Minimum Value to Get Positive Step by Step Sum
 */

// @lc code=start
class Solution {
public:
    int minStartValue(vector<int>& nums) {
        int mini = INT_MAX;
        for (int i = 0; i < nums.size(); i++)
        {
            sum+=nums[i];
            mini = min(mini, sum);
        }
        if(mini>=1) return 1;
        return -mini+1;
    }
};
// @lc code=end

