#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 1e9+7;
int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n,x;
    cin>>n>>x;
    vector<int> v(n);
    for(int i=0;i<n;i++) cin>>v[i];
    vector<int> dp(x+1);
    dp[0] = 1;
    for(int i=0;i<=x;i++){
        for(int j=0;j<n;j++){
            if(i-v[j] >= 0) dp[i] = (dp[i] + dp[i-v[j]])%mod;
        }
    }
    cout<<dp[x];
}