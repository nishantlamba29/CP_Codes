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
const int mod = 1e9+7;
int lcm(int a, int b){ return (a/gcd(a,b))*b;}
void print(int a) { cout<<a<<endl;}
void print(vec v) { for(int i : v) cout<<i<<' '; cout<<endl; }
void print(string s) { cout<<s<<endl; }

inline void n_lamba_29(){
    int n;
    cin>>n;
    vector<char> v(n);
    rep(n) cin>>v[i];
    vector<vector<int>> dp(n, vector<int>(n+1, 0));

    vector<int> pre(n+1);

    for(int i=0;i<=n;i++) {
        dp[n-1][i] = 1;
        pre[i] = i+1;
    }

    for(int i=n-2;i>=0;i--){
        for(int j=n-1;j>=0;j--){
            if(v[i] == 'f') dp[i][j] = dp[i+1][j+1];
            else dp[i][j] = pre[j];
        }

        for(int j=0;j<=n;j++) pre[j] = dp[i][j];
        for(int i=1;i<=n;i++) pre[i] = (pre[i] + pre[i-1]) % mod;
    }

    print(dp[0][0]);
}


int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    n_lamba_29();
}