//? C++ program to check if a number is Palindrome
//* Easy
//- reverse by using the last digit and appending it to the reversed no
#include <iostream>
using namespace std;
// Function to check Palindrome
bool checkPalindrome(int n)
{
    int reverse = 0;
    int temp = n;
    while (temp != 0)
    {
        reverse = (reverse * 10) + (temp % 10);
        temp = temp / 10;
    }
    return (reverse == n);
}
int main()
{
    int n = 7007;
    if (checkPalindrome(n) == 1)
    {
        cout << "Yes\n";
    }
    else
    {
        cout << "No\n";
    }
    return 0;
}
