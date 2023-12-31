/*
 * @lc app=leetcode id=403 lang=cpp
 *
 * [403] Frog Jump
 */

// @lc code=start
class Solution {
public:
    bool canCross(vector<int>& stones) {
        int i = 0; j = 1, k = 1;
        while(i!=stones.size()){
            int diff = stones[j]-stones[i];
            if(diff == k || diff == k-1 || diff == k+1){
                j = i;
                k = diff;
                j = i+1;
            } else {
                j++;
                if(j==stones.size()) return false;
            }
        }
        return true;
    }
};
// @lc code=end

