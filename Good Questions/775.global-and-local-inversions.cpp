/*
 * @lc app=leetcode id=775 lang=cpp
 *
 * [775] Global and Local Inversions
 */

// @lc code=start
class Solution {
public:
    bool isIdealPermutation(vector<int>& nums) {
        // BRUTE EASY ...
        // THis is optimized solution
        for (int i = 0; i < nums.size(); ++i) {
            if (abs(nums[i] - i) > 1) {
                return false;
            }
        }
        return true;
    }
};
// @lc code=end

