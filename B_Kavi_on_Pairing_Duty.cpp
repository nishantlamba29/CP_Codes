#include "bits/stdc++.h"
using namespace std;
#define int long long
const int mod = 998244353;
const int N = 1e6;

int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);


    vector<int> div(N+10, 1);
    for(int i=2;i<=N;i++){
        for(int j=2*i;j<=N;j+=i){
            div[j]++;
        }
    }

    int n;
    cin>>n;
    
    vector<int> dp(2*n+1);
    int sum = 2;
    dp[0] = 1;
    dp[2] = 1;
    for(int i=4;i<=2*n;i+=2){
        dp[i] = (sum + div[i/2]) % mod;
        sum = (sum + dp[i]) % mod;
    }
    cout<<dp[2*n];

}