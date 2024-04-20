class Solution
{
public:
    bool dfs(int i, vector<int> &visited, vector<int> &pathVis, vector<vector<int>> &graph, vector<int> &safe)
    {
        visited[i] = 1;
        pathVis[i] = 1;
        for (auto x : graph[i])
        {
            if (!visited[x])
            {
                if (dfs(x, visited, pathVis, graph, safe) == true)
                {
                    safe[i] = 0;
                    return true;
                }
            }
            if (pathVis[x] == 1)
            {
                safe[i] = 0;
                return true;
            }
        }
        safe[i] = 1;
        pathVis[i] = 0;
        return false;
    }

    vector<int> eventualSafeNodes(vector<vector<int>> &graph)
    {
        int v = graph.size();
        vector<int> visited(v, 0);
        vector<int> pathVis(v, 0);
        vector<int> safe(v, 0);
        vector<int> ans;
        for (int i = 0; i < v; i++)
        {
            if (!visited[i])
                dfs(i, visited, pathVis, graph, safe);
        }
        for (int i = 0; i < v; i++)
        {
            if (safe[i] == 1)
                ans.push_back(i);
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