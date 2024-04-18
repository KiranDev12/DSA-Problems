//? Count trailing zeroes in factorial of a number
//* Easy
//- The logic behind counting trailing zeroes in the factorial of a number lies in the fact that trailing zeroes are created by pairs of factors of 2 and 5. Since factors of 2 appear much more frequently than factors of 5 in the factorial expansion, we only need to count the number of factors of 5.

class Solution
{
public:
    int trailingZeroes(int n)
    {
        int res = 0;
        for (int i = 5; i <= n; i = i * 5)
        {
            res += n / i;
        }
        return res;
    }
};