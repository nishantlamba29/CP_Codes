#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pb push_back
void print(int a) { cout<<a<<endl;}
void print(vector<int> v) { for(int i : v) cout<<i<<' '; cout<<endl; }
void print(string s) { cout<<s<<endl; }

void dfs(int node, vector<int> adj[], vector<int> &vis, bool &ans, vector<int> &st,
     int &node_count, int &edge_count) {

    if(st[node]) ans = 0;
    vis[node] = 1;
    node_count++;
    for(auto &j : adj[node]){
        if(!vis[j]) {
            dfs(j, adj, vis, ans, st, node_count, edge_count);
        }
        edge_count++;
    }
}

inline void n_lamba_29(){
    int n,m,k;
    cin>>n>>m>>k;
    vector<int> adj[n+1];
    vector<int> st(n+1, 0);
    for(int i=0;i<k;i++) {
        int x;
        cin>>x;
        st[x] = 1;
    }
    for(int i=0,x,y;i<m;i++){
        cin>>x>>y;
        adj[x].pb(y);
        adj[y].pb(x);
    }

    vector<int> vis(n+1, 0);

    int result = 0, maxi = 0, sum = 0;
    vector<int> v;
    for(int i=1;i<=n;i++){
        if(!vis[i]){
            bool ans = 1;
            int node = 0, edge = 0;
            dfs(i, adj, vis, ans, st, node, edge);
            edge /= 2;
            // cout<<i<<" "<<node<<" "<<edge<<" \n";
            result += (node*(node-1)/2 - edge);
            if(ans == 1) {
                v.push_back(node);
                sum += node;
            }
            else {
                maxi = max(maxi, node);
            }
        }
    }
    // print(v);
    for(int i=0;i<v.size();i++){
        for(int j=i+1;j<v.size();j++){
            result += (v[i]*v[j]);
        }
    }
    result += (maxi*sum);
    print(result);


}


int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    n_lamba_29();
}