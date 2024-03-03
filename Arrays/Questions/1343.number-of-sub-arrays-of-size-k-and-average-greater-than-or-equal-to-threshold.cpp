/*
 * @lc app=leetcode id=1343 lang=cpp
 *
 * [1343] Number of Sub-arrays of Size K and Average Greater than or Equal to Threshold
 */

// @lc code=start
class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int cnt=0, sum=0;
        for(int i = 0; i<k; i++){
            sum+=arr[i];
        }
        if(sum>=threshold*k) cnt++;
        for(int i=1; i<=arr.size()-k; i++){
            sum-=arr[i-1];
            sum+=arr[i+k-1];
            double avg = (double)sum/k;
            if(avg>=threshold) cnt++;
        }
        return cnt;
    }
};
// @lc code=end

