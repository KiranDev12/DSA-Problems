/*
 * @lc app=leetcode id=1624 lang=cpp
 *
 * [1624] Largest Substring Between Two Equal Characters
 */

// @lc code=start
class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        int len = 0; 
        int maxi = -1;
        for(int i = 0; i<s.size(); i++){
            len = 0;
            char c = s[i];
            for(int j = i+1; j<s.size(); j++){
                if(s[j]==c){
                    maxi = max(len, maxi);
                }
                len++;
            }
        }
        return maxi;
    }
};
// @lc code=end

