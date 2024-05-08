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
    vector<vector<string>> accountsMerge(vector<vector<string>> &accounts)
    {
        int size = accounts.size();
        DisjointSet ds(size);
        unordered_map<string, int> mpp;
        for (int i = 0; i < size; i++)
        {
            for (int j = 1; j < accounts[i].size(); j++)
            {
                string account = accounts[i][j];
                if (mpp.find(account) != mpp.end())
                {
                    ds.unionBySize(i, mpp[account]);
                }
                else
                {
                    mpp[account] = i;
                }
            }
        }
        vector<string> merged[size];
        for (auto it : mpp)
        {
            string temp = it.first;
            int node = ds.findUPar(it.second);
            merged[node].push_back(temp);
        }

        vector<vector<string>> ans;

        for (int i = 0; i < size; i++)
        {
            if (merged[i].size() == 0)
                continue;
            sort(merged[i].begin(), merged[i].end());
            vector<string> temp;
            temp.push_back(accounts[i][0]);
            for (auto it : merged[i])
            {
                temp.push_back(it);
            }
            ans.push_back(temp);
        }
        sort(ans.begin(), ans.end());
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