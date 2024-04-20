/// @brief Dont know why its horrible bad at time and excellent at memory on leetcode
class Solution
{
public:
    bool canFinish(int numCourses, vector<vector<int>> &prereq)
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
        int cnt = 0;
        while (!q.empty())
        {
            int node = q.front();
            q.pop();
            cnt++;
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
        if (cnt == numCourses)
            return true;
        return false;
    }
};
auto init = []()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();