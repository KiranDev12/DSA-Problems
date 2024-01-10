// Optimal solution has a good logic

#include <bits/stdc++.h>
using namespace std;

int brute(vector<int> v)
{
    int n = v.size();

    for (int i = 0; i < n; i++)
    {
        int cnt = 0;
        for (int j = 0; j < n; j++)
        {
            if (v[j] == v[i])
            {
                cnt++;
            }
        }
        if (cnt > (n / 2))
            return v[i];
    }

    return -1;
}
int better(vector<int> v)
{
    int n = v.size();
    map<int, int> mpp;
    for (int i = 0; i < n; i++)
    {
        mpp[v[i]]++;
    }
    for (auto it : mpp)
    {
        if (it.second > (n / 2))
        {
            return it.first;
        }
    }

    return -1;
}
int optimal(vector<int> a)
{
    int ele, cnt = 0;
    int size=a.size();
    for (int i = 0; i < size; i++)
    {
        if (cnt == 0)
        {
            ele = a[i];
            cnt++;
        }
        else if (a[i] == ele)
        {
            cnt++;
        }
        else
        {
            cnt--;
        }
    }
    cnt = 0;
    for (int i = 0; i < size; i++)
    {
        if (a[i] == ele)
            cnt++;
    }
    if (cnt > size / 2)
        return ele;
    return -1;
}
int main()
{
    vector<int> arr = {2, 2, 1, 1, 1, 2, 2};
    int ans = brute(arr);
    ans = better(arr);
    ans = optimal(arr);
    cout << "The majority element is: " << ans << endl;
    return 0;
}
