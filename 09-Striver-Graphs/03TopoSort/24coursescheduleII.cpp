class Solution
{
public:
    vector<int> findOrder(int numCourses, vector<vector<int>> &prereq)
    {
        vector<int> indeg(numCourses, 0);
        for (int i = 0; i < prereq.size(); i++)
        {
            indeg[prereq[i][1]]++;
        }
        queue<int> q;
        for (int i = 0; i < numCourses; i++)
        {
            if (indeg[i] == 0)
            {
                q.push(i);
            }
        }
        vector<int> ans;
        while (!q.empty())
        {
            int node = q.front();
            q.pop();
            ans.push_back(node);
            for (int i = 0; i < prereq.size(); i++)
            {
                if (prereq[i][0] == node)
                {
                    indeg[prereq[i][1]]--;
                    if (indeg[prereq[i][1]] == 0)
                    {
                        q.push(prereq[i][1]);
                    }
                }
            }
        }
        reverse(ans.begin(), ans.end());
        if (ans.size() == numCourses)
            return ans;
        return {};
    }
};

auto init = []()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();