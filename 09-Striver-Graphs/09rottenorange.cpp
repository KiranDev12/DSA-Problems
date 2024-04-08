class Solution
{
public:
    int orangesRotting(vector<vector<int>> &grid)
    {
        int m = grid.size(), n = grid[0].size();
        queue<pair<pair<int, int>, int>> q;
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        int fresh = 0;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == 2)
                {
                    q.push({{i, j}, 0});
                    visited[i][j] = true;
                }
                if (grid[i][j] == 1)
                    fresh++;
            }
        }
        int res = 0;
        vector<int> delrow = {0, -1, 0, +1};
        vector<int> delcol = {-1, 0, +1, 0};
        while (!q.empty())
        {
            int row = q.front().first.first;
            int col = q.front().first.second;
            int t = q.front().second;
            res = max(res, t);
            q.pop();
            for (int i = 0; i < 4; i++)
            {
                int newRow = row + delrow[i];
                int newCol = col + delcol[i];
                if (newRow >= 0 && newRow < m && newCol >= 0 && newCol < n && grid[newRow][newCol] == 1 && visited[newRow][newCol] == false)
                {
                    q.push({{newRow, newCol}, t + 1});
                    visited[newRow][newCol] = true;
                    fresh--;
                }
            }
        }
        if (fresh == 0)
            return res;
        return -1;
    }
};

auto init = []()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();