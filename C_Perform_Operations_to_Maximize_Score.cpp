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

bool check(int mid, vector<pii> &v, int n, int k){
    int cnt = 0;
    for(int i=n-2;i>=0;i--){
        if(v[i].first >= mid){
            cnt++;
        }
        else if(v[i].second == 1){
            int diff = mid - v[i].first;
            if(diff <= k){
                k -= diff;
                cnt++;
            }
        }
    }
    return cnt >= (n+1)/2;
}
inline void n_lamba_29(){
    int n,k;
    cin>>n>>k;
    vector<pii> v(n);
    rep(n) cin>>v[i].first;
    rep(n) cin>>v[i].second;
    sort(all(v));
    int ans = 0;
    for(int i=0;i<n;i++){
        if(v[i].second == 0) continue;
        int med;
        if(i < n/2) med = v[n/2].first;
        else med = v[(n-2)/2].first;
        ans = max(ans, v[i].first + k + med);
    }
    int l = v[0].first, r = 2e9;
    int median = 0;
    while(l <= r) {
        int mid = (l+r)>>1;
        if(check(mid, v, n, k)) {
            median = mid;
            l = mid + 1;
        }
        else r = mid - 1;
    }
    ans = max(ans, v.back().first + median);
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