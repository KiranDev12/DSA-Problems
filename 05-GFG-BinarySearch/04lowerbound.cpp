// CPP program to illustrate lower_bound()
// for both vectors and array

#include <bits/stdc++.h>
using namespace std;

// Driver code
int main()
{
     vector<int> v{10, 20, 30, 40, 50};

     cout << "Vector contains :";
     for (int i = 0; i < v.size(); i++)
          cout << " " << v[i];
     cout << "\n";

     vector<int>::iterator low1, low2;

     /// RETURNS ADDR. POINTER TO THAT ELEMENT. Subtract to get the index
     low1 = lower_bound(v.begin(), v.end(), 20);
     low2 = lower_bound(v.begin(), v.end(), 55);

     cout << "\nlower_bound for element 20 at position : "
          << (low1 - v.begin());
     cout << "\nlower_bound for element 55 at position : "
          << (low2 - v.begin());

     return 0;
}
