#include <bits/stdc++.h>
using namespace std;

int brute(int arr[], int n) // O(N^2) & O(1)
{
    for (int i = 1; i <= n; i++)
    {
        int flag = 0;
        for (int j = 0; j < n-1; j++)
        {
            if (arr[j]==i)
            {
                flag=1;
                break;
            }
        }   
        if (flag == 0)
        {
            return i;
        }
    }
    return -1;  
}

int better(int a[], int n) // O(N) & o(N)
{
    int hash[n+1] = {0};
    for (int i = 0; i < n; i++)
    {
        hash[a[i]]=1;
    }

    for (int i = 1; i < n; i++)
    {
        if (hash[i]==0)
        {
            return i;
        }
    }
    return -1;
}


//! TWO OPTIMAL APPROACHES - 1) SUM 2) XOR
int optimal(int a[], int n){
    int sum  = 0;
    for (int i = 0; i < n; i++)
    {
        sum+=a[i];
    }
    int actual = n*(n+1)/2;
    return actual - sum;
}

int XOR(int a[], int n){
    int XOR1 = 0, XOR2  = 0;
    for (int i = 0; i < n; i++)
    {
        XOR1 = XOR1 ^ a[i];
        XOR2 = XOR2 ^ (i+1);
    }
    return XOR1^XOR2;
}
int main()
{
    int a[5] = {1, 2, 3, 5};

    cout<<brute(a, 5)<<endl;
    cout<<better(a, 5)<<endl;
    cout<<optimal(a, 5)<<endl;
    cout<<XOR(a, 5)<<endl;

}