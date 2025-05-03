#include "bits/stdc++.h"
using namespace std;

#define int long long

void solve(){
    int n;
    cin>>n;
    vector<int> v(n);
    int val = 0;
    vector<int> pre1(n, 0), pre2(n, 0);
    for(int i=0;i<n;i++) {
        cin>>v[i];
    }
    
    string s;
    cin>>s;
    if(s[0] == '0') pre1[0] = v[0];
    else pre2[0] = v[0];
    for(int i=1;i<n;i++){
        if(s[i] == '0'){
            pre1[i] = v[i]^pre1[i-1];
            pre2[i] = pre2[i-1];
        }
        else{
            pre2[i] = v[i]^pre2[i-1];
            pre1[i] = pre1[i-1];
        }
    }

    int one = pre2[n-1], zero = pre1[n-1];
    
    int q;
    cin>>q;
    while(q--){
        int ff;
        cin>>ff;
        if(ff == 1){
            int l, r;
            cin>>l>>r;
            l--, r--;

            int t1 = pre1[r] ^ (l == 0 ? 0 : pre1[l-1]); //  zero  to one
            int t2 = pre2[r] ^ (l == 0 ? 0 : pre2[l-1]); // one to zero

            zero = zero^(t1^t2);
            one = one^(t1^t2);
            
        }
        else{
            int g;
            cin>>g;
            if(g == 0) cout<<zero<<" ";
            else cout<<one<<" ";
        }
    }

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