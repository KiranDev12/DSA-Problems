#include<bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string frequencySort(string s)
    {
        unordered_map<char, int> mpp;
        for (int i = 0; i < s.length(); i++)
        {
            mpp[s[i]]++;
        }
        vector<pair<int, char>> v;
        for (auto it : mpp)
        {
            v.push_back({it.second, it.first});
        }
        sort(v.begin(), v.end());
        s = "";
        for (int i = v.size() - 1; i >= 0; i--)
        {
            int count = v[i].first;
            char c = v[i].second;
            while (count > 0)
            {
                s += c;
                count--;
            }
        }
        return s;
    }
};