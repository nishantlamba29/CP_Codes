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

inline void n_lamba_29(){
    int n;
    cin>>n;
    int ans = n/15;
    int r2 = n%15;
    ans *= 3;
    for(int i=0;i<=r2;i++){
        if(i%3 == i%5) ans++;
    }
    cout<<ans<<"\n";

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