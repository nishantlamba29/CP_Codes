#include <bits/stdc++.h>
using namespace std;
#define int long long

inline void n_lamba_29() {
    int n;
    cin >> n;
    vector<int> v(n);
    for(int i=0;i<n;i++) cin >> v[i];
    vector<int> pre(n+1, 0);
    for(int i=1;i<=n;i++) {
        pre[i] = pre[i-1] + v[i-1];
    }

    function<bool(int)> check = [&](int mid) {
        vector<int> dp(n+1, LLONG_MAX);
        dp[0] = 0;
        int j = 0;
        multiset<int> st;
        st.insert(0);
        for(int i=1;i<=n;i++) {
            while(j < i && pre[i-1] - pre[j] > mid) {
                st.erase(st.find(dp[j]));
                j++;
            }
            dp[i] = v[i-1] + *st.begin();
            st.insert(dp[i]);
        }
        while(j <= n && pre[n] - pre[j] > mid) {
            st.erase(st.find(dp[j]));
            j++;
        }
        return *st.begin() <= mid;
    };

    int lo = 1, hi = (int) 1e14, ans = 1;
    while(lo <= hi) {
        int mid = (lo + hi) >> 1LL;
        if(check(mid)) {
            ans = mid;
            hi = mid - 1;
        }
        else {
            lo = mid + 1;
        }
    }
    cout << ans << "\n";

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