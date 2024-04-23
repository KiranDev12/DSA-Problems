#include<bits/stdc++.h>
using namespace std;

void reverse(int arr[], int l, int r){
    if (l>=r)
    {
        return;
    }
    swap(arr[l], arr[r]);
    reverse(arr, l+1, r-1);
}

int main(){
    int arr[5] = {0,1,2,3,4};
    reverse(arr, 0, 4);
    for(int it: arr){
        cout<<it<<endl;
    }
}