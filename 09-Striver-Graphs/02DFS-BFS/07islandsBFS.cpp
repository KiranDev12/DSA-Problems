/// @brief DFS Soln had better time complexity than this
class Solution
{
public:
    vector<vector<int>> dirs = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    void bfs(int i, int j, vector<vector<char>> &grid, vector<vector<bool>> &visited)
    {
        visited[i][j] = true;
        queue<pair<int, int>> q;
        q.push({i, j});
        while (!q.empty())
        {
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            for (auto dir : dirs)
            {
                int a = row + dir[0];
                int b = col + dir[1];
                if (a >= 0 && a < grid.size() && b >= 0 && b < grid[0].size() && grid[a][b] == '1' && visited[a][b] == false)
                {
                    visited[a][b] = true;
                    q.push({a, b});
                }
            }
        }
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
                    bfs(i, j, grid, visited);
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