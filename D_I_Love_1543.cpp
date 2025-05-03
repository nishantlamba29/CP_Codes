#include<bits/stdc++.h>
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

inline void n_lamba_29(){
    int n,m;
    cin>>n>>m;
    vector<string> v(n);
    rep(n) cin>>v[i];
    int ans = 0;
    

}

 
void solve() {
    int n, m;
    std::cin >> n >> m;
    
    std::vector<std::string> s(n);
    for (int i = 0; i < n; i++) {
        std::cin >> s[i];
    }
    
    int ans = 0;
    for (int d = 0; d < std::min(n, m) / 2; d++) {
        std::string t;
        for (int i = d; i < m - 1 - d; i++) {
            t += s[d][i];
        }
        for (int i = d; i < n - 1 - d; i++) {
            t += s[i][m - 1 - d];
        }
        for (int i = m - 1 - d; i > d; i--) {
            t += s[n - 1 - d][i];
        }
        for (int i = n - 1 - d; i > d; i--) {
            t += s[i][d];
        }
        t += t;
        for (int j = 0; j < t.size() / 2; j++) {
            ans += (t.substr(j, 4) == "1543");
        }
    }
    std::cout << ans << "\n";
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