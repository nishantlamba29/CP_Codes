#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve(){
    int n;
    cin>>n;
    vector<int> v(n);
    map<int,int> mp;
    for(int i=0;i<n;i++) {
        cin>>v[i];
        mp[v[i]]++;
    }
    int q;
    cin>>q;
    while(q--){
        int x,y;
        cin>>x>>y;
        int ans = 0;
        int D = x*x-(y<<2);
        if(D == 0 && x%2 == 0){
            int no = mp[x/2];
            ans = no*(no-1)/2;
        }
        else if(D > 0){
            int r = sqrtl(D);
            if(r*r == D && ((x&1) == (r&1))){
                int x1 = (x-r)/2, x2 = (x+r)/2;
                ans = mp[x1]*mp[x2];
            }
        }
        cout<<ans<<" ";
    }
    cout<<"\n";

}
int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int _;
    cin>>_;
    while(_-->0){
        solve();

    }
    return 0;
}