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

     vector<int>::iterator upper1, upper2;

     /// RETURNS ADDR. POINTER TO THAT ELEMENT. Subtract to get the index
     upper1 = upper_bound(v.begin(), v.end(), 35);
     upper2 = upper_bound(v.begin(), v.end(), 45);

     cout << "\nUpper_bound for element 35 is at position : "
          << (upper1 - v.begin());
     cout << "\nUpper_bound for element 45 is at position : "
          << (upper2 - v.begin()) << "\n\n";

     return 0;
}
