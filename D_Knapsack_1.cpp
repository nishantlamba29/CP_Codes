#include<bits/stdc++.h>
using namespace std;
#define int long long

int rec(vector<int>& weight, vector<int>& val, int n, int cap, vector<vector<int>>& dp){
    if(n < 0) return 0;
    if(dp[n][cap] != -1) return dp[n][cap];
    int ff = rec(weight, val, n-1, cap, dp);
    int ss = 0;
    if(weight[n] <= cap){
        ss = rec(weight, val, n-1, cap - weight[n], dp) + val[n];
    }

    return dp[n][cap] = max(ff, ss);
}
int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, w;
    cin>>n>>w;
    vector<int> val(n), weight(n);
    for(int i=0;i<n;i++) {
        cin>>weight[i] >> val[i];
    }
    vector<vector<int>> dp(n, vector<int>(w+1,-1));
    int ans = rec(weight, val, n-1, w, dp);

    cout<<ans<<'\n';

}