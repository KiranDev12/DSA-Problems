/*
?Question: Find the position of first set bit in a number
*Difficulty: Easy
*/
//- Keep running a loop that checks n&2^(i-1) if its 1 then return i as the set bit

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    unsigned int getFirstSetBit(int n)
    {
        // if(n==0) return 0;
        for (int i = 1; i < n; i++)
        {
            if (n & (1 << (i - 1)))
            {
                return i;
            }
        }
        return 0;
    }
};

//{ Driver Code Starts.

// Driver code
int main()
{
    int t;
    cin >> t; // testcases
    while (t--)
    {
        int n;
        cin >> n; // input n
        Solution ob;
        printf("%u\n", ob.getFirstSetBit(n));
    }
    return 0;
}

// } Driver Code Ends