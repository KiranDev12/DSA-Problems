class Solution
{
public:
    bool isBipartite(vector<vector<int>> &graph)
    {
        vector<int> color(graph.size(), -1);
        // adj list already diya hua h
        queue<int> q;
        q.push(0);
        for (int start = 0; start < graph.size(); ++start)
        {
            if (color[start] == -1)
            {
                q.push(start);
                color[start] = 0;
                while (!q.empty())
                {
                    int curr = q.front();
                    q.pop();
                    for (int i = 0; i < graph[curr].size(); ++i)
                    {
                        int child = graph[curr][i];
                        if (color[child] == -1)
                        {
                            color[child] = 1 - color[curr];
                            q.push(child);
                        }
                        else if (color[child] == color[curr])
                        {
                            return false;
                        }
                    }
                }
            }
        }
        return true;
    }
};

auto init = []()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();