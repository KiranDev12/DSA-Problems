/* 
?Function to get no of set bits in binary representation of positive integer n 
*Easy
*/
#include <bits/stdc++.h>
using namespace std;
int preprocessed[256];
unsigned int brute(unsigned int n)
{
    unsigned int count = 0;
    while (n)
    {
        count += n & 1;
        n >>= 1;
    }
    return count;
}

// O(Number of set bits) - TC optimized
unsigned int better(int n)
{
    unsigned int count = 0;
    while (n)
    {
        n &= (n - 1);
        count++;
    }
    return count;
}

int main()
{
    int i = 9;
    preprocessed[0] = 0;
    for (int i = 1; i < 256; i++)
    {
        preprocessed[i] = preprocessed[i & (i - 1)] + 1;
    }
    int cnt = preprocessed[i & 255] + preprocessed[(i >> 8) & 255] + preprocessed[(i >> 16) & 255] + preprocessed[i >> 24];
    cout << cnt;
    return 0;
}