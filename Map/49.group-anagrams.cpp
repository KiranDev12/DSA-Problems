/*
 * @lc app=leetcode id=49 lang=cpp
 *
 * [49] Group Anagrams
 */

// @lc code=start
class Solution
{
public:
    vector<vector<string>> groupAnagrams(vector<string> &strs)
    {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        vector<vector<string>> ans;
        unordered_map<string, vector<string>> mpp;
        for (int i = 0; i < strs.size(); i++)
        {
            string x = strs[i];
            sort(strs[i].begin(), strs[i].end());
            mpp[strs[i]].push_back(x);
        }
        for (auto x : mpp)
            ans.push_back(x.second);
        return ans;
    }
};
// @lc code=end
