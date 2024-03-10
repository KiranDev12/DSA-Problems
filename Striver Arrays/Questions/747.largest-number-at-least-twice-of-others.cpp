/*
 * @lc app=leetcode id=747 lang=cpp
 *
 * [747] Largest Number At Least Twice of Others
 */

// @lc code=start
class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        int maxPos = 0;
        for(int i = 1; i<nums.size(); i++){
            if(nums[maxPos]<nums[i]) {
                maxPos = i;
            }
        }
        for(int i = 0; i<nums.size(); i++){
            if(maxPos == i) continue;
            if(nums[i]*2>nums[maxPos]) return -1;
        }
        return maxPos;
    }
};
// @lc code=end

