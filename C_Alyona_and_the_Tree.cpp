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

int n;
vector<int> wt;
void dfs(int node, int p, vector<pii> adj[], vector<int> &sz){
    for(auto &[v, w] : adj[node]){
        if(v != p){
            dfs(v, node, adj, sz);
            sz[node] += sz[v];
        }
    }
}

int dfs2(int node, int p, vector<pii> adj[], int dist, vec &sz){
    if(dist > wt[node]) return sz[node];
    int ans = 0;
    for(auto &[v,w] : adj[node]){
        if(v != p){
            ans += dfs2(v, node, adj, (dist + w < 0 ? 0 : dist + w), sz);
        }
    }
    return ans;
}

inline void n_lamba_29(){
    cin>>n;
    wt.resize(n+1);
    for(int i=1;i<=n;i++) cin>>wt[i];
    vector<pii> adj[n+1];
    for(int i=0;i<n-1;i++){
        int x,y;
        cin>>x>>y;
        adj[x].pb({i+2, y});
        adj[i+2].pb({x, y});
    }
    vector<int> sz(n+1, 1);
    dfs(1, -1, adj, sz);
    int cnt = dfs2(1, -1, adj, 0, sz);
    print(cnt);


}


int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    n_lamba_29();
}