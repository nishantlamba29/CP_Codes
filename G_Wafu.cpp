#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 1e9 + 7;

int dp1[31], dp2[31];

inline void n_lamba_29() {

    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    for(int i=0;i<n;i++) cin >> v[i];

    sort(v.begin(), v.end());
    int ans = 1;
    for(int i=0;i<n;i++) {
        if(k <= 0) break;
        if(v[i] > 30) {
            ans = (ans * v[i]) % mod;
            k--;
            if(k == 0) break;
            while(k) {
                int ind = lower_bound(dp1, dp1 + 30, k) - dp1;
                if(dp1[ind] > k) ind--;
                k -= dp1[ind];
                ans = (ans * dp2[ind]) % mod;
                if(k <= 0) break;
            }
            break;
        }
        if(k - dp1[v[i]] >= 0) {
            k -= dp1[v[i]];
            ans = (ans * dp2[v[i]]) % mod;
        }
        else {
            ans = (ans * v[i]) % mod;
            k--;
            if(k == 0) break;
            while(k) {
                int ind = lower_bound(dp1, dp1 + 30, k) - dp1;
                if(dp1[ind] > k) ind--;
                k -= dp1[ind];
                ans = (ans * dp2[ind]) % mod;
                if(k <= 0) break;
            }
        }
    }

    cout << ans << "\n";

}


int32_t main(){
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    dp1[1] = 1;
    dp2[1] = 1;
    int sum = 1, prod = 1;
    for(int i=2;i<31;i++) {
        dp1[i] = 1 + sum;
        sum += dp1[i];
        dp2[i] = (i * prod) % mod;
        prod = (prod * dp2[i]) % mod;
    }
    
    int _;
    cin >> _;
    while (_-->0) {
        n_lamba_29();
    }


    return 0;
}