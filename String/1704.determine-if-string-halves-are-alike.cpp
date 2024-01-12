/*
 * @lc app=leetcode id=1704 lang=cpp
 *
 * [1704] Determine if String Halves Are Alike
 */

// @lc code=start
class Solution {
public:
    bool halvesAreAlike(string s) {
        for(int i = 0; i<size(s); i++){
            s[i] = tolower(s[i]);
        }
        int cnt1=0, cnt2=0;
        for(int i = 0; i<size(s); i++){
            char x = s[i];
            if(i<size(s)/2){
                if (x == 'a' || x == 'e' || x == 'i' || x == 'o'|| x == 'u')
                    cnt1++;
            } else {
                if (x == 'a' || x == 'e' || x == 'i' || x == 'o'|| x == 'u')
                    cnt2++;
            }
        }
        return (cnt1==cnt2);
    }
};
// @lc code=end

