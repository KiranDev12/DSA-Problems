#include <bits/stdc++.h>
using namespace std;
int xor1(int a[], int N)
{
    int xor1 = 0;
    for (int i = 0; i < N; i++)
    {
        xor1 = xor1 ^ a[i];
    }
    return xor1;
}
int main()
{
    int a[5] = {1,1,2,3,3};
    cout<<xor1(a, 5)<<endl;
    return 0;
}