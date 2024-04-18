/*
    ?Title: Swap Odd and Even Bits
    *Difficulty: Medium

    *Approach:
    We use bit manipulation to swap odd and even bits.
    We first extract even and odd bits using bitwise AND with masks.
    Then we shift even bits right and odd bits left, and finally combine them using bitwise OR.

    -Time Complexity: O(1)
    -Space Complexity: O(1)
*/
#include <bits/stdc++.h>
using namespace std;

class Solution
{
    unsigned int swapBits(unsigned int n)
    {
        unsigned int even_bits = n & 0xAAAAAAAA;
        unsigned int odd_bits = n & 0X55555555;
        even_bits >>= 1;
        odd_bits <<= 1;
        return even_bits | odd_bits;
    }
};
int main()
{
    int t;
    cin >> t; 
    while (t--)
    {
        unsigned int n;
        cin >> n; 

        Solution ob;
        // calling swapBits() method
        cout << ob.swapBits(n) << endl;
    }
    return 0;
}
// } Driver Code Ends