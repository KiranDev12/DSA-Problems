//{ Driver Code Starts
// Initial Template for C++

#include <iostream>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    // Complete this function
    int RecursivePower(int x, int n)
    {
        if (n == 0)
            return 1;
        long long half_power = RecursivePower(x, n / 2);
        if (n % 2 == 0)
            return (half_power * half_power);
        else
            return (x * half_power * half_power);
    }
};

//{ Driver Code Starts.

int main()
{
    int T;
    cin >> T; // testcases
    while (T--)
    {
        int n, p;

        // taking n and p as inputs
        cin >> n >> p;

        // calling RecursivePower() function
        Solution obj;
        cout << obj.RecursivePower(n, p) << endl;
    }
    return 0;
}
// } Driver Code Ends