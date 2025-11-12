#include <bits/stdc++.h>
using namespace std;

inline void n_lamba_29() {

    int n;
    cin >> n;
    vector<int> v(n);
    for(int i=0;i<n;i++) cin >> v[i];
    
    vector<bool> dp(n + 1);
    dp[0] = 1;
    for(int i=1;i<=n;i++) {
        int ele = v[i-1];
        if(i + ele + 1 <= n && dp[i-1]) dp[i + ele + 1] = 1;
        if(i - ele >= 0 && dp[i - ele]) dp[i] = 1;
    }

    cout << (dp[n] ? "YES\n" : "NO\n");

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