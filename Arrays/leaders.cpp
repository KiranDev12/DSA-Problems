#include <bits/stdc++.h>
using namespace std;

// to the right of that element all are smaller

// brute
vector<int> brute(int arr[])
{
    vector<int> ans;
    bool leader = true;
    for (int i = 0; i < 6; i++)
    {
        leader = true;
        for (int j = i + 1; j < 6; j++)
        {
            if (arr[i] < arr[j])
            {
                leader = false;
                break;
            }
        }
        if (leader == true)
        {
            ans.push_back(arr[i]);
        }
    }
    return ans;
}

vector<int> optimal(int arr[])
{
    vector<int> ans;
    int maxi = INT_MIN;
    for (int i=6-1; i>=0; i++)
    {
        if (arr[i]>maxi)
        {
            ans.push_back(arr[i]);
            maxi=arr[i];
        }
    }
    return ans;
}



int main()
{
    int arr[6] = {10, 22, 12, 3, 0, 6};
    vector<int> ans = brute(arr);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << endl;
    }

    return -1;
}