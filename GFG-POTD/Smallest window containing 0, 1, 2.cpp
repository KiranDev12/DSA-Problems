//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    int smallestSubstring(string S)
    {
        int zero = -1;
        int one = -1;
        int two = -1;

        int len = INT_MAX;
        for (int i = 0; i < S.length(); i++)
        {
            if (S[i] == '0')
                zero = i;
            else if (S[i] == '1')
                one = i;
            else
                two = i;

            if (zero != -1 and one != -1 and two != -1)
            {
                int s = min({zero, one, two});
                int e = max({zero, one, two});

                len = min(len, e - s + 1);
            }
        }
        return len >= INT_MAX ? -1 : len;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string S;
        cin >> S;
        Solution ob;
        cout << ob.smallestSubstring(S);
        cout << endl;
    }
}
// } Driver Code Ends