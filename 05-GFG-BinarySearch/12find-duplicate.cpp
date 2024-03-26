class Solution
{
public:
    int findDuplicate(vector<int> &arr)
    {
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        int slow = arr[0], fast = arr[0];
        do
        {
            slow = arr[slow];
            fast = arr[arr[fast]];
        } while (slow != fast);
        slow = arr[0];
        while (slow != fast)
        {
            slow = arr[slow];
            fast = arr[fast];
        }
        return slow;
    }
};