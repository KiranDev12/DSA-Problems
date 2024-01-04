#include<bits/stdc++.h>
using namespace std;

int maxConsecutiveOnes(int N)
{
    bitset<32> b(N);
    int maxi = 0;
    int cnt = 0;
    for (int i = 0; i < 32; i++)
    {

        if (b[i] == 1)
        {
            cnt++;
            maxi = max(maxi, cnt);
        }
        else
        {
            cnt = 0;
        }
    }

    return maxi;
}

int main(){
    cout<<maxConsecutiveOnes(15)<<endl;
    return 0;
}