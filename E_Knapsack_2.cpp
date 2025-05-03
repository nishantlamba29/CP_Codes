#include<bits/stdc++.h>
using namespace std;
#define int long long

int rec(vector<int>& weight, vector<int>& val, int n, int profit, vector<vector<int>>& dp){
    if(profit == 0) return 0;
    if(n < 0) return INT_MAX;
    if(dp[n][profit] != -1) return dp[n][profit];

    int ff = rec(weight, val, n-1, profit, dp);
    int ss = INT_MAX;
    if(profit - val[n] >= 0){
        int temp = rec(weight, val, n-1, profit - val[n], dp);
        if(temp != INT_MAX) {
            ss = weight[n] + temp;
        }
    }
    return dp[n][profit] = min(ff, ss);

}
int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, w;
    cin>>n>>w;
    vector<int> val(n), weight(n);
    int mx = 0;
    for(int i=0;i<n;i++) {
        cin>>weight[i] >> val[i];
        mx += val[i];
    }
    vector<vector<int>> dp(n, vector<int>(mx+1,-1));
    rec(weight, val, n-1, mx, dp);
    int ans = -1;
    for(int i=mx;i>=0;i--){
        if(rec(weight, val, n-1, i, dp) <= w){
            ans = i;
            break;
        }
    }
    cout<<ans<<"\n";

}