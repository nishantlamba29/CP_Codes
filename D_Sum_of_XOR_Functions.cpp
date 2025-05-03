#include <bits/stdc++.h>

using namespace std;

// Consistency doesn't guarantee you will be successful
// but not being consistent will guarantee that you won't reach success.
#define int long long

#define vec vector<int>

#define rep(n) for(int i=0;i<n;i++)

const int mod = 998244353;

inline void n_lamba_29(){
    int n;
    cin>>n;
    vector<int> v(n);
    rep(n) cin>>v[i];
    vec pre = v;
    int ans = 0;
    for(int i=1;i<n;i++) pre[i] ^= pre[i-1];

    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            ans += ((pre[j]^pre[i]^v[i])*(j-i+1));
            ans %= mod;
        }
    }
    cout<<ans<<"\n";
}


int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    n_lamba_29();
}