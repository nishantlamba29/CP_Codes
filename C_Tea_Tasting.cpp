#include <bits/stdc++.h>
using namespace std;
#define int long long

inline void n_lamba_29() {

    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for(int i=0;i<n;i++) cin >> a[i];
    for(int i=0;i<n;i++) cin >> b[i];

    vector<int> pre(n);
    vector<int> ans(n);

    pre[0] = b[0];
    for(int i=1;i<n;i++) {
        pre[i] = pre[i-1] + b[i];
    }

    vector<int> cnt(n);

    for(int i=0;i<n;i++) {
        int j = upper_bound(pre.begin(), pre.end(), a[i] + (i > 0 ? pre[i-1] : 0)) - pre.begin();
        cnt[i]++;
        if(j < n) {
            cnt[j]--;
            ans[j] += (a[i] - ( j > 0 ? (pre[j-1] - (i > 0 ? pre[i-1] : 0)) : 0));
        }
    }

    for(int i=1;i<n;i++) cnt[i] += cnt[i-1];

    for(int i=0;i<n;i++) {
        cout << cnt[i] * b[i] + ans[i] << " \n"[i == n-1]; // NOLINT
    }

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