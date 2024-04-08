class Solution
{
public:
    vector<vector<int>> updateMatrix(vector<vector<int>> &mat)
    {
        int m = mat.size(), n = mat[0].size();
        vector<vector<int>> vis(m, vector<int>(n, 0));
        vector<vector<int>> dist(m, vector<int>(n, 0));
        queue<pair<pair<int, int>, int>> q;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (mat[i][j] == 0)
                {
                    q.push({{i, j}, 0});
                    vis[i][j] = 1;
                }
            }
        }
        vector<int> delrow = {-1, 0, 1, 0};
        vector<int> delcol = {0, -1, 0, 1};
        while (!q.empty())
        {
            int r = q.front().first.first;
            int c = q.front().first.second;
            int steps = q.front().second;
            q.pop();
            dist[r][c] = steps;
            for (int i = 0; i < 4; i++)
            {
                int newr = r + delrow[i];
                int newc = c + delcol[i];
                if (newr >= 0 && newc >= 0 && newr < m && newc < n && vis[newr][newc] != 1)
                {
                    vis[newr][newc] = 1;
                    q.push({{newr, newc}, steps + 1});
                }
            }
        }
        return dist;
    }
};

auto init = []()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();