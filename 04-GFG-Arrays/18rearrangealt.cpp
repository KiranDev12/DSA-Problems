//{ Driver Code Starts
// C++ program to rearrange an array in minimum
// maximum form
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    // This function wants you to modify the given input
    // array and no need to return anything
    // arr: input array
    // n: size of array
    // Function to rearrange  the array elements alternately.
    void rearrange(long long *A, int N)
    {
        int max_idx = N - 1, min_idx = 0;
        int max_elem = A[N - 1] + 1;
        for (int i = 0; i < N; i++)
        {
            if (i % 2 == 0)
            {
                A[i] += (A[max_idx] % max_elem) * max_elem;
                max_idx--;
            }
            else
            {
                A[i] += (A[min_idx] % max_elem) * max_elem;
                min_idx++;
            }
        }
        for (int i = 0; i < N; i++)
            A[i] = A[i] / max_elem;
    }
};

//{ Driver Code Starts.

// Driver program to test above function
int main()
{
    int t;

    // testcases
    cin >> t;

    while (t--)
    {

        // size of array
        int n;
        cin >> n;

        long long arr[n];

        // adding elements to the array
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }

        Solution ob;

        // calling rearrange() function
        ob.rearrange(arr, n);

        // printing the elements
        for (int i = 0; i < n; i++)
            cout << arr[i] << " ";

        cout << endl;
    }
    return 0;
}

// } Driver Code Ends