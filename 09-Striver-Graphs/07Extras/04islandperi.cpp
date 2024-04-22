class Solution
{
public:
    int islandPerimeter(vector<vector<int>> &grid)
    {
        int res = 0;
        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[0].size(); j++)
            {
                if (grid[i][j])
                {
                    res += 4;
                    if ((i + 1 < grid.size() && grid[i + 1][j]))
                        res--; // agar niche 1 h toh
                    if (j + 1 < grid[0].size() && grid[i][j + 1])
                        res--; // right pe 1 ho toh
                    if (i - 1 >= 0 && grid[i - 1][j])
                        res--; // upar 1 ho toh
                    if (j - 1 >= 0 && grid[i][j - 1])
                        res--; // left pe agar 1 ho toh
                }
            }
        }
        return res;
    }
};
auto init = []()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();