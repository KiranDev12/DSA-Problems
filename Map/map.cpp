#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    cin >> s;
    
    // map<char, int> mpp; (Better to use unordered map as it is in O(1) time complexity)
    unordered_map<char, int> mpp; //order cant be known
    for (int i = 0; i < s.size(); i++)
    {
        mpp[s[i]]+=1;
    }
    
    int q;
    cin >> q;
    while (q--)
    {
        char c;
        cin >> c;
        cout << mpp[c] << endl;
    }
}