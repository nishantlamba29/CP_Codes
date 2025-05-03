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

int dfs(int i, int j, vector<pii> adj[], int prev, vector<vvec> &dp){
    if(dp[i][j][prev] != -1) return dp[i][j][prev];
    bool ans = 0;
    for(auto &ngh : adj[i]){
        if(ngh.second >= prev){
            ans |= !dfs(j, ngh.first, adj, ngh.second, dp);
        }
    }
    return dp[i][j][prev] = ans;
}

inline void n_lamba_29(){
    int n,m;
    cin>>n>>m;
    vector<pii> adj[n+1];
    for(int i=0;i<m;i++){
        int x,y;
        char z;
        cin>>x>>y>>z;
        adj[x].pb({y, z-'a'});
    }

    vector<vvec> dp(n+1, vvec(n+1, vec(26, -1)));
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(dfs(i,j,adj,0,dp)) cout<<'A';
            else cout<<'B';
        }
        cout<<"\n";
    }
}


int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    n_lamba_29();

}