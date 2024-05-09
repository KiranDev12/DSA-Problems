//? Find the prime factors of a number
//* Easy
//- The loop iterates from 5 up to the square root of the number, checking only every sixth number (i) and (i + 2). This is based on the fact that all primes greater than 3 can be expressed as 6k +/- 1 

#include <bits/stdc++.h>
using namespace std;

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
