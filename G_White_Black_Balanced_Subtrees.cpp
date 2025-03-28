#include <bits/stdc++.h>
using namespace std;
// Consistency doesn't guarantee you will be successful
// but not being consistent will guarantee that you won't reach success.
#define int long long
#define vec vector<int>
#define pb push_back
#define rep(n) for(int i=0;i<n;i++)

int dfs(int node, string &s, vector<int> adj[], int &ans){
    int sum = s[node-1] == 'W' ? 1 : -1;
    for(auto &j : adj[node]){
        sum += dfs(j, s, adj, ans);
    }
    if(sum == 0) ans++;
    return sum;
}

inline void n_lamba_29(){
    int n;
    cin>>n;
    vector<int> adj[n+1];
    rep(n-1){
        int x;
        cin>>x;
        adj[x].pb(i+2);
    }
    string s;
    cin>>s;
    int ans = 0;
    dfs(1, s, adj, ans);
    cout<<ans<<"\n";

}


int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int _;
    cin>>_;
    while(_-->0)
    n_lamba_29();
}