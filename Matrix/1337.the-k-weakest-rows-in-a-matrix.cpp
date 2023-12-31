/*
 * @lc app=leetcode id=1337 lang=cpp
 *
 * [1337] The K Weakest Rows in a Matrix
 */

// @lc code=start
class Solution
{
public:
    vector<int> kWeakestRows(vector<vector<int>> &mat, int k)
    {
        int n = mat[0].size();
        for (int i = 0; i < mat.size(); i++)
        {
            mat[i].push_back(i);
        }
        sort(mat.begin(), mat.end());
        vector<int> ans(k);
        for (int i = 0; i < k; i++)
        {
            ans[i] = mat[i][n];
        }
        return ans;
    }
};
// @lc code=end
