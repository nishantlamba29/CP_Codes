#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
template <typename T>
using ordered_set = tree<T, null_type,less_equal<T>, rb_tree_tag,tree_order_statistics_node_update>;
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

void print(vector<int> a){
    for(auto i : a) cout<<i<<" ";
    cout<<"\n";
}
inline void n_lamba_29(){
    int n,k,q;
    cin>>n>>k>>q;
    vector<vector<int>> v(n, vector<int>(k));
    for(int i=0;i<n;i++) for(int j=0;j<k;j++) cin>>v[i][j];
    vector<vector<int>> ant;
    for(int j=0;j<k;j++){
        vector<int> t = {v[0][j]};
        for(int i=1;i<n;i++){
            v[i][j] |= v[i-1][j];
            t.push_back(v[i][j]);
        }
        ant.push_back(t);
    }
    for(int i=0;i<q;i++){
        int m;
        cin>>m;
        int l = 1, h = n+1;
        for(int mm=0;mm<m;mm++){
            int r,c;
            char o;
            cin>>r>>o>>c;
            r--;
            if(o == '>') {
                int ind = upper_bound(all(ant[r]), c) - ant[r].begin();
                l = max(l, ind+1);
            }
            else {
                int ind = lower_bound(all(ant[r]), c) - ant[r].begin();
                h = min(h, ind);
            }
        }
        if(l > h || l > n) cout<<"-1\n";
        else cout<<l<<"\n";
    }
}


int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    n_lamba_29();
}