#include <bits/stdc++.h>
using namespace std;
#define int long long

inline void n_lamba_29() {
    int n;
    cin >> n;
    vector<int> v(n + 2);
    for(int i=1;i<=n;i++) cin >> v[i];
    v[0]=1e18;
    v[n+1]=1e18;
    int ans = 0;
    for(int i=1;i<=n;i+=2) {
        int mini=min({v[i],v[i-1],v[i+1]});
        ans=ans+abs(v[i]-mini);
        v[i]=mini;
    }
    int last=n;
    if(n%2==0){
        last--;
    }
    last=last-2;
    for(int i=last;i>=1;i-=2){
        if(v[i]+v[i+2]>v[i+1]){
            int op=v[i]+v[i+2]-v[i+1];
            ans=ans+op;
            v[i]=v[i]-op;
        }
    }

    cout << ans << "\n";

}


int32_t main(){
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int _;
    cin >> _;
    while (_-->0) {
        n_lamba_29();
    }


    return 0;
}