//{ Driver Code Starts
#include <iostream>
#include <map>
#include <algorithm>
#include <cstdlib>
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
class Solution
{
public:
    // Function to return the name of candidate that received maximum votes.
    vector<string> winner(string arr[], int n)
    {
        map<string, int> m;
        for (int i = 0; i < n; i++)
        {
            m[arr[i]]++;
        }
        int vote = INT_MIN;
        vector<string> vec(2);
        string ans = "";
        for (auto it = m.begin(); it != m.end(); it++)
        {
            if (it->second > vote)
            {
                vote = it->second;
                ans = it->first;
                vec[0] = ans;
                vec[1] = to_string(vote);
            }
        }
        return vec;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;

    for (int i = 0; i < t; i++)
    {

        int n;
        cin >> n;

        string arr[n];

        for (int i = 0; i < n; i++)
            cin >> arr[i];
        Solution obj;
        vector<string> result = obj.winner(arr, n);

        cout << result[0] << " " << result[1] << endl;
    }
    return 0;
}

// } Driver Code Ends