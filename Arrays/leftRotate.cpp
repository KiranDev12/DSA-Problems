//left Rotate by 1 place
#include<bits/stdc++.h>
using namespace std;

int main(){
    int arr[5] = {1,2,3,4,5};
    int first = arr[0];
    for (int i = 1; i < 5; i++)
    {
        arr[i-1]=arr[i];
    }
    arr[5-1]=first;
    for (int i = 0; i < 5; i++)
    {
        cout<<arr[i]<<endl;
    }
}