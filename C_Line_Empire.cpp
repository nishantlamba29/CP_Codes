#include <bits/stdc++.h>
using namespace std;
#define int long long

inline void n_lamba_29() {
    int n, a, b;
    cin >> n >> a >> b;
    vector<int> v(n+1, 0);
    for(int i=1;i<=n;i++) cin >> v[i];
    
    vector<int> suff(n+2, 0);
    for(int i=n;i>=1;i--) {
        suff[i] = suff[i+1] + v[i];
    }

    vector<int> dp(n+2, 0);

    for(int i=n-1;i>=0;i--) {
        dp[i] = min(dp[i+1] + (a+b)*(v[i+1] - v[i]), b*(suff[i+1] - (n-i)*v[i]));
    }

    cout << dp[0] << "\n";

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