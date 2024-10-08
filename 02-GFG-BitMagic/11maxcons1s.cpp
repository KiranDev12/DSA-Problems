    //{ Driver Code Starts
    // Initial Template for C++

    #include <bits/stdc++.h>
    using namespace std;

    // } Driver Code Ends
    // User function Template for C++

    /*  Function to calculate the longest consecutive ones
    *   N: given input to calculate the longest consecutive ones
    */
   
    class Solution
    {
    public:
        int maxConsecutiveOnes(int N)
        {
            int cnt = 0, max_cnt = -1;
            while (N != 0)
            {
                if (N % 2 == 1)
                {
                    cnt++;
                    max_cnt = max(cnt, max_cnt);
                }
                else
                {
                    cnt = 0;
                }
                N >>= 1;
            }
            return max_cnt;
        }
    };

    //{ Driver Code Starts.

    // Driver Code
    int main()
    {
        int t;
        cin >> t; // testcases
        while (t--)
        {
            int n;
            cin >> n; // input n
            Solution obj;
            // calling maxConsecutiveOnes() function
            cout << obj.maxConsecutiveOnes(n) << endl;
        }
        return 0;
    }
    // } Driver Code Ends