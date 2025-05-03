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

void dfs(int node, int p, vector<int> adj[], vector<int> &dist){
    for(auto &j : adj[node]){
        if(j != p){
            dist[j] = dist[node] + 1;
            dfs(j, node, adj, dist);
        }
    }
}

inline void n_lamba_29(){
    int n,x;
    cin>>n>>x;
    vector<int> adj[n+1];
    for(int i=0;i<n-1;i++){
        int u,v;
        cin>>u>>v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    vector<int> dist1(n+1), dist2(n+1);
    dist1[1] = 0;
    dfs(1, -1, adj, dist1);
    dist2[x] = 0;
    dfs(x, -1, adj, dist2);

    int maxi = 0;
    for(int i=1;i<=n;i++){
        if(dist1[i] > dist2[i]){
            maxi = max(maxi, dist1[i]);
        }
    }
    print(2*maxi);

}


int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    n_lamba_29();
}