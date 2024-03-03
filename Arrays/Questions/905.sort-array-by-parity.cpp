/*
 * @lc app=leetcode id=905 lang=cpp
 *
 * [905] Sort Array By Parity
 */

// @lc code=start
class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int pos = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i]%2 == 0) {
                swap(nums[pos], nums[i]);
                pos++;
            }
        }
        return nums;
    }
};
// @lc code=end

