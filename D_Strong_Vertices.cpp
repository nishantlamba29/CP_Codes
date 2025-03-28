#include <bits/stdc++.h>
using namespace std;

#define int long long

int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int _;
    cin>>_;
    while(_-->0){
        int n;
        cin>>n;
        vector<int> v(n);
        int maxi = -1E17;
        for(int i=0;i<n;i++) cin>>v[i];
        for(int i=0;i<n;i++) {
            int x;
            cin>>x;
            v[i] -= x;
            maxi = max(maxi, v[i]);
        }
        vector<int> ans;
        for(int i=0;i<n;i++) if(v[i] == maxi) ans.push_back(i+1);
        
        cout<<ans.size()<<"\n";
        for(auto &i : ans) cout<<i<<" ";
        cout<<"\n";

    }
    return 0;
}