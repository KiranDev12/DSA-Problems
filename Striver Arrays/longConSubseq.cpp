#include <bits/stdc++.h>
using namespace std;

bool linearSearch(vector<int>&a, int num) {
    int n = a.size();
    for (int i = 0; i < n; i++) {
        if (a[i] == num)
            return true;
    }
    return false;
}
int brute(vector<int>&a) {
    int n = a.size();
    int longest = 1;
    for (int i = 0; i < n; i++) {
        int x = a[i];
        int cnt = 1;
        while (linearSearch(a, x + 1) == true) {
            x += 1;
            cnt += 1;
        }
        longest = max(longest, cnt);
    }
    return longest;
}

int better(vector<int>&a) {
    int n = a.size();
    if (n == 0) return 0;
    sort(a.begin(), a.end());
    int lastSmaller = INT_MIN;
    int cnt = 0;
    int longest = 1;

    for (int i = 0; i < n; i++) {
        if (a[i] - 1 == lastSmaller) {
            cnt += 1;
            lastSmaller = a[i];
        }
        else if (a[i] != lastSmaller) {
            cnt = 1;
            lastSmaller = a[i];
        }
        longest = max(longest, cnt);
    }
    return longest;

}

int optimal(vector<int>&a){
    int n = a.size();
    if (n == 0) return 0;

    int longest = 1;
    unordered_set<int> st;
    for (int i = 0; i < n; i++) {
        st.insert(a[i]);
    }
    for (auto it : st) {
        if (st.find(it - 1) == st.end()) {
            int cnt = 1;
            int x = it;
            while (st.find(x + 1) != st.end()) {
                x = x + 1;
                cnt = cnt + 1;
            }
            longest = max(longest, cnt);
        }
    }
    return longest;

}

int main()
{
    vector<int> a = {100, 200, 1, 2, 3, 4};
    int ans = brute(a);
    cout << "The longest consecutive sequence is " << ans << "\n";
    ans = better(a);
    cout << "The longest consecutive sequence is " << ans << "\n";
    ans = optimal(a);
    cout << "The longest consecutive sequence is " << ans << "\n";
    return 0;
}