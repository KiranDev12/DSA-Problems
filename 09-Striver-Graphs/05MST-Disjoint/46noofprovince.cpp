class DisjointSet
{
    vector<int> rank, parent, size;

public:
    DisjointSet(int n)
    {
        parent.resize(n + 1);
        size.resize(n + 1);
        for (int i = 0; i <= n; i++)
        {
            parent[i] = i;
            size[i] = 1;
        }
    }

    int findUPar(int node)
    {
        if (node == parent[node])
            return node;
        return parent[node] = findUPar(parent[node]);
    }

    void unionBySize(int u, int v)
    {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v)
            return;
        if (size[ulp_u] < size[ulp_v])
        {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else
        {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};
class Solution
{
public:
    int findCircleNum(vector<vector<int>> &isConnected)
    {
        int n = isConnected.size(), m = isConnected[0].size();
        DisjointSet ds(n);
        int cnt = 0;
        set<int> s;
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < m; j++)
            {
                if (isConnected[i][j] == 1)
                {
                    ds.unionBySize(i, j);
                }
            }
        }
        for (int i = 0; i < isConnected.size(); i++)
        {
            s.insert(ds.findUPar(i));
        }
        return s.size();
    }
};

auto init = []()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();