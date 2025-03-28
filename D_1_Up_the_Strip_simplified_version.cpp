#include <bits/stdc++.h>
using namespace std;
#define int long long
int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n,m;
    cin>>n>>m;
    vector<int> dp(n+1);
    dp[1] = 1;
    int sum = 0, sum2 = 1;
    for(int i=1;i<=n;i++){
        dp[i] = (dp[i] + sum) % m;
        int j = 2;
        while(j <= i) {
            int q = i / j;
            int next_j = i / q + 1;
            int cnt = next_j - j;
            dp[i] = (dp[i] + (dp[q] * cnt) % m) % m;
            j = next_j;
        }
        sum = (sum + dp[i]) % m;
    }
    cout<<dp[n]<<endl;
    return 0;
}