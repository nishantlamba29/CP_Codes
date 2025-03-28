#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
template <typename T>
using ordered_set = tree<T, null_type,less<T>, rb_tree_tag,tree_order_statistics_node_update>;
// Consistency doesn't guarantee you will be successful
// but not being consistent will guarantee that you won't reach success.
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
const int inf = INT64_MAX;
const int ninf = INT64_MIN;
const int mod = 1000000007;
int lcm(int a, int b){ return (a/gcd(a,b))*b;}
void print(int a) { cout<<a<<endl;}
void print(vec v) { for(int i : v) cout<<i<<' '; cout<<endl; }
void print(string s) { cout<<s<<endl; }
int powr(int a, int b){ int res = 1; while(b>0){ if(b&1) res *= a; a *= a; b = b>>1; } return res;}
int modpowr(int a, int b, int k){ int res = 1;while(b>0){ if(b&1) res = (res*a)%k; a = (a*a)%k; b = b>>1; } return res%k;}
int nCr(int n, int r){ if(n<r) return 0; if(r > n-r) r = n-r; int res = 1;
    for(int i=1;i<r+1;i++) {res *= (n-r+i); res /= i;} return res;}
vector<int> isPrime, spf;
void seive(int N = 1e6){ isPrime.resize(N+1,1); isPrime[0]=0; isPrime[1]=0;
    for(int i=2;i<=N;i++) if(isPrime[i]) for(int j=i*i;j<=N;j+=i) isPrime[j] = 0;}
void SPF(int N = 1e6){ spf.resize(N+1); iota(all(spf),0);
    for(int i=2;i*i<=N;i++) if(spf[i] == i) for(int j=i*i;j<=N;j+=i) spf[j] = min(spf[j],i);}

inline void n_lamba_29(){
    int n,k;
    cin>>n>>k;
    vector<vvec> dp(n+1, vvec(k+1, vec(2)));
    // Base Cases
    for(int j=0;j<=k;j++){
        // 1st plane k left m chla gya then dp = 1;
        dp[0][j][0] = 1;
        // last plane k right m chla gya then dp = 1;
        dp[n][j][1] = 1;
    }
    // when k = 1 then dp = 1
    for(int i=0;i<=n;i++){
        dp[i][1][0] = 1;
        dp[i][1][1] = 1;
    }

    for(int j=2;j<=k;j++){
        for(int i=1;i<=n;i++){
            // going left = continue go left + (decay-1) go right
            dp[i][j][0] = (dp[i-1][j][0] + dp[i][j-1][1]) % mod;
        }
        for(int i=n-1;i>=0;i--){
            // going right = continue go right + (decay-1) go left
            dp[i][j][1] = (dp[i+1][j][1] + dp[i][j-1][0] ) % mod;
        }
    }

    // final answer is (0,k,1) as 
    // particle started left of 1st plane i.e. from 0 and towards right having decay = k 
    cout<<dp[0][k][1]<<"\n";
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int _;
    cin>>_;
    while(_-->0)
    n_lamba_29();
}