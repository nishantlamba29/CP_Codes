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
const int mod = 998244353; // 1000000007
int lcm(int a, int b){ return (a/gcd(a,b))*b;}
void print(int a) { cout<<a<<endl;}
void print(vec v) { for(int i : v) cout<<i<<' '; cout<<endl; }
void print(string s) { cout<<s<<endl; }

int f(vector<int> a, vector<int> b, int m, int n){
    int l = 0, r = n, ans = 0;
    a[0] = m;
    sort(all(a));
    sort(all(b));
    while(l <= r) {
        int mid = (l+r)>>1;
        bool flag = 1;
        for(int i=0;i<n-mid;i++){
            if(a[i] >= b[i+mid]) {
                flag = 0;
                break;
            }
        }
        if(flag){
            ans = mid;
            r = mid - 1;
        }
        else l = mid + 1;
    }
    return ans;
}

inline void n_lamba_29(){
    int n,m;
    cin>>n>>m;
    vector<int> a(n), b(n);
    for(int i=1;i<n;i++) cin>>a[i];
    rep(n) cin>>b[i];

    int l = 1, r = m, ans = 0;
    int ans1 = f(a, b, l, n);
    while(l <= r){
        int mid = (l+r)>>1;
        if(f(a, b, mid, n) == ans1){
            ans = mid;
            l = mid + 1;
        }
        else{
            r = mid - 1;
        }
    }
    int res = ans1*ans + (m-ans)*(ans1+1);
    print(res);
    
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