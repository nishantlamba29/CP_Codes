#include "bits/stdc++.h"
using namespace std;
#define int long long

inline void n_lamba_29(){
    int n;
    cin>>n;
    vector<int>v(n), temp(n);
    for(int i=0;i<n;i++) {
        cin>>v[i];
    }
    temp[0] = -1;
    for(int i=1;i<n;i++){
        if(v[i] == v[i-1]){
            temp[i] = temp[i-1];
        }
        else temp[i] = i-1;
    }
    int q;
    cin>>q;
    while(q--){
        int l,r;
        cin>>l>>r;
        if(temp[r-1] >= l-1) cout<<temp[r-1]+1<<" "<<r<<"\n";
        else cout<<"-1 -1\n";
    }
    cout<<"\n";
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