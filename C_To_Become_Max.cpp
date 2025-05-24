#include <bits/stdc++.h>
using namespace std;
#define int long long

inline void n_lamba_29() {
    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    for(int i=0;i<n;i++) {
        cin >> v[i];
    }
    
    auto check = [&](int mid) {
        for(int i=0;i<n;i++) {
            if(mid == v[i]) return true;
            else if(mid > v[i]) {
                int curr = mid - v[i];
                int next = mid - 1;
                for(int j=i+1;j<n;j++) {
                    if(curr > k) break;
                    if(v[j] >= next) return true;
                    curr += (next - v[j]);
                    next--;
                }
            }
        }
        return false;
    };

    int maxi = *max_element(v.begin(), v.end());
    int lo = maxi, hi = maxi + k + 1, ans = maxi;
    while(lo <= hi) {
        int mid = (lo + hi) >> 1;
        if(check(mid)) {
            ans = max(ans, mid);
            lo = mid + 1;
        }
        else hi = mid - 1;
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