/*
 * @lc app=leetcode id=583 lang=cpp
 *
 * [583] Delete Operation for Two Strings
 */

// @lc code=start
class Solution
{
public:
    int minDistance(string word1, string word2)
    {
        unordered_map<char, int> mpp;
        int max;
        if (word1.length() > word2.length())
            max = 1;
        else
            max = 2;
        if (max == 1)
        {
            for (int i = 0; i < word1.length(); i++)
            {
                mpp[word1[i]]++;
                mpp[word2[i]]--;
            }
        } else {
            for (int i = 0; i < word2.length(); i++)
            {
                mpp[word2[i]]++;
                mpp[word1[i]]--;
            }
        }
        int cnt = 0;
        for (int i = 0; i < mpp.size(); i++)
        {
            cnt+=mpp[i];
        }
        return word1.length()+word2.length()-cnt;
    }
}; // @lc code=end
