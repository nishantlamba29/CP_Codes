#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
template <typename T>
using ordered_set = tree<T, null_type,less<T>, rb_tree_tag,tree_order_statistics_node_update>;
// Consistency doesn't guarantee you will be successful
// but not being consistent will guarantee that you won't reach success.
#define int long long
#define ld long double
#define pii pair<int,int>
#define vec vector<int>
#define vvec vector<vec>
#define R return
#define all(v) v.begin(),v.end()
#define rll(v) v.rbegin(),v.rend()
#define pb push_back
#define rep(n) for(int i=0;i<n;i++)
#define gcd __gcd
template<class T>
using min_heap = priority_queue<T, vector<T>, greater<T>>;
const int inf = 0x3f3f3f3f3f3f3f3fLL;
const int ninf = INT64_MIN;
const int mod = 998244353;
int lcm(int a, int b){ return (a/gcd(a,b))*b;}
void print(int a) { cout<<a<<endl;}
void print(vec v) { for(int i : v) cout<<i<<' '; cout<<endl; }
void print(string s) { cout<<s<<endl; }


void dfs(int node, vector<pii> adj[], vector<int> &vis, int &res){
    vis[node] = 1;
    for(auto &[v, w] : adj[node]){
        if(!vis[v]){
            dfs(v, adj, vis, res);
        }
    }
    res = node;
}

void dfs(int node, vector<pii> adj[], vector<int> &vis){
    vis[node] = 1;
    for(auto &[v, w] : adj[node]){
        if(!vis[v]){
            dfs(v, adj, vis);
        }
    }
}

pii check(int mid, vector<pii> adj[], int n){
    vector<pii> g[n+1];
    int ans = 0;
    for(int i=1;i<=n;i++){
        for(auto &[v,w ] : adj[i]){
            g[i].pb({v, w});
            if(w <= mid){
                g[v].pb({i, w});
                ans = max(ans, w);
            }
        }
    }
    vector<int> vis(n+1, 0);
    int node = -1;
    for(int i=1;i<=n;i++){
        if(!vis[i]){
            dfs(i, g, vis, node);
        }
    }
    fill(all(vis), 0);

    dfs(node, g, vis);
    for(int i=1;i<=n;i++){
        if(!vis[i]) return {0, 0};
    }
    return {1, ans};
}

inline void n_lamba_29(){
    int n,m;
    cin>>n>>m;
    vector<pii> adj[n+1];
    for(int i=0;i<m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        adj[u].pb({v, w});
    }
    int lo = 0, hi = 1e9, ans = -1;
    while(lo <= hi){
        int mid = (lo+hi)>>1LL;
        auto res = check(mid, adj, n);
        if(res.first){
            ans = res.second;
            hi = mid - 1;
        }
        else lo = mid + 1;
    }
    print(ans);
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