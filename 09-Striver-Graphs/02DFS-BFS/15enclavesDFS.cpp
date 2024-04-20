/// @brief  Beats almost 100% on time
class Solution {
public:
    
    void dfs(int r, int c, vector<vector<int>>& grid, vector<vector<int>>& vis) {
        int delrow[] = {-1, 0, +1, 0};
        int delcol[] = {0, 1, 0, -1};
        vis[r][c] = 1;
        int n = grid.size();
        int m = grid[0].size();
        for(int i = 0; i<4; i++) {
            int newr = r + delrow[i];
            int newc = c + delcol[i];
            if(newr>=0 && newc>=0 && newr<n && newc<m && !vis[newr][newc] && grid[newr][newc]==1) {
                dfs(newr, newc, grid, vis);
            }
        }
    }
    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));

        for(int j = 0; j < m; j++) {
            if(!vis[0][j] && grid[0][j] == 1) {
                dfs(0, j, grid, vis);
            }
            if(!vis[n-1][j] && grid[n-1][j] == 1) {
                dfs(n-1, j, grid, vis);
            }
        }

        for(int i = 0; i<n; i++) {
            if(!vis[i][0] && grid[i][0]==1) {
                dfs(i, 0, grid, vis);
            }
            if(!vis[i][m-1] && grid[i][m-1]==1) {
                dfs(i, m-1, grid, vis);
            }
        }
        int cnt = 0;
        for(int i = 1; i<n-1; i++) {
            for(int j = 1; j<m-1; j++) {
                if(!vis[i][j] && grid[i][j] == 1) {
                    cnt++;
                }
            }
        }
        return cnt;
    }
};
auto init = []() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();