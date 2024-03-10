#include <bits/stdc++.h>
using namespace std;
vector<int> brute(int arr1[], int arr2[], int n, int m)
{
    set<int> s;
    vector<int> intersection;
    for (int i = 0; i < n; i++)
        s.insert(arr1[i]);
    for (int i = 0; i < m; i++)
        s.insert(arr2[i]);
    for (auto &it : s)
        intersection.push_back(it);
    return intersection;
}
vector<int> optimal(int arr1[], int arr2[], int n, int m ) {
    //two pointer method i and j
}
int main()
{
    int arr1[5] = {1, 2, 3, 4, 5};
    int arr2[3] = {1, 2, 3};
    vector<int> intersections = brute(arr1, arr2, 5, 3);
    cout << "Union of arr1 and arr2 is  " << endl;
    for (auto &val : intersections)
        cout << val << " " << endl;
    return 0;
}