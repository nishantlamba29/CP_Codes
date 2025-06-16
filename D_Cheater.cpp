#include <bits/stdc++.h>
using namespace std;

inline void n_lamba_29() {

    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for(int i=0;i<n;i++) cin >> a[i];
    for(int i=0;i<n;i++) cin >> b[i];

    vector<int> pre(n), suff(n);
    pre[0] = 0;
    suff[n-1] = n-1;
    for(int i=1;i<n;i++) {
        if(a[i] < a[pre[i-1]]) pre[i] = i;
        else pre[i] = pre[i-1];
    }
    for(int i=n-2;i>=0;i--) {
        if(a[i] > a[suff[i+1]]) suff[i] = i;
        else suff[i] = suff[i+1];
    }

    auto check = [&](int mid) {
        swap(a[pre[mid - 1]], a[suff[mid]]);
        int i = 0, j = 0, cnt = 0;
        while(i < n && j < n && i + j < n) {
            if(a[i] > b[j]) {
                cnt++;
                i++;
            }
            else {
                j++;
            }
        }
        swap(a[pre[mid - 1]], a[suff[mid]]);
        return cnt >= mid;
    };

    int lo = 1, hi = n-1, ans = 0;
    while(lo <= hi) {
        int mid = (lo + hi) >> 1;
        if(check(mid)) {
            ans = mid;
            lo = mid + 1;
        }
        else hi = mid - 1;
    }
    int i = 0, j = 0, cnt = 0;
    while(i < n && j < n && i + j < n) {
        if(a[i] > b[j]) {
            cnt++;
            i++;
        }
        else {
            j++;
        }
    }
    ans = max(ans, cnt);
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