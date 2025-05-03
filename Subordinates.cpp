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
const int mod = 998244353; // 1000000007
int lcm(int a, int b){ return (a/gcd(a,b))*b;}
void print(int a) { cout<<a<<endl;}
void print(vec v) { for(int i : v) cout<<i<<' '; cout<<endl; }
void print(string s) { cout<<s<<endl; }
const int N = 2e5;
int sz[N+1];
vector<int> adj[N+1];
void dfs(int node = 1, int p = -1){
    sz[node] = 1;
    for(auto &j : adj[node]){
        if(j != p){
            dfs(j, node);
            sz[node] += sz[j];
        }
    }
}

inline void n_lamba_29(){
    int n;
    cin>>n;
    for(int i=2;i<=n;i++){
        int x;
        cin>>x;
        adj[x].pb(i);
        adj[i].pb(x);
    }
    dfs();
    for(int i=1;i<=n;i++) cout<<sz[i]-1<<" ";
    cout<<"\n";

}


int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    n_lamba_29();
}