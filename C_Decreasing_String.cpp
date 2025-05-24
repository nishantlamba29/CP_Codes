#include <bits/stdc++.h>
using namespace std;

inline void n_lamba_29() {
    string s;
    int64_t pos;
    cin >> s >> pos;

    int64_t n = s.size();

    int64_t k = -1;
    int64_t lo = 0, hi = n+1;
    while(lo <= hi) {
        int64_t mid = (lo + hi) >> 1;
        int64_t val = (mid + 1) * (2 * n - mid) / 2;
        if(val >= pos) {
            k = mid;
            hi = mid - 1;
        }
        else lo = mid + 1;
    }
    if(k == 0) {
        cout << s[pos - 1];
        return;
    }
    pos -= k * (2 * n - k + 1) / 2;
    
    stack<int> st;
    vector<bool> del(n, 0);
    for(int i=0;i<n;i++) {
        while(k > 0 && !st.empty() && s[i] < s[st.top()]) {
            del[st.top()] = 1;
            st.pop();
            k--;
        }
        st.push(i);
    }

    while(k > 0) {
        del[st.top()] = 1;
        st.pop();
        k--;
    }

    string temp;
    for(int i=0;i<n;i++) {
        if(!del[i]) temp += s[i];
    }

    cout <<temp[pos - 1];

}

int32_t main(){
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int _;
    cin >> _;
    while (_-->0) {
        n_lamba_29();
    }


    return 0;
}