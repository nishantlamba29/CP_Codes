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

int solve(int ind, int digit, vector<int> &v, int n, vvec &dp){
    if(ind == n) return 1;
    if(dp[ind][digit] != -1) return dp[ind][digit];
    int ans = 0;
    for(auto &num : v){
        if(abs(digit - num) <= 2){
            ans += solve(ind+1, num, v, n, dp);
        }
    }
    return dp[ind][digit] = ans;
}

inline void n_lamba_29(){
    int m,n;
    cin>>m>>n;
    vector<int> v(m);
    rep(m) cin>>v[i];
    int ans = 0;
    vvec dp(n+1, vec(11, -1));
    for(auto &dig : v){
        ans += solve(1, dig, v,  n, dp);
    }
    print(ans);
}


int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    rep(t){
        cout<<"Case "<<i+1<<": ";
        n_lamba_29();
    }
}