//? Find GCD of two numbers
//* Easy
//-Euclidean algo
class Solution
{
public:
    int gcd(int m, int n)
    {
        int temp = -1;
        while (temp != 0)
        {
            temp = m % n;
            m = n;
            n = temp;
        }
        return m;
    }
    int recursive(int m, int n)
    {
        if (n == 0)
            return m;
        return gcd(n, m % n);
    }
    int findGCD(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        int m = nums[0], n = nums[nums.size() - 1];
        int gcd;
        for (int i = 1; i <= n; i++)
        {
            if (m % i == 0 && n % i == 0)
            {
                gcd = i;
            }
        }

        return gcd;
    }
};
