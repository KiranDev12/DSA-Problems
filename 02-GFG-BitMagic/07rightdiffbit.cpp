//? Question:
//? Given two integers m and n, write a C++ program to find the position of the rightmost different bit in their binary representation.

//* Difficulty: Easy
//- Rightmost diff bit of 2 numbers will be the rightmost bit of their XOR and to get the position log2(k)+1
#include <bits/stdc++.h>
using namespace std;

// User function
class Solution {
public:
    int posOfRightMostDiffBit(int m, int n) {
        if (m == n)
            return -1;
        int x = m ^ n;
        int k = x & (~(x - 1));
        return log2(k) + 1; // Returning the position of the rightmost set bit
    }
};

// Driver code
int main() {
    int t;
    cin >> t; // Input number of testcases
    while (t--) {
        int m, n;
        cin >> m >> n; // Input m and n
        Solution ob;
        cout << ob.posOfRightMostDiffBit(m, n) << endl; // Output the position of the rightmost different bit
    }
    return 0;
}
