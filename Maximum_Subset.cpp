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
const int mod = 1000000007;
int lcm(int a, int b){ return (a/gcd(a,b))*b;}
void print(int a) { cout<<a<<endl;}
void print(vec v) { for(int i : v) cout<<i<<' '; cout<<endl; }
void print(string s) { cout<<s<<endl; }
int modpowr(int a, int b, int k){ int res = 1;while(b>0){ if(b&1) res = (res*a)%k; a = (a*a)%k; b = b>>1; } return res%k;}
inline void n_lamba_29(){
    int n;
    cin>>n;
    vec v(n);
    rep(n) cin>>v[i];
    int maxi = 0;
    for(int mask=0;mask<(1<<n);mask++){
        vec t;
        for(int i=0;i<n;i++){
            if(mask>>i&1) t.pb(v[i]);
        }
        int sz = t.size();
        if(sz%2==0 && sz > 0){
            sort(all(t));
            int t1 = 1, t2 = 1;
            for(int i=0;i<sz/2;i++){
                t1 = (t1*t[i])%mod;
            }
            for(int i=sz/2;i<sz;i++){
                t2 = (t2*t[i])%mod;
            }
            int inv = modpowr(t1, mod-2, mod);
            maxi = max(maxi, (inv*t2)%mod);
        }
    }
    print(maxi);
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