#include<bits/stdc++.h>
using namespace std;

bool palindrome(string s, int i){
    if (i>s.size()/2)
        return true;
    if (s[i]!=s[s.size()-i-1])
    {
        return false;  
    } 
    return palindrome(s, i+1);;  
}

int main(){
    string s;
    cin>>s;
    if (palindrome(s, 0))
    {
        cout<<"It is a palindrome"<<endl;
    } else {
        cout<<"It is not a palindrome"<<endl;
    }
    
}