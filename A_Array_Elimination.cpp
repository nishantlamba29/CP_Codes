#include "bits/stdc++.h"
using namespace std;

#define int long long

void solve(){
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;i++) cin>>v[i];
    int ans = 0;
    vector<int> mp(30, 0);
    for(int i=0;i<n;i++){
        for(int j=0;j<30;j++){
            mp[j] += (v[i] >> j & 1);
        }
    }
    for(int i=0;i<30;i++){
        ans = __gcd(ans, mp[i]);
    }
    if(ans == 0){
        for(int i=1;i<=n;i++) cout<<i<<" ";
        cout<<"\n";
        return;
    }
    vector<int> res;
    for(int i=1;i*i<=ans;i++){
        if(ans % i == 0){
            res.push_back(i);
            if(i*i != ans){
                res.push_back(ans/i);
            }
        }
    }
    sort(res.begin(), res.end());
    for(auto i : res) cout<<i<<" ";
    cout<<"\n";


}

int32_t main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int t;
    cin>>t;
    while(t--){
        solve();
    }

    return 0;
}