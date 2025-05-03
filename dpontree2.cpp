#include<bits/stdc++.h>
using namespace std;
#define int long long

int n;
vector<int> dp, wt;
vector<vector<int>> adj;

int dfs(int node, int par = -1){
    if(dp[node] != -1) return dp[node];
    int ans = 0;
    for(auto &j : adj[node])
        if(j != par)
            ans += dfs(j, node);
    
    return dp[node] = max(ans, wt[node]);
}

int32_t main(){

    cin>>n;
    wt.resize(n+1);
    adj.resize(n+1);
    dp.resize(n+1, -1);
    for(int i=0,a,b;i<n-1;i++){
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    for(int i=1;i<=n;i++) cin>>wt[i];

    cout<<dfs(1)<<"\n";

    // xor of odd numbers
    
    // int rem = n/4, mod = n%4;
    // if(rem&1 && mod == 1) n+2;
    // if(!(rem&1) && mod == 1) n
    // even 3 0
    // odd 3 2
    // int ans = 0;
    // for(int i=1;i<=99;i+=2){
    //     int rem = i%4, q = i/4;
    //     cout<<i<<" ->";
    //     if(rem == 1){
    //         if(q&1) cout<<i+2<<"\n";
    //         else cout<<i<<"\n";
    //     }
    //     else{
    //         if(q&1) cout<<0<<"\n";
    //         else cout<<2<<"\n";
    //     }
    // }
    
}