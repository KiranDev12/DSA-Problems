/*
 * @lc app=leetcode id=1684 lang=cpp
 *
 * [1684] Count the Number of Consistent Strings
 */

// @lc code=start
class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        vector<bool> allowedMask(26, false);
        for (const char ch: allowed) {
            allowedMask[ch - 'a'] = true;
        }
        int count = 0;
        for (const auto& word:words){
            int flag = true;
            for (char letter:word){
                if (!allowedMask[letter - 'a']){
                    flag = false;
                    break;
                }
            }
            if (flag) count++;
        }
        return count;

    }
};
// @lc code=end

