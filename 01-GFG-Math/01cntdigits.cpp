//? Count the number of digits in the integer n
//* Easy
//-keep dividing by 10 until the number is zero and increment count from 0
#include <bits/stdc++.h>
using namespace std;

int countDigit(long long n)
{
    if (n == 0)
        return 1;
    int count = 0;
    while (n != 0)
    {
        n = n / 10;
        ++count;
    }
    return count;
}

int main(void)
{
    long long n = 345289467;
    cout << "Number of digits : " << countDigit(n);
    return 0;
}