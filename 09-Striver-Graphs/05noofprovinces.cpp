class Solution
{
public:
    void dfs(int i, vector<vector<int>> &isConnected, vector<bool> &visited)
    {
        visited[i] = true;
        for (int j = 0; j < isConnected[i].size(); j++)
        {
            if (isConnected[i][j] == 1 && !visited[j])
            {
                dfs(j, isConnected, visited);
            }
        }
    }
    int findCircleNum(vector<vector<int>> &isConnected)
    {
        vector<bool> visited(isConnected.size());
        int cnt = 0;
        for (int i = 0; i < isConnected.size(); i++)
        {
            if (!visited[i])
            {
                cnt++;
                dfs(i, isConnected, visited);
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