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
    vector<int> v(n);
    for(int i=0;i<n;i++) cin>>v[i];

    int sum = 0;
    set<int> st1 = {0}, st2 = {0};
    set<int> st3;
    vector<int> t1;

    int ind = -1, sum2 = 0;;
    for(int i=0;i<n;i++) {
        if(v[i] != 1 && v[i] != -1){
            ind = i;
            st3.insert(sum+v[i]);
            sum = 0;
            continue;
        } 
        int prev = sum;
        sum += v[i];
        if(prev >= 0 && sum < prev){
            sum = -1;
        }
        if(prev < 0 && sum > prev){
            sum = 1;
        }
        if(ind != -1){
            st2.insert(sum);
            sum2 += v[i];
            st3.insert(sum2);
        }
        else st1.insert(sum);
        
    }
    if(ind == -1){
        cout<<st1.size()<<"\n";
        while(st1.size()){
            auto it = st1.begin();
            cout<<(*it)<<" ";
            st1.erase(it);
        }
        cout<<"\n";
        return;
    }
    int val = v[ind];
    set<int> ans;
    for(auto i : st1){
        ans.insert(i+val);
        ans.insert(i);
    }

    for(auto i : st2){
        ans.insert(i+val);
        ans.insert(i);
    }
    for(auto i : st3){
        ans.insert(i);
    }
    int sum3 = accumulate(all(v), 0LL);
    ans.insert(sum3);
    cout<<ans.size()<<"\n";
    while(ans.size()){
        auto it = ans.begin();
        cout<<(*it)<<" ";
        ans.erase(it);
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