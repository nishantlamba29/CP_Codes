#include<bits/stdc++.h>
using namespace std;

#define int long long
#define vec vector<int>
#define all(v) v.begin(),v.end()
#define pb push_back
#define rep(n) for(int i=0;i<n;i++)


bool check(int mid, vector<int> adj[], vector<int>& city, int n, int src, int dest){
    vector<int> vis(n+1, 0);
    set<int> st(all(city));
    queue<vec> q;
    q.push({src, 0});
    vis[src] = 1;
    while(q.size()){
        int u = q.front()[0];
        int len = q.front()[1];
        q.pop();
        if(len > mid) return 0;
        if(u == dest) return 1;
        for(auto & j: adj[u]){
            if(vis[j]) continue;
            vis[j] = 1;
            if(st.find(j) != st.end()){
                q.push({j, 0});
            }
            else q.push({j, len+1});
        }
    }
    return 0;
}
inline void n_lamba_29(){
    int n,m;
    cin>>n>>m;
    vector<int> adj[n+1];
    for(int i=0,u,v;i<m;i++){
        cin>>u>>v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    int c;
    cin>>c;
    vector<int> city(c); // city where loudspeaker is present
    rep(c) cin>>city[i];
    int src, dest;
    cin>>src>>dest;
    int l = 0, r = n, ans = -1;
    while(l <= r){
        int mid = (l+r)>>1;
        if(check(mid, adj, city, n, src, dest)){
            ans = mid;
            r = mid-1;
        }
        else l = mid+1;
    }

    cout<<ans<<"\n";

    return;
}


int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    n_lamba_29();

    return 0;
}
// Nishant ...