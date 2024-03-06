//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    // function to convert a given Gray equivalent n to Binary equivalent.
    int grayToBinary(int n)
    {

        // Your code here
        int binary = 0;
        while (n)
        {
            binary ^= n;
            n >>= 1;
        }
        return binary;
    }
    int binaryToGray(int n)
    {
        return n ^ (n >> 1);
    }
};

//{ Driver Code Starts.

// Driver code
int main()
{
    int t, n;
    cin >> t; // testcases
    while (t--)
    {
        cin >> n; // initializing n

        Solution ob;
        // calling function grayToBinary()
        cout << ob.grayToBinary(n) << endl;
    }
}

// } Driver Code Ends