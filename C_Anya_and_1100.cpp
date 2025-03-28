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
    string s;
    cin>>s;
    int tq;
    cin>>tq;
    if(s.size() < 4){
        rep(tq) {
            int ii,j;
            cin>>ii>>j;
            cout<<"NO\n";
        }
        return;
    }
    int cnt = 0;
    vector<int> vis(s.size(), 0);
    for(int i=0;i<=s.size()-4;i++){
        if(s.substr(i,4) == "1100") {
            vis[i] = 1;
            cnt++;
        }
    }
    while(tq--){
        int i;
        char v;
        cin>>i>>v;
        i--;
        s[i] = v;
        for(int j=max((int)0, i-3); j < min((int)s.size()-(int)3,i+4); j++){
            if(!vis[j] && s.substr(j, 4) == "1100") {
                vis[j] = 1;
                cnt++;
            }
            else if(vis[j] && s.substr(j, 4) != "1100") {
                vis[j] = 0;
                cnt--;
            }
        }
        if(cnt) cout<<"YES\n";
        else cout<<"NO\n";
    }
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