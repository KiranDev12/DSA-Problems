/*
?Power of two
*Easy
*/

//- n&(n-1) makes last set bit 0 and hence the whole number will be zero if it is a power of 2
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    // Function to check if given number n is a power of two.
    bool isPowerofTwo(long long n)
    {

        if (n == 0)
            return false;
        return ((n & (n - 1)) == 0);
    }
};
int main()
{

    int t;
    cin >> t; // testcases

    for (int i = 0; i < t; i++)
    {
        long long n; // input a number n
        cin >> n;

        Solution ob;
        if (ob.isPowerofTwo(n)) // Now, if log2 produces an integer not decimal then we are sure raising 2 to this value
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }

    return 0;
}

// } Driver Code Ends