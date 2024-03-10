#include <bits/stdc++.h>
using namespace std;

// function check whether a number
// is prime or not
bool isPrime(int n)
{
    if (n <= 1)
        return false;
    if (n == 2 || n == 3)
        return true;
    if (n % 2 == 0 || n % 3 == 0)
        return false;
    for (int i = 5; i <= sqrt(n); i = i + 6)
        if (n % i == 0 || n % (i + 2) == 0)
            return false;

    return true;
}

// Driver Code
int main()
{
    isPrime(11) ? cout << "true\n" : cout << "false\n";
    return 0;
}
