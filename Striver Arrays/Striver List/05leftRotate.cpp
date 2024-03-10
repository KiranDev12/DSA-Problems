// left Rotate by 1 place
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int arr[5] = {1, 2, 3, 4, 5};
    int first = arr[0]; // storing the first element 
    for (int i = 1; i < 5; i++)
    {
        arr[i - 1] = arr[i]; //shifting the rest
    }
    arr[5 - 1] = first; //bring back the last elemenet
    for (int i = 0; i < 5; i++)
    {
        cout << arr[i] << endl;
    }
}