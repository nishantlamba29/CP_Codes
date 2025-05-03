#include <bits/stdc++.h>
using namespace std;
#define int long long

inline void n_lamba_29() {

    int n;
    cin >> n;
    vector<int> v(n);
    for(int i = 0; i < n; i++) cin >> v[i];

    vector<vector<int>> dp(n+1, vector<int>(3));

    int curr = 1;
    dp[0][0] = 1;
    for(int i = 1; i < n; i++) {
        if(curr > v[i]) curr--;
        else if(curr < v[i]) curr++;

        dp[i][0] = curr;
        dp[i][1] = max(dp[i-1][0], dp[i-1][1]);

        int val = max(dp[i-1][1], dp[i-1][2]);

        if(val > v[i]) dp[i][2] = val - 1;
        else if(val < v[i]) dp[i][2] = val + 1;
        else dp[i][2] = val;
        
    }

    int ans = max(dp[n-1][1], dp[n-1][2]);
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