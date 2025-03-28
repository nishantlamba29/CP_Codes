/*
⠈⠙⠲⢶⣶⣶⣶⣶⣶⣶⣶⣶⣶⣶⣶⣶⣶⣿⡀⠀⠀⠀⠀⠀⠀⠀⡄⠀⠀⡄⠀⠀⠀⠀⠀⠀⠀⣼⣶⣶⣶⣶⣶⣶⣶⣶⣶⣶⣶⣶⣶⣿⠟⠓⠉
⠀⠀⠀⠀⠈⠙⢿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣷⣄⠀⠀⠀⠀⠀⢀⣧⣶⣦⣇⠀⠀⠀⠀⠀⢀⣼⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠟⠉⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠙⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣷⣶⣶⣶⣶⣾⣿⣿⣿⣿⣶⣶⣶⣶⣶⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠟⠁⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠸⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡏⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡇⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠛⠛⠛⠛⠛⠛⠛⠿⠿⢿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡿⠿⠿⠟⠛⠛⠛⠛⠛⠛⠃⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⠙⠻⢿⣿⣿⣿⣿⣿⣿⣿⣿⠟⠛⠉⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠉⠻⣿⣿⣿⡿⠋⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠹⣿⡟⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠛⠀⠀⠀
*/
#include<bits/stdc++.h>
using namespace std;
// Consistency doesn't guarantee you will be successful
// but not being consistent will guarantee that you won't reach success.
#define int long long
#define ld long double
#define pii pair<int,int>
#define vec vector<int>
#define vvec vector<vec>
#define all(v) v.begin(),v.end()
#define rll(v) v.rbegin(),v.rend()
#define pb push_back
#define rep(n) for(int i=0;i<n;i++)

void dfs(int node, vector<int> adj[], vec &vis, vec &topo){
    vis[node] = 1;
    for(auto &i : adj[node]){
        if(!vis[i]){
            dfs(i, adj, vis, topo);
        }
    }
    topo.pb(node);
}
int dfs2(int node, vector<int> adj[], vec &people, vec &dp){
    if(dp[node] != -1) return dp[node];
    int ans = 0;
    for(auto i : adj[node]){
        ans = max(ans, dfs2(i, adj, people, dp));
    }
    return dp[node] = people[node] + ans;
}
inline void n_lamba_29(){
    int n;
    cin>>n;
    vec adj[n+1], radj[n+1];
    for(int i=1, a;i<=n;i++){
        cin>>a;
        adj[i].pb(a);
        radj[a].pb(i);
    }
    vector<int> topo;
    vec vis(n+1, 0);
    for(int i=1;i<=n;i++){
        if(!vis[i]){
            dfs(i, adj, vis, topo);
        }
    }
    reverse(all(topo));
    for(int i=0;i<=n;i++) vis[i] = 0;
    vvec sccs;
    for(auto &node : topo){
        if(vis[node]) continue;
        vector<int> temp;
        dfs(node, radj, vis, temp);
        sccs.pb(temp);
    }
    int k = 0;
    vector<int> code(n+1), people(sccs.size(), 1);
    for(auto &i : sccs){
        for(auto &j : i) code[j] = k;
        people[k] = i.size();
        k++;
    }
    vector<int> newg[k+1];
    set<pii> st;
    for(int i=1;i<=n;i++){
        for(auto &j : adj[i]){
            if(code[i] != code[j] && st.find({code[i], code[j]}) == st.end()){
                newg[code[i]].push_back(code[j]);
                st.insert({code[i], code[j]});
            }
        }
    }
    vec dp(k, -1);
    for(int i=0;i<k;i++){
        if(dp[i] == -1) dfs2(i, newg, people, dp);
    }
    int sum = 0;
    for(int i=0;i<k;i++) {
        sum += people[i]*dp[i];
    }
    cout<<sum<<"\n";

}


int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    n_lamba_29();

    return 0;
}
// Nishant ...