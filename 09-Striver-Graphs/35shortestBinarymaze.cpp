class Solution
{
public:
    int shortestPathBinaryMatrix(vector<vector<int>> &grid)
    {
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<pair<int, int>, int>> q;
        vector<vector<int>> visited(n, vector<int>(m, 0));
        int dx[] = {-1, -1, -1, 0, 1, 1, 1, 0};
        int dy[] = {-1, 0, 1, 1, 1, 0, -1, -1};
        if (grid[0][0] == 0)
        {
            q.push({{0, 0}, 1});
            visited[0][0] = 1;

            while (!q.empty())
            {
                int r = q.front().first.first;
                int c = q.front().first.second;
                int steps = q.front().second;
                if (r == n - 1 and c == m - 1)
                {
                    return steps;
                }
                q.pop();
                for (int i = 0; i < 8; i++)
                {
                    int newr = r + dx[i];
                    int newc = c + dy[i];

                    if (newr >= 0 and newr < n and newc >= 0 and newc < m and
                        grid[newr][newc] == 0 and visited[newr][newc] == 0)
                    {
                        q.push({{newr, newc}, steps + 1});
                        visited[newr][newc] = 1;
                    }
                }
            }
        }
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