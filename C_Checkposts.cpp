#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 1000000007;

void dfs(int node, vector<int> adj[], vector<int>& st, vector<int>& vis){
    vis[node] = 1;
    for(auto j : adj[node]){
        if(!vis[j]){
            dfs(j, adj, st, vis);
        }
    }
    st.push_back(node);
}
int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin>>n;
    vector<int> v(n+1);
    for(int i=1;i<=n;i++) cin>>v[i];
    int m;
    cin>>m;
    vector<int> adj[n+1], radj[n+1];
    for(int i=0;i<m;i++){
        int x,y;
        cin>>x>>y;
        adj[x].push_back(y);
        radj[y].push_back(x);
    }
    
    vector<int> vis(n+1, 0);
    vector<int> topo1;
    for(int i=1;i<=n;i++){
        if(!vis[i]){
            dfs(i, adj, topo1, vis);
        }
    }
    reverse(topo1.begin(), topo1.end());

    vis.assign(n+1, 0);
    int ff = 0, ss = 1;
    for(auto node : topo1){
        if(vis[node])  continue;
        vector<int> temp;
        dfs(node, radj, temp, vis);
        int ans = 1e10, cnt = 0;
        for(int i=0;i<temp.size();i++){
            ans = min(ans, v[temp[i]]);
        }
        ff += ans;
        for(int i=0;i<temp.size();i++){
            if(v[temp[i]] == ans){
                cnt++;
                cnt %= mod;
            }
        }
        if(cnt > 1) ss = (ss*cnt)%mod;

    }


    cout<<ff<<" "<<ss<<"\n";


    return 0;
}
// Nishant ...