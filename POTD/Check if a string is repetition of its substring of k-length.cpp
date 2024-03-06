//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int kSubstrConcat(int n, string s, int k)
    {
        if (n % k != 0)
            return 0;
        unordered_set<string> x;
        for (int i = 0; i < n; i += k)
        {
            x.insert(s.substr(i, k));
            if (x.size() > 2)
                return 0;
        }
        return 1;
    }
};
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        string s;
        cin >> s;
        int k;
        cin >> k;
        Solution ob;
        cout << ob.kSubstrConcat(n, s, k) << endl;
    }
}