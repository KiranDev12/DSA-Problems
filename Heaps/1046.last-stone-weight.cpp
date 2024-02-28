/*
 * @lc app=leetcode id=1046 lang=cpp
 *
 * [1046] Last Stone Weight
 */

// @lc code=start
class Solution
{
public:
    int lastStoneWeight(vector<int> &stones)
    {
        priority_queue<int> pq(stones.begin(),stones.end());
        while(pq.size()>1){
            int num=pq.top();
            pq.pop();
            int num1=pq.top();
            pq.pop();
            if(num!=num1) 
                pq.push(abs(num-num1));
        }
        if(pq.empty()) return 0;
        return pq.top();
    }
};
// @lc code=end
