/*
 * @lc app=leetcode id=2125 lang=cpp
 *
 * [2125] Number of Laser Beams in a Bank
 */

// @lc code=start
class Solution
{
public:
    int numberOfBeams(vector<string> &bank)
    {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        if (bank.size() < 2)
            return 0;

        int ans = 0;
        short prev = 0;
        short curr = 0;
        for (size_t i = 0; i < bank.size(); ++i)
        {
            curr = 0;

            for (auto &it : bank[i])
            {
                if (it == '1')
                {
                    curr++;
                }
            }
            ans += curr * prev;
            prev = (curr == 0) * prev + curr;
        }

        return ans;
    }
};
// @lc code=end
