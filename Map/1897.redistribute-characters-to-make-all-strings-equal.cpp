/*
 * @lc app=leetcode id=1897 lang=cpp
 *
 * [1897] Redistribute Characters to Make All Strings Equal
 */

// @lc code=start
class Solution
{
public:
    bool makeEqual(vector<string> &words)
    {
        unordered_map<char, int> counts;
        for (auto a : words)
        {
            for (char x : a)
            {
                counts[x]++;
            }
        }

        int n = words.size();
        for (auto a : counts)
        {
            if (a.second % n != 0)
            {
                return false;
            }
        }

        return true;
    }
};
// @lc code=end
