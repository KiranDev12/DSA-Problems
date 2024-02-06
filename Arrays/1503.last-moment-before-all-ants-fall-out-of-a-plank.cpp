/*
 * @lc app=leetcode id=1503 lang=cpp
 *
 * [1503] Last Moment Before All Ants Fall Out of a Plank
 */

// @lc code=start
class Solution
{
public:
    int getLastMoment(int n, vector<int> &left, vector<int> &right)
    {
        int maxLeft = -1, minRight = n + 1;
        for (int i = 0; i < left.size(); i++)
            maxLeft = max(maxLeft, left[i]);
        for (int i = 0; i < right.size(); i++)
            minRight = min(minRight, right[i]);
        int t1 = maxLeft - 0;
        int t2 = n - minRight;
        return max(t1, t2);
    }
};
// @lc code=end
