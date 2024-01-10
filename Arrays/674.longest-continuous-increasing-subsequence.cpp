/*
 * @lc app=leetcode id=674 lang=cpp
 *
 * [674] Longest Continuous Increasing Subsequence
 */

// @lc code=start
class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        int cnt=1;
        int maxi = 1;
        for (int i = 0; i < nums.size() - 1; i++)
        {
            if(nums[i]<nums[i+1]) cnt++;
            else{
                maxi = max(maxi,cnt);
                cnt = 1;
            } 
        }
        maxi = max(maxi,cnt);
        return maxi;
    }
};
// @lc code=end

