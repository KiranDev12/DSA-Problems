#include <bits/stdc++.h>
using namespace std;
vector<int> optimalType1(vector<int> &nums)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int i = 0;
    int j = 1;
    vector<int> ans = nums;
    for (int k = 0; k < ans.size(); k++)
    {
        if (ans[k] > 0)
        {
            nums[i] = ans[k];
            i += 2;
        }
        else if (ans[k] < 0)
        {
            nums[j] = ans[k];
            j += 2;
        }
    }
    return nums;
}

//Falling back to the brute force
vector<int> optimalType2(vector<int> &nums)
{
    //iterate twice O(2N) maintaining pos[] and neg[] 
    return nums;
}
int main()
{  
    vector<int> nums = {4,2,3,-1,-5,-10};
    vector<int> ans = optimalType1(nums);
    for(auto it: ans) cout<<it<<endl;
    return 0;
}
