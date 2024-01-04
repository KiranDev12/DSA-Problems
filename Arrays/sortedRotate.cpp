// Input: nums = [3,4,5,1,2]
// Output: true


// Input: nums = [2,1,3,4]
// Output: false
#include<bits/stdc++.h>
using namespace std;
bool check(vector<int> &nums)
{
    int n = nums.size();
    int cnt = 0;
    for (int i = 1; i < n; i++)
    {
        if (nums[i - 1] > nums[i])
        {
            cnt++;
        }
    }
    if (nums[n - 1] > nums[0])
    {
        cnt++;
    }
    if (cnt <= 1)
    {
        return true;
    }
    return false;
}

int main(){
    vector<int> nums = {2,1,3,4};
    cout<<check(nums)<<endl;
    return 0;
}
