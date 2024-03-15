/*
 * @lc app=leetcode id=1423 lang=cpp
 *
 * [1423] Maximum Points You Can Obtain from Cards
 */

// @lc code=start
class Solution {
public:
    int maxScore(vector<int>& card, int k) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        int total = 0;
        for(int x: card) total += x;
        int size = card.size() - k;
        int left = 0, right = size - 1;
        int curr = 0, ans = INT_MAX;
        for(int i = 0; i < size; i++) curr += card[i];
        for(int i = 0; i <= card.size() - size; i++) {
            if(ans > curr) {
                left = i;
                right = i + size - 1;
                ans = curr;
            }
            if(i < card.size() - size) {
                curr -= card[i];
                curr += card[i + size];
            }
        }    
        
        return total - ans;
    }
};

// @lc code=end

