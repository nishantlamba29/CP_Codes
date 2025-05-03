#include "bits/stdc++.h"
using namespace std;
#define int long long
const int N = 200005;
int n, x, y, ans, isCycle[N+1], vis[N+1], dp[N+1], deg[N+1];
vector<int> adj[N+1];

void solve(){
    cin>>n;
    for(int i=0;i<=n;i++){
        adj[i].clear();
        isCycle[i] = 1;
        vis[i] = 0;
        dp[i] = 1;
        deg[i] = 0;
    }
    for(int i=0;i<n;i++){
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
        deg[x]++;
        deg[y]++;
    }
    queue<int> q;
    for(int i=1;i<=n;i++){
        if(deg[i] == 1) {
            q.push(i);
            vis[i] = 1;
        }
    }
    while(q.size()){
        int node = q.front();
        q.pop();
        isCycle[node] = 0;
        for(auto &j : adj[node]){
            if(!vis[j]){
                deg[j]--;
                if(deg[j] == 1){
                    vis[j] = 1;
                    q.push(j);
                }
            }
            dp[j] += dp[node];
        }
    }
    ans = 0;
    for(int i=1;i<=n;i++){
        if(isCycle[i]){
            // subtree wale pairs k bich m path  +  subtree wale and bche hue k bich m 2*path
            // bcz cycle ki wjh se twice ho gya
            ans += dp[i]*(dp[i]-1)/2 + dp[i]*(n-dp[i]);
        }
    }
    cout<<ans<<"\n";

}

int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin>>t;
    while(t--){
        solve();
    }

    return 0;
}