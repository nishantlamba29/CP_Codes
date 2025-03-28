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
#define all(v) v.begin(),v.end()
#define rll(v) v.rbegin(),v.rend()
#define pb push_back
#define rep(n) for(int i=0;i<n;i++)
#define gcd __gcd
template<class T>
using min_heap = priority_queue<T, vector<T>, greater<T>>;
const int inf = INT64_MAX;
const int ninf = INT64_MIN;
const int mod = 998244353;
int lcm(int a, int b){ return (a/gcd(a,b))*b;}
int powr(int a, int b){ int res = 1; while(b>0){ if(b&1) res *= a; a *= a; b = b>>1; } return res;}
int modpowr(int a, int b, int k){ int res = 1;while(b>0){ if(b&1) res = (res*a)%k; a = (a*a)%k; b = b>>1; } return res%k;}
int nCr(int n, int r){ if(n<r) return 0; if(r > n-r) r = n-r; int res = 1;
    for(int i=1;i<r+1;i++) {res *= (n-r+i); res /= i;} return res;}
vector<int> isPrime, spf;
void seive(int N = 1e6){ isPrime.resize(N+1,1); isPrime[0]=0; isPrime[1]=0;
    for(int i=2;i<=N;i++) if(isPrime[i]) for(int j=i*i;j<=N;j+=i) isPrime[j] = 0;}
void SPF(int N = 1e6){ spf.resize(N+1); iota(all(spf),0);
    for(int i=2;i*i<=N;i++) if(spf[i] == i) for(int j=i*i;j<=N;j+=i) spf[j] = min(spf[j],i);}


void dfs(int node, vector<int> g[], vector<int> &vis){
    vis[node] = 1;
    for(auto &j : g[node]){
        if(!vis[j]) dfs(j, g, vis);
    }
}
inline void n_lamba_29(){
    int n;
    cin>>n;
    vector<int> adj[n+1], deg(n+1, 0);
    vector<vector<int>> edge;
    for(int i=0,u,v;i<n-1;i++){
        cin>>u>>v;
        edge.pb({u,v});
        adj[u].pb(v);
        adj[v].pb(u);
        deg[u]++;
        deg[v]++;
    }
    int maxi = *max_element(all(deg));
    int maxi2 = 0, ff = -1, ss = -1;
    bool fg = 0;
    for(int i=1;i<=n;i++){
        if(!fg && maxi == deg[i]){
            fg = 1;
            ff = i;
        }
        if(i != ff && maxi2 < deg[i]){
            maxi2 = deg[i];
            ss = i;
        }
    }
    queue<int> q;
    q.push(ff);
    vector<int> dist(n+1, -1);
    vector<int> par(n+1, -1);
    dist[ff] = 0;
    while(q.size()){
        int node = q.front();
        if(node == ss) break; 
        q.pop();
        for(auto &j : adj[node]){
            if(dist[j] == -1){
                dist[j] = dist[node] + 1;
                q.push(j);
                par[j] = node;
            }
        }
    }
    vector<int> path;
    int t = ss;
    while(t != ff){
        path.pb(t);
        t = par[t];
    }
    path.pb(ff);
    set<int> st;
    for(int i=0;i<path.size();i++) {
        st.insert(path[i]);
    }

    vector<int> g[n+1];
    for(auto &i : edge){
        int u = i[0], v = i[1];
        if(st.find(u) == st.end() && st.find(v) == st.end()){
            g[u].pb(v);
            g[v].pb(u);
        }
    }
    int ans = 0;
    vector<int> vis(n+1, 0);
    for(int i=1;i<=n;i++){
        if(st.find(i) != st.end()) continue;
        if(!vis[i]){
            ans++;
            dfs(i, g, vis);
        }
    }
    ans = max(ans, (int)1);
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