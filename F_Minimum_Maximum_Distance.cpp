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
const int inf = 1e17;
const int ninf = -1e17;
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


int dfs(int node, int par, vector<int> & vis, vector<int> & dp, vector<int> adj[]){
    if(dp[node] != -1) return dp[node];
    int ans = 0;
    for(auto &i : adj[node]){
        if(i != par)
        ans = max(ans, 1 + dfs(i, node, vis, dp, adj));
    }
    return dp[node] = ans;
}
inline void n_lamba_29(){
    int n,k;
    cin>>n>>k;

    vector<int> adj[n+1], vis(n+1, 0), dp(n+1, -1);

    for(int i=0,x;i<k;i++) {
        cin>>x;
        vis[x] = 1;
    }
    
    for(int i=0,u,v;i<n-1;i++){
        cin>>u>>v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    int ans = inf;
    for(int i=1;i<=n;i++){
        if(vis[i]){
            dfs(i, -1, vis, dp, adj);
        }
    }
    for(int i=1;i<=n;i++){
        int f_i = dp[i];
        cout<<f_i<<" ";
        ans = min(ans, f_i);
    }
    cout<<"\n";
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