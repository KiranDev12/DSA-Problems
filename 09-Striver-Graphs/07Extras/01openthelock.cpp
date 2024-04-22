class Solution
{
public:
    int openLock(vector<string> &deadends, string target)
    {
        unordered_set<string> st(deadends.begin(), deadends.end());
        if (st.find("0000") != st.end())
            return -1;
        unordered_set<string> visited1, visited2;
        queue<string> q1, q2;
        q1.push("0000");
        q2.push(target);
        visited1.insert("0000");
        visited2.insert(target);
        int cnt = 0;
        while (!q1.empty() && !q2.empty())
        {
            if (q1.size() > q2.size())
            {
                swap(q1, q2);
                swap(visited1, visited2);
            }
            int size = q1.size();
            for (int i = 0; i < size; ++i)
            {
                string current = q1.front();
                q1.pop();
                if (visited2.count(current))
                    return cnt;
                for (int j = 0; j < 4; ++j)
                {
                    string temp = current;
                    temp[j] = (temp[j] - '0' + 1) % 10 + '0';
                    if (st.find(temp) == st.end() && visited1.find(temp) == st.end())
                    {
                        q1.push(temp);
                        visited1.insert(temp);
                    }
                    temp = current;
                    temp[j] = (temp[j] - '0' + 9) % 10 + '0';
                    if (st.find(temp) == st.end() && visited1.find(temp) == st.end())
                    {
                        q1.push(temp);
                        visited1.insert(temp);
                    }
                    temp = current;
                }
            }
            ++cnt;
        }

        return -1;
    }
};

auto init = []()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();