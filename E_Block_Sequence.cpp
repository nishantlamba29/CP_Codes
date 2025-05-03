#include "bits/stdc++.h"
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> v(n);
        for(int i=0;i<n;i++) cin>>v[i];
        vector<int> dp(n+1, n+1);
        dp[n] = 0;
        dp[n-1] = 1;
        for(int i=n-2;i>=0;i--){
            if(i+v[i]+1 > n) dp[i] = dp[i+1] + 1;
            else if(i+v[i]+1 == n) dp[i] = 0;
            else dp[i] = min(dp[i+1] + 1, dp[i+v[i]+1]);
        }
        cout<<dp[0]<<"\n";
    }
}