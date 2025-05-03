#include "bits/stdc++.h"
using namespace std;

#define int long long
const int mod = 998244353;

void solve(){
    string s;
    cin>>s;
    int n = s.size();
    int ans = 0, ways = 1;
    int l = 0, r = 0;
    while(r < n){
        while(s[l] == s[r]) r++;
        ans += r-l-1;
        ways *= r-l;
        ways %= mod;
        l = r;
    }

    for(int i=2;i<=ans;i++){
        ways *= i;
        ways %= mod;
    }

    cout<<ans<<" "<<ways<<"\n";

    
}

int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin>>t;
    while(t--)
    solve();

    return 0;
}