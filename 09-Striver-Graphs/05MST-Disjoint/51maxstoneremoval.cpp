
class DisjointSet
{
public:
    vector<int> rank, parent, size;
    DisjointSet(int n)
    {
        rank.resize(n + 1, 0);
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
    int removeStones(vector<vector<int>> &stones)
    {
        int n = stones.size();
        int maxr = 0, maxc = 0;
        for (auto it : stones)
        {
            maxr = max(maxr, it[0]);
            maxc = max(maxc, it[1]);
        }
        DisjointSet nums(maxr + maxc + 2);
        maxr = maxr + 1;
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            int u = stones[i][0];
            int v = maxr + stones[i][1];
            int parentu = nums.findUPar(u);
            int parentv = nums.findUPar(v);
            if (parentu != parentv)
            {
                nums.unionBySize(u, v);
            }
            else
            {
                nums.parent[parentu] -= 1;
            }
        }
        for (int i = 0; i < maxr + maxc + 1; i++)
        {
            if (nums.parent[i] < -1)
            {
                ans = ans - (nums.parent[i]) - 2;
            }
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