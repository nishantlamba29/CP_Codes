#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
using i64 = int;
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

int fun(int x){
    if(x%4 == 0) return x;
    if(x%4 == 1) return 1;
    if(x%4 == 2) return x+1;
    return 0;
}
i64 get(i64 n) {
    if (n % 4 == 0) {
        return 0;
    } else if (n % 4 == 1) {
        return n - 1;
    } else if (n % 4 == 2) {
        return 1;
    } else {
        return n;
    }
}
 
void n_lamba_29() {
    i64 l, r, i, k;
    std::cin >> l >> r >> i >> k;
    r++;
    
    i64 ans = 0;
    ans ^= get(r);
    ans ^= get(l);
    
    r = (r - k + (1LL << i) - 1) >> i;
    l = (l - k + (1LL << i) - 1) >> i;
    
    ans ^= get(r) << i;
    ans ^= get(l) << i;
    
    if ((l ^ r) & 1) {
        ans ^= k;
    }
    
    cout << ans << "\n";
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