/// @brief You can use O(1) space by marking visited nodes as 2 in the process
class Solution
{
public:
    void dfs(int i, int j, vector<vector<char>> &grid, vector<vector<bool>> &visited)
    {
        if (i < 0 || i == grid.size() || j < 0 || j == grid[0].size() || visited[i][j] == true)
            return;
        if (grid[i][j] == '0')
            return;
        visited[i][j] = true;
        dfs(i + 1, j, grid, visited);
        dfs(i - 1, j, grid, visited);
        dfs(i, j + 1, grid, visited);
        dfs(i, j - 1, grid, visited);
    }
    int numIslands(vector<vector<char>> &grid)
    {
        int i = 0, j = 0, cnt = 0;
        vector<vector<bool>> visited(grid.size(), vector<bool>(grid[0].size(), false));
        for (i = 0; i < grid.size(); i++)
        {
            for (j = 0; j < grid[i].size(); j++)
            {
                if (grid[i][j] == '1' && visited[i][j] != true)
                {
                    dfs(i, j, grid, visited);
                    cnt++;
                }
            }
        }
        return cnt;
    }
};

auto init = []()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();