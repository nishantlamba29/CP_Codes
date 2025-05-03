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

bool check(vector<int> v, int mid, int h){
    sort(v.begin(), v.begin()+mid+1);
    int cnt = 0;
    for(int i=mid;i-1>=0;i-=2){
        if(h < 0) return 0;
        if(v[i] <= h && v[i-1] <= h){
            h -= max(v[i], v[i-1]);
            cnt += 2;
        }
    }
    if(mid % 2 == 0){
        if(v[0] <= h) cnt++;
    }
    return cnt == mid+1;
}

inline void n_lamba_29(){
    int n,h;
    cin>>n>>h;
    vector<int> v(n);
    rep(n) cin>>v[i];

    int l = 0, r = n-1, ans = 0;
    while(l <= r){
        int mid = (l+r)>>1;
        if(check(v, mid, h)){
            ans = mid + 1;
            l = mid + 1;
        }
        else r = mid - 1;
    }
    print(ans);

}


int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    n_lamba_29();
}