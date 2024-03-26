/*
 * @lc app=leetcode id=153 lang=cpp
 *
 * [153] Find Minimum in Rotated Sorted Array
 */

// @lc code=start
class Solution
{
public:
    int findMin(vector<int> &nums)
    {
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        int low = 0, high = nums.size() - 1;
        int mid;
        while (low < high)
        {
            mid = (low + high) / 2;

            if (nums[mid] > nums[high])
            {
                low = mid + 1;
            }
            else
            {
                high = mid;
            }
        }
        return nums[low];
    }
};
// @lc code=end
