#pragma GCC optimize("O3", "unroll-loops")
class Solution
{
public:
    void dfs(int row, int col, vector<vector<int>> &land, int &xmax, int &ymax)
    {
        int m = land.size(), n = land[0].size();
        land[row][col] = 0;
        xmax = max(xmax, row);
        ymax = max(ymax, col);
        vector<int> delx = {0, 1, 0, -1};
        vector<int> dely = {1, 0, -1, 0};
        for (int i = 0; i < 4; i++)
        {
            int newr = row + delx[i];
            int newc = col + dely[i];
            if (newr >= 0 && newc >= 0 && newr < m && newc < n && land[newr][newc] == 1)
            {
                dfs(newr, newc, land, xmax, ymax);
            }
        }
    }

    vector<vector<int>> findFarmland(vector<vector<int>> &land)
    {
        vector<vector<int>> ans;
        for (int i = 0; i < land.size(); i++)
        {
            for (int j = 0; j < land[0].size(); j++)
            {
                if (land[i][j] == 1)
                {
                    int xmax = INT_MIN, ymax = INT_MIN;
                    dfs(i, j, land, xmax, ymax);
                    ans.push_back({i, j, xmax, ymax});
                }
            }
        }
        return ans;
    }
};
auto init = []()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();