/*
    ?Title: Count the number of bits to be flipped to convert A to B

    * Approach:
    We XOR A and B to find the bits that are different.
    Then, we count the number of set bits in the result using Brian Kernighan's algorithm.

    -Time Complexity: O(log N), where N is the maximum of A and B
    -Space Complexity: O(1)
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:

    int countBitsFlip(int a, int b)
    {

        int x = a ^ b;
        int res = 0;
        while (x)
        {
            x = x & (x - 1);
            res++;
        }
        return res;
    }
};

int main()
{
    int t;
    cin >> t;   
    while (t--) 
    {
        int a, b;
        cin >> a >> b; 

        Solution ob;
        cout << ob.countBitsFlip(a, b) << endl;
    }
    return 0;
}
