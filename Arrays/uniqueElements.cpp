#include<bits/stdc++.h>
using namespace std;
int brute(int arr[]){
    set<int> st;
    for (int i = 0; i < 6; i++)
    {
        st.insert(arr[i]);
    }
    return st.size();
}
int optimal(int arr[]){
    int cnt = 1;
    for (int i = 0; i < 5; i++)
    {
        if (arr[i]!=arr[i+1])
        {
            cnt+=1;
        }
    }
    return cnt;
}
int main(){
    int arr[6] = {1,1,1,2,2,3};
    cout << brute(arr) << endl;
    cout << optimal(arr) << endl;
    return 0;
}