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
const int inf = 1e18;
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


int rec(string &c, string &a, string &b, int i, int j, vvec &dp){
    if(i+j == c.size()) return dp[i][j] = 0;
    if(dp[i][j] != -1) return dp[i][j];
    if(i>=a.size()){
        return dp[i][j] = rec(c,a,b,i,j+1, dp) + (b[j] != c[i+j]);
    }
    if(j>=b.size()){
        return dp[i][j] = rec(c,a,b,i+1,j, dp) + (a[i] != c[i+j]);
    }
    int ff = rec(c,a,b,i+1,j, dp) + (a[i] != c[i+j]);
    int ss = rec(c,a,b,i,j+1, dp) + (b[j] != c[i+j]);
    return dp[i][j] = min(ff, ss);

}
inline void n_lamba_29(){
    string a,b,c;
    cin>>a>>b>>c;
    int n = a.size(), m = b.size();
    vector<vec> dp(n+1, vec(m+1, inf));
    for(int i=n;i>=0;i--){
        for(int j=m;j>=0;j--){
            if(i == n && j == m){
                dp[i][j] = 0;
            }
            else if(i == n){
                dp[i][j] = dp[i][j+1] + (b[j] != c[i+j]); 
            }
            else if(j == m){
                dp[i][j] = dp[i+1][j] + (a[i] != c[i+j]);
            }
            else{
                dp[i][j] = min(dp[i+1][j] + (a[i] != c[i+j]), dp[i][j+1] + (b[j] != c[i+j]));
            }
        }
    }

    cout<<dp[0][0]<<"\n";

    // vvec dp(n+1, vec(m+1, -1));
    // int ans = rec(c, a, b, 0, 0, dp);
    // cout<<ans<<"\n";

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