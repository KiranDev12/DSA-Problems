#include <bits/stdc++.h>
using namespace std;
vector<int> brute(vector<int> &nums, int target)
{
    int n = nums.size();
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == j)
                continue;
            if (nums[i] + nums[j] == target)
                return {i, j};
        }
    }
    return {-1, -1};
}

vector<int> better(vector<int> &nums, int target)
{
    unordered_map<int, int> mpp;
    for (int i = 0; i < nums.size(); i++) {
        int num = nums[i];
        int rem = target - num;
        if (mpp.find(rem) != mpp.end()) {
            return {mpp[rem], i};
        }
        mpp[num] = i;
    }
    return { -1, -1};
}

string optimal(vector<int> &arr, int target) {
    int n = arr.size();
    sort(arr.begin(), arr.end());
    int left = 0, right = n - 1;
    while (left < right) {
        int sum = arr[left] + arr[right];
        if (sum == target) {
            return "YES";
        }
        else if (sum < target) left++;
        else right--;
    }
    return "NO";
}
int main()
{
    vector<int> nums = {2,7,11,15};
    // vector<int> ans = brute(nums, 9);
    // vector<int> ans =  better(nums, 9);
    string ans =  optimal(nums, 9);
    // for (int i = 0; i < 2; i++)
    // {
    //     cout<<ans[i]<<endl;
    // }
    cout<<ans<<endl;
    return -1;
}