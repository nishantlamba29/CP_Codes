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

void dfs(int node, vector<int> &vis, vector<int> &v, vector<int> adj[]){
    v.pb(node);
    vis[node] = 1;
    for(auto &j : adj[node]){
        if(!vis[j]) dfs(j, vis, v, adj);
    }
}

void dfs(int node, int p, vector<int> adj[], vector<vector<int>> &par, vector<int>& depth){
    par[node][0] = p;
    for(int i=1;i<20;i++){
        if(par[node][i-1] != -1)
        par[node][i] = par[par[node][i-1]][i-1];
        else
        par[node][i-1] = -1;
    }
    for(auto &j : adj[node]){
        if(j != p){
            depth[j] = depth[node] + 1;
            dfs(j, node, adj, par, depth);
        }
    }
}

inline void n_lamba_29(){
    int n,q;
    cin>>n>>q;
    vector<int> adj[n+1];
    for(int i=2;i<=n;i++){
        int x;
        cin>>x;
        adj[x].pb(i);
        adj[i].pb(x);
    }

    vector<int> vis(n+1, 0), v;

    vector<vector<int>> par(n+1, vector<int>(20));

    vector<int> depth(n+1);

    dfs(1, vis, v, adj);

    depth[1] = 0;
    dfs(1, -1, adj, par, depth);

    map<int,int> mp;

    for(int i=0;i<n;i++) mp[v[i]] = i;
    
    auto check = [&](int u, int v){
        if(depth[u] > depth[v]) return false;
        int diff = depth[v] - depth[u];
        for(int i=0;i<20;i++){
            if(diff >> i & 1){
                v = par[v][i];
            }
        }
        return v == u;
    };

    while(q--){
        int u,k;
        cin>>u>>k;
        int ind = mp[u];
        int ind2 = ind + k - 1;
        if(ind2 >= n){
            print(-1);
            continue;
        }
        int ele = v[ind2];
        if(check(u, ele)) print(ele);
        else print(-1);
    }
    cout<<"\n";
}


int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    n_lamba_29();
}