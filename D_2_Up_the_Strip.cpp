#include "bits/stdc++.h"
using namespace std;
#define int long long

int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n,m;
    cin>>n>>m;

    vector<int> dp(n+1), cnt(n+1);

    dp[1] = 1;
    int sum = 0, sum2 = 0;
    for(int i=1;i<=n;i++){
        dp[i] = (dp[i] + ((sum + sum2) % m + cnt[i]) % m) % m;
        for(int j=2;i*j<=n;j++){
            int ff = i*j, ss = (i+1)*j;
            cnt[ff] = (cnt[ff] + dp[i]) % m;
            if(ss <= n)
            cnt[ss] = (cnt[ss] - dp[i] + m) % m;
        }
        sum = (sum + dp[i]) % m;
        sum2 = (sum2 + cnt[i]) % m;
    }
    cout<<dp[n];

    return 0;
}
