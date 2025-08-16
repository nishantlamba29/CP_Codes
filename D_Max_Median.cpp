#include <bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    for(int i=0;i<n;i++) cin >> v[i];

    auto check = [&](int mid) {
        vector<int> pre(n + 1);
        for(int i=0;i<n;i++) {
            if(v[i] >= mid) pre[i + 1] = 1;
            else pre[i + 1] = -1;
        }
        multiset<int> st;
        for(int i=0;i<n;i++) {
            pre[i+1] += pre[i];
            if(i + 1 - k >= 0) st.insert(pre[i + 1 - k]);
            if(st.size() && pre[i + 1] - (*st.begin()) > 0) {
                return 1;
            }
        }
        return 0;
    };


    int lo = 1, hi = n, ans = -1;
    while(lo <= hi) {
        int mid = (lo + hi) >> 1;
        if(check(mid)) {
            lo = mid + 1;
            ans = mid;
        }
        else hi = mid - 1;
    }

    cout << ans;


    return 0;
}