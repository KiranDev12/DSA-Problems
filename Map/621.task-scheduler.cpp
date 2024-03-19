/*
 * @lc app=leetcode id=621 lang=cpp
 *
 * [621] Task Scheduler
 */

// @lc code=start
class Solution
{
public:
    int leastInterval(vector<char> &tasks, int n)
    {
        int freq[26] = {0};
        for(char c: tasks) freq[c-'A']++;
        int spaces = 0;
        int cnt = 0;
        int max = 0;
        for (int i : f) {
            if (i > max) {
                max = i;  
                cnt = 1;
            } else if (i == max) {
                cnt++;
            }
        }
        return cnt;
    }
};
// @lc code=end
