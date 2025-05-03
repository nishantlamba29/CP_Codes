#include <bits/stdc++.h>
using namespace std;
#define int long long

int modpowr(int a, int b, int k){
    int res = 1;
    while(b>0){
        if(b&1) res = (res*a)%k;
        a = (a*a)%k;
        b = b>>1;
    }
    return res%k;
}

int dp[1001][101][2];
int n,k,mod;

int solve(int ind = 0, int sum = 0, int flag = 0){
    if(ind == n){
        return flag && sum == 0;
    }
    else if(sum == 0 && flag){
        return 9*modpowr(10, n-ind-1, mod)%mod;
    }
    if(dp[ind][sum][flag] != -1) return dp[ind][sum][flag];

    int ans = 0;
    for(int i=(ind == n-1 ? 1 : 0);i<=9;i++) {
        int sum2 = (i*modpowr(10, ind, k)%k + sum)%k;
        flag |= (i!=0);
        ans = (ans + solve(ind+1, sum2, flag)) % mod;
    }
    return dp[ind][sum][flag] = ans;

}

int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>k>>mod;
    memset(dp, -1, sizeof(dp));
    cout<<solve();

}