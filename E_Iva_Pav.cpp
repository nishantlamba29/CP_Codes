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
const int mod = 998244353;
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
    int n;
    cin>>n;
    vec v(n);
    rep(n) {
        cin>>v[i];
    }
    vector<vector<int>> pre(n, vector<int>(30, 0));

    for(int j=0;j<30;j++){
        pre[0][j] = v[0]>>j&1;
    }
    for(int i=1;i<n;i++){
        for(int j=0;j<30;j++){
             pre[i][j] += pre[i-1][j] + (v[i]>>j&1);
        }
    }

    int q;
    cin>>q;
    while(q--){
        int l, k;
        cin>>l>>k;
        l--;
        if(v[l] < k) {
            cout<<"-1 ";
            continue;
        }
        int lo = l, hi = n-1, ans = l;

        auto check = [&](int mid){
            int num = 0;
            for(int i=0;i<30;i++){
                if(pre[mid][i] - (l != 0 ? pre[l-1][i] : 0) == mid-l+1)
                    num += (1<<i);
            }
            return num >= k;
        };

        while(lo <= hi){
            int mid = (lo+hi)>>1;
            if(check(mid)){
                ans = mid+1;
                lo = mid+1;
            }
            else hi = mid-1;
        }
        cout<<ans<<" ";
    }
    cout<<"\n";
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