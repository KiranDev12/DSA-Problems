/*
?Question: Check if the k-th bit of a given number is set or not.
*Difficulty: Easy
/// Important is for the kth bit find 2^(k-1) and then just & with 1
-Intuition:
- For left shift: 
    - Left shift the number k-1 times.
    - Check if the k-th bit is set using bitwise AND with 1.
- For right shift:
    - Right shift the number k-1 times.
    - Check if the k-th bit is set using bitwise AND with 1.

*/
#include <bits/stdc++.h>
using namespace std;

void leftShift(int n, int k)
{
    if (n & (1 << (k - 1)))
        cout << "SET";
    else
        cout << "NOT SET";
}

void rightShift(int n, int k)
{
    if ((n >> (k - 1)) & 1)
        cout << "SET";
    else
        cout << "NOT SET";
}

// Driver code
int main()
{
    int n = 5, k = 1;

    // Function call
    isKthBitSet2(n, k);
    return 0;
}   