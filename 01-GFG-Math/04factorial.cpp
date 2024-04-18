//? C++ program to find the factorial of a number
//* Easy

#include <iostream>
using namespace std;

// function to find factorial of given number
unsigned int brute(unsigned int n)
{
    int res = 1, i;
    for (i = 2; i <= n; i++)
        res *= i;
    return res;
}

unsigned int factorial(unsigned int n)
{
    if (n == 0 || n == 1)
        return 1;
    return n * factorial(n - 1);
}

// Driver code
int main()
{
    int num = 5;
    cout << "Factorial of "
         << num << " is "
         << factorial(num) << endl;
    return 0;
}
