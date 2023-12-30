/*
 * @lc app=leetcode id=1221 lang=cpp
 *
 * [1221] Split a String in Balanced Strings
 */

// @lc code=start
class Solution
{
public:
    int balancedStringSplit(string s)
    {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        int cnt = 0, ans = 0;
        for (int i = 0; i < size(s); i++)
        {
            if (s[i] == 'R')
                cnt++;
            else
                cnt--;
            if (cnt == 0)
                ans++;
        }
        return ans;
    }
};
// @lc code=end
