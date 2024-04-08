class Solution
{
private:
    void dfs(int row, int col, vector<vector<int>> &vis, vector<vector<char>> &mat, int delrow[], int delcol[])
    {
        vis[row][col] = 1;
        int n = mat.size();
        int m = mat[0].size();
        for (int i = 0; i < 4; i++)
        {
            int nrow = row + delrow[i];
            int ncol = col + delcol[i];
            if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m &&
                !vis[nrow][ncol] && mat[nrow][ncol] == 'O')
            {
                dfs(nrow, ncol, vis, mat, delrow, delcol);
            }
        }
    }

public:
    vector<vector<char>> solve(int n, int m, vector<vector<char>> mat)
    {
        int delrow[] = {-1, 0, +1, 0};
        int delcol[] = {0, 1, 0, -1};
        vector<vector<int>> vis(n, vector<int>(m, 0));
        for (int j = 0; j < m; j++)
        {
            // first row ke saare elements pe dfs karta h
            if (!vis[0][j] && mat[0][j] == 'O')
            {
                dfs(0, j, vis, mat, delrow, delcol);
            }
            // last row ke saare elements pe dfs karta h
            if (!vis[n - 1][j] && mat[n - 1][j] == 'O')
            {
                dfs(n - 1, j, vis, mat, delrow, delcol);
            }
        }

        for (int i = 0; i < n; i++)
        {
            // first column cover karta h
            if (!vis[i][0] && mat[i][0] == 'O')
            {
                dfs(i, 0, vis, mat, delrow, delcol);
            }
            // last column cover karta h
            if (!vis[i][m - 1] && mat[i][m - 1] == 'O')
            {
                dfs(i, m - 1, vis, mat, delrow, delcol);
            }
        }
        // if there still exists 0's that are not visited then usse X se replace kardo
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (!vis[i][j] && mat[i][j] == 'O')
                    mat[i][j] = 'X';
            }
        }

        return mat;
    }
};
auto init = []()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();