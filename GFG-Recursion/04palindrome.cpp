#include <iostream>
using namespace std;

bool isPalindrome(string s, int i)
{

    if (i > s.size() / 2)
    {
        return true;
    }

    return s[i] == s[s.size() - i - 1] && isPalindrome(s, i + 1);
}

int main()
{
    string str = "geeg";
    if (isPalindrome(str, 0))
        cout << "Yes";
    else
        cout << "No";

    return 0;
}

// #include <bits/stdc++.h>
// using namespace std;

// // A recursive function that
// // check a str[s..e] is
// // palindrome or not.
// bool isPalRec(char str[],
//               int s, int e)
// {

//     // If there is only one character
//     if (s >= e)
//         return true;

//     return (str[s] == str[e]) && isPalRec(str, s + 1, e - 1);
// }

// bool isPalindrome(char str[])
// {
//     int n = strlen(str);
//     if (n == 0)
//         return true;

//     return isPalRec(str, 0, n - 1);
// }

// // Driver Code
// int main()
// {
//     char str[] = "geeks";

//     if (isPalindrome(str))
//         cout << "Yes";
//     else
//         cout << "No";

//     return 0;
// }
