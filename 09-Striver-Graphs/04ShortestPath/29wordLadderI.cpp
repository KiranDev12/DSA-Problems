class Solution
{
public:
    
    //! BRUTE FORCE 
    int ladderLength(string beginWord, string endWord, vector<string> &wordList)
    {
        queue<pair<string, int>> q;
        set<string> search(wordList.begin(), wordList.end());
        set<string> visited;
        int level = 1;
        q.push({beginWord, level});
        visited.insert(beginWord);

        while (!q.empty())
        {
            string curr = q.front().first;
            int currLevel = q.front().second;
            q.pop();
            for (int i = 0; i < curr.size(); i++)
            {
                for (int j = 0; j < 26; j++)
                {
                    string temp = curr;
                    temp[i] = 'a' + j;

                    if (search.find(temp) != search.end() && visited.find(temp) == visited.end())
                    {
                        q.push({temp, currLevel + 1});
                        visited.insert(temp);

                        if (temp == endWord)
                            return currLevel + 1;
                    }
                }
            }
        }
        return 0;
    }
};
/// @brief STRIVER SOLUTION
class Solution {
public:
    int ladderLength(string startWord, string targetWord, vector<string>& wordList) {

        queue<pair<string, int>> q;
        q.push({startWord, 1});
        unordered_set<string> st(wordList.begin(), wordList.end());
        st.erase(startWord);
        while (!q.empty())
        {
            string word = q.front().first;
            int steps = q.front().second;
            q.pop();
            if (word == targetWord)
                return steps;

            for (int i = 0; i < word.size(); i++)
            {
                char original = word[i];
                for (char ch = 'a'; ch <= 'z'; ch++)
                {
                    word[i] = ch;
                    if (st.find(word) != st.end())
                    {
                        st.erase(word);
                        q.push({word, steps + 1});
                    }
                }
                word[i] = original;
            }
        }
        return 0;

    }
};

auto init = []() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();

auto init = []()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();
