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